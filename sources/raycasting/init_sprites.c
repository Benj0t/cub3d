/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:50:00 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/03 16:33:50 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sp_tab(t_pmlx *pmlx)
{
	int i;

	i = -1;
	while (++i < pmlx->s.sprite_num)
	{
		pmlx->sp.sprite_order[i] = i;
		pmlx->sp.sprite_distance[i] = ((pmlx->pl.posx - pmlx->s.list[i].x) *\
			(pmlx->pl.posx - pmlx->s.list[i].x) + (pmlx->pl.posy -\
			pmlx->s.list[i].y) * (pmlx->pl.posy - pmlx->s.list[i].y));
	}
}

int		init_sprite(t_pmlx *pmlx)
{
	if (!(pmlx->sp.sprite_order = (int *)malloc(sizeof(int) *\
		(pmlx->s.sprite_num))))
		return (0);
	if (!(pmlx->sp.sprite_distance = (double *)malloc(sizeof(double) *\
		(pmlx->s.sprite_num))))
		return (0);
	return (1);
}
