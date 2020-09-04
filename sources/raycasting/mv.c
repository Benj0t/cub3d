/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:47:07 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/04 12:13:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mv_right(t_pmlx *pmlx)
{
	if (pmlx->s.map[(int)(pmlx->pl.posx +\
		pmlx->pl.planex * pmlx->pl.movespeed)]\
		[(int)pmlx->pl.posy] == 0)
		pmlx->pl.posx += pmlx->pl.planex * pmlx->pl.movespeed;
	if (pmlx->s.map[(int)pmlx->pl.posx]\
		[(int)(pmlx->pl.posy + pmlx->pl.planey * pmlx->pl.movespeed)] == 0)
		pmlx->pl.posy += pmlx->pl.planey * pmlx->pl.movespeed;
}

void	mv_left(t_pmlx *pmlx)
{
	if (pmlx->s.map[(int)(pmlx->pl.posx -\
		pmlx->pl.planex * pmlx->pl.movespeed)]\
		[(int)pmlx->pl.posy] == 0)
		pmlx->pl.posx -= pmlx->pl.planex * pmlx->pl.movespeed;
	if (pmlx->s.map[(int)pmlx->pl.posx]\
		[(int)(pmlx->pl.posy - pmlx->pl.planey * pmlx->pl.movespeed)] == 0)
		pmlx->pl.posy -= pmlx->pl.planey * pmlx->pl.movespeed;
}
