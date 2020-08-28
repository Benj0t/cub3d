/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:50:00 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/28 14:50:20 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sp_tab(t_pmlx *pmlx)
{
	int i;

	i = -1;
	while (++i < pmlx->s.sprite_num)
	{
		pmlx->sp.spriteOrder[i] = i;
		pmlx->sp.spriteDistance[i] = ((pmlx->pl.posX - pmlx->s.list[i].x) *\
			(pmlx->pl.posX - pmlx->s.list[i].x) + (pmlx->pl.posY -\
			pmlx->s.list[i].y) * (pmlx->pl.posY - pmlx->s.list[i].y));
	}
}

int		init_sprite(t_pmlx *pmlx)
{
	if (!(pmlx->sp.spriteOrder = (int *)malloc(sizeof(int) *\
		(pmlx->s.sprite_num))))
		return (0);
	if (!(pmlx->sp.spriteDistance = (double *)malloc(sizeof(double) *\
		(pmlx->s.sprite_num))))
		return (0);
	return (1);
}