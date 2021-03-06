/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:47:47 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/20 16:06:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		sprites_tab(t_pmlx *pmlx)
{
	int i;
	int j;
	int count;

	count = 0;
	j = 0;
	i = -1;
	if (!(pmlx->s.list = (t_svec *)malloc(sizeof(t_svec) * (\
		pmlx->s.sprite_num + 1))))
		ft_puterr("Error\n(malloc)", pmlx, 1);
	while (pmlx->s.cmap[++i])
	{
		while (pmlx->s.cmap[i][j])
			if (pmlx->s.cmap[i][j++] == 'S')
			{
				pmlx->s.list[count].x = i + 0.5;
				pmlx->s.list[count++].y = j - 0.5;
			}
		j = 0;
	}
	spr_fix(pmlx, count);
	if (count != pmlx->s.sprite_num)
		return (0);
	return (1);
}
