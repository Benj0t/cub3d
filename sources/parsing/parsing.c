/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:15 by bemoreau          #+#    #+#             */
/*   Updated: 2020/07/25 13:08:15 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putendl(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &(str[i++]), 1);
	write(1, "\n", 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &(str[i++]), 1);
}

int	 get_arg(t_pmlx *pmlx)
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
		return(1);
	}
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	add_line(t_pmlx *pmlx)
{
	if (!(pmlx->s.map_join = ft_strdup_N(pmlx->s.line)))
		ft_puterr("Malloc failed (strdup)", pmlx);
	free(pmlx->s.line);
	while ((get_next_line(pmlx->s.fd, &(pmlx->s.line))) > 0)
		if (ft_strlen(pmlx->s.line) > 0)
		{
			if (!(pmlx->s.tmp = ft_strjoin_N(pmlx->s.map_join, pmlx->s.line, (ft_strlen(pmlx->s.map_join) + ft_strlen(pmlx->s.line)))))
				ft_puterr("Malloc failed (strjoin)", pmlx);
			free(pmlx->s.map_join);
			if (!(pmlx->s.map_join = ft_strdup(pmlx->s.tmp)))
				ft_puterr("Malloc failed (strdup)", pmlx);
			free(pmlx->s.tmp);
			free(pmlx->s.line);
			pmlx->s.tmp = NULL;
			pmlx->s.line = NULL;
		}
	if (ft_strlen(pmlx->s.line) > 1)
	{
		if (!(pmlx->s.tmp = ft_strjoin(pmlx->s.map_join, pmlx->s.line, (ft_strlen(pmlx->s.map_join) + ft_strlen(pmlx->s.line)))))
			ft_puterr("Malloc failed (strjoin)", pmlx);
		free(pmlx->s.map_join);
		if (!(pmlx->s.map_join = ft_strdup(pmlx->s.tmp)))
			ft_puterr("Malloc failed (strdup)", pmlx);
		free(pmlx->s.tmp);
		pmlx->s.tmp = NULL;
	}
}

int ft_parse(t_pmlx *pmlx, char *filename)
{
	if ((pmlx->s.fd = open(filename, O_RDONLY)) <= 0)
		return (0);
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
					ft_puterr("Something went wrong with your .cub arguments", pmlx);
			} 
			free_tab(pmlx->s.tab);
			free(pmlx->s.line);
		}
	}
	return (1);
}

void	set_pos(t_pmlx *pmlx, int j, int i)
{
	pmlx->s.dir = pmlx->s.cmap[j][i];
	pmlx->s.cmap[j][i] = '0';
	pmlx->pl.posX = j + 0.5;
	pmlx->pl.posY = i + 0.5;
}

int get_pos(t_pmlx *pmlx)
{
	int i;
	int j;
	int bool;

	bool = 0;
	i = 0;
	j = 0;
	while (pmlx->s.cmap[j])
	{
		while (pmlx->s.cmap[j][i])
		{
			if (find_char("NESW", pmlx->s.cmap[j][i]))
			{
				set_pos(pmlx, j, i);
				if (++bool > 1)
				{
					return (0);
				}
				return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int get_char(char c)
{
	if (find_char("NESW", c))
		return (0);
	if (c == ' ')
		return (0);
	if (c == '0')
		return (0);
	if (c == '1')
		return (1);
	if (c == '2')
		return (0);
	return (-1);
}

int convert_map(t_pmlx *pmlx)
{
	int len;
	int i;
	int j;

	i = 0;
	pmlx->s.tabHeight = tab_len(pmlx->s.cmap);
	if (!(pmlx->s.map = (int **)malloc(sizeof(int *) * (pmlx->s.tabHeight + 1))))
		return (0);
	pmlx->s.map[pmlx->s.tabHeight] = NULL;
	while (i < pmlx->s.tabHeight)
	{
		j = -1;
		len = ft_strlen(pmlx->s.cmap[i]);
		if (!(pmlx->s.map[i] = (int *)malloc(sizeof(int) * (len + 1))))
			return (0);
		pmlx->s.map[i][len] = '\0';
		while (++j < len)
			if ((pmlx->s.map[i][j] = get_char(pmlx->s.cmap[i][j])) == -1)
				ft_puterr("Unauthorized character", pmlx);
		i++;
	}
	return (1);
}

int	sprites_tab(t_pmlx *pmlx)
{
	int i;
	int j;
	int count;

	count = 0;
	j = 0;
	i = 0;
	if (!(pmlx->s.list = (t_vec *)malloc(sizeof(t_vec) * (pmlx->s.sprite_num + 1))))
		return (0);
	while (pmlx->s.cmap[i])
	{
		while (pmlx->s.cmap[i][j])
			if (pmlx->s.cmap[i][j++] == 'S')
			{
				pmlx->s.list[count].x = i;
				pmlx->s.list[count++].y = j - 1;
			}
		j = 0;
		i++;
	}
	if (count != pmlx->s.sprite_num)
		return (0);
	return (1);
}

void	set_NULL(t_pmlx *pmlx)
{
	init_parse(pmlx);
	pmlx->sp.spriteDistance = NULL;
	pmlx->sp.spriteOrder = NULL;
	pmlx->img.addr = NULL;
	pmlx->img.image = NULL;
	pmlx->mlx.img_ptr = NULL;
	pmlx->mlx.win_ptr = NULL;
	pmlx->mlx.data_addr = NULL;
}
void	err_parsing(t_pmlx *pmlx)
{
	(pmlx->s.list) ? free(pmlx->s.list) : 0;
	(pmlx->s.NO) ? free(pmlx->s.NO) : 0;
	(pmlx->s.SO) ? free(pmlx->s.SO) : 0;
	(pmlx->s.WE) ? free(pmlx->s.WE) : 0;
	(pmlx->s.EA) ? free(pmlx->s.EA) : 0;
	(pmlx->s.S) ? free(pmlx->s.S) : 0;
	(pmlx->s.line) ? free(pmlx->s.line) : 0;
	(pmlx->s.tmp) ? free(pmlx->s.tmp) : 0;
	(pmlx->s.map_join) ? free(pmlx->s.map_join) : 0;
	(pmlx->s.cmap) ? free(pmlx->s.cmap) : 0;
	(pmlx->s.map) ? free(pmlx->s.map) : 0;
	(pmlx->s.C) ? free(pmlx->s.C) : 0;
	(pmlx->sp.spriteDistance) ? free(pmlx->sp.spriteDistance) : 0;
	(pmlx->sp.spriteOrder) ? free(pmlx->sp.spriteOrder) : 0;
	(pmlx->img.addr) ? free(pmlx->img.addr ) : 0;
	(pmlx->img.image) ? free(pmlx->img.image) : 0;
	(pmlx->mlx.img_ptr) ? free(pmlx->mlx.img_ptr) : 0;
	(pmlx->mlx.win_ptr) ? free(pmlx->mlx.win_ptr) : 0;
	(pmlx->mlx.data_addr) ? free(pmlx->mlx.data_addr) : 0;
}

void	ft_puterr(char *str, t_pmlx *pmlx)
{
	ft_putendl(str);
	err_parsing(pmlx);
	exit(1);
}

int		check_tex(t_pmlx *pmlx)
{
	if (!(pmlx->s.NO) || !(pmlx->s.EA) || !(pmlx->s.WE) || !(pmlx->s.SO))
		return (0);
	return (1);
}

// Si y a un espace dans la map
// REsolution a reparer.

int		main(int argc, char **argv)
{
	t_pmlx pmlx;

	set_NULL(&pmlx);
	if (argc >= 2 && argc <= 3)
	{
		if (!(ft_parse(&pmlx, argv[1])))
			ft_puterr("Parsing error\n", &pmlx);
		if (!(create_map(&pmlx)) || (!convert_map(&pmlx)))
			ft_puterr("Map creation error\n", &pmlx);
		if (!(get_pos(&pmlx)) ||  !(valid_map(&pmlx)) || !(check_tex(&pmlx)))
			ft_puterr("Map invalid\n", &pmlx);
		if (!sprites_tab(&pmlx))
			ft_puterr("Sprites creation error\n", &pmlx);
		if (argc == 3 && !ft_strcmp(argv[2], "--save"))
			pmlx.screenshot = 1;
		raycast(&pmlx);
	}
	else
	{
		ft_puterr("Invalid Number of Arguments\n", &pmlx);
	}
}