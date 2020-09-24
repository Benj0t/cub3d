/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:55:31 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/20 16:11:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ext_check(char *str, char *ext)
{
	return (ft_strcmp(str + (ft_strlen(str) - ft_strlen(ext)), ext));
}

int		check_tex(t_pmlx *pmlx)
{
	if (!(pmlx->s.no) || !(pmlx->s.ea) || !(pmlx->s.we) || !(pmlx->s.so))
		ft_puterr("Error\nMissing texture", pmlx, 1);
	return (1);
}

void	set_pos(t_pmlx *pmlx, int j, int i)
{
	pmlx->s.id = pmlx->s.cmap[j][i];
	pmlx->s.cmap[j][i] = '0';
	pmlx->pl.posx = j + 0.5;
	pmlx->pl.posy = i + 0.5;
}

int		get_pos(t_pmlx *pmlx)
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
					return (0);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return ((bool) ? 1 : 0);
}

int		get_char(char c)
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
		return (2);
	return (-1);
}
