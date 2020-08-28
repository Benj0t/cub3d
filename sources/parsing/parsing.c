/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:15 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/28 12:01:28 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_arg(t_pmlx *pmlx)
{
	if (pmlx->s.tab[0] == NULL)
		return (0);
	if (pmlx->s.tab[0][0] == 'R')
		return (store_res(pmlx));
	else if (pmlx->s.tab[0][0] == 'N' && pmlx->s.tab[0][1] == 'O')
		return (store_no(pmlx));
	else if (pmlx->s.tab[0][0] == 'S' && pmlx->s.tab[0][1] == 'O')
		return (store_so(pmlx));
	else if (pmlx->s.tab[0][0] == 'W' && pmlx->s.tab[0][1] == 'E')
		return (store_we(pmlx));
	else if (pmlx->s.tab[0][0] == 'E' && pmlx->s.tab[0][1] == 'A')
		return (store_ea(pmlx));
	else if (pmlx->s.tab[0][0] == 'S')
		return (store_s(pmlx));
	else if (pmlx->s.tab[0][0] == 'F')
		return (store_f(pmlx));
	else if (pmlx->s.tab[0][0] == 'C')
		return (store_c(pmlx));
	else
	{
		return (1);
	}
}

void	add_line2(t_pmlx *pmlx)
{
	if (ft_strlen(pmlx->s.line) > 1)
	{
		if (!(pmlx->s.tmp = ft_strjoin(pmlx->s.map_join, pmlx->s.line,\
			(ft_strlen(pmlx->s.map_join) + ft_strlen(pmlx->s.line)))))
			ft_puterr("Malloc failed (strjoin)", pmlx);
		free(pmlx->s.map_join);
		if (!(pmlx->s.map_join = ft_strdup(pmlx->s.tmp)))
			ft_puterr("Malloc failed (strdup)", pmlx);
		free(pmlx->s.tmp);
		pmlx->s.tmp = NULL;
	}
}

void	add_line(t_pmlx *pmlx)
{
	if (!(pmlx->s.map_join = ft_strdup_n(pmlx->s.line)))
		ft_puterr("Malloc failed (strdup)", pmlx);
	free(pmlx->s.line);
	while ((get_next_line(pmlx->s.fd, &(pmlx->s.line))) > 0)
		if (ft_strlen(pmlx->s.line) > 0)
		{
			if (!(pmlx->s.tmp = ft_strjoin_n(pmlx->s.map_join, pmlx->s.line,\
				(ft_strlen(pmlx->s.map_join) + ft_strlen(pmlx->s.line)))))
				ft_puterr("Malloc failed (strjoin)", pmlx);
			free(pmlx->s.map_join);
			if (!(pmlx->s.map_join = ft_strdup(pmlx->s.tmp)))
				ft_puterr("Malloc failed (strdup)", pmlx);
			free(pmlx->s.tmp);
			free(pmlx->s.line);
			pmlx->s.tmp = NULL;
			pmlx->s.line = NULL;
		}
	add_line2(pmlx);
}

int		ft_parse(t_pmlx *pmlx, char *filename)
{
	if ((pmlx->s.fd = open(filename, O_RDONLY)) <= 0 ||\
		(ext_check(filename, ".cub") != 0))
		ft_puterr("Wrong file", pmlx);
	pmlx->s.tmp = NULL;
	while ((get_next_line(pmlx->s.fd, &(pmlx->s.line))) > 0)
	{
		if ((pmlx->s.tab = ft_split(pmlx->s.line, pmlx)) == NULL)
			free(pmlx->s.line);
		else
		{
			if (pmlx->s.tab[0][0] == '1')
				add_line(pmlx);
			else
			{
				if (!get_arg(pmlx))
					ft_puterr("Error in your .cub arguments", pmlx);
			}
			free_tab(pmlx->s.tab);
			free(pmlx->s.line);
		}
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_pmlx pmlx;

	set_null(&pmlx);
	if (argc >= 2 && argc <= 3)
	{
		if (!(ft_parse(&pmlx, argv[1])))
			ft_puterr("Parsing error", &pmlx);
		if (!(create_map(&pmlx)) || (!convert_map(&pmlx)))
			ft_puterr("Map creation error", &pmlx);
		if (!(get_pos(&pmlx)) || !(valid_map(&pmlx)) || !(check_tex(&pmlx)))
			ft_puterr("Map invalid", &pmlx);
		if (!sprites_tab(&pmlx))
			ft_puterr("Sprites creation error", &pmlx);
		if (argc == 3 && !ft_strcmp(argv[2], "--save"))
			pmlx.screenshot = 1;
		raycast(&pmlx);
	}
	else
	{
		ft_puterr("Invalid Number of Arguments\n", &pmlx);
	}
}
