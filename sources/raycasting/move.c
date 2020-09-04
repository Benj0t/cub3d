/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:59:01 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/04 12:17:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	forward(t_pmlx *pmlx)
{
	if (pmlx->s.map[(int)(pmlx->pl.posx + pmlx->pl.dirx * pmlx->pl.movespeed)]\
		[(int)pmlx->pl.posy] == 0)
		pmlx->pl.posx += pmlx->pl.dirx * pmlx->pl.movespeed;
	if (pmlx->s.map[(int)pmlx->pl.posx]\
		[(int)(pmlx->pl.posy + pmlx->pl.diry * pmlx->pl.movespeed)] == 0)
		pmlx->pl.posy += pmlx->pl.diry * pmlx->pl.movespeed;
}

void	downward(t_pmlx *pmlx)
{
	if (pmlx->s.map[(int)(pmlx->pl.posx - pmlx->pl.dirx * pmlx->pl.movespeed)]\
		[(int)pmlx->pl.posy] == 0)
		pmlx->pl.posx -= pmlx->pl.dirx * pmlx->pl.movespeed;
	if (pmlx->s.map[(int)pmlx->pl.posx]\
		[(int)(pmlx->pl.posy - pmlx->pl.diry * pmlx->pl.movespeed)] == 0)
		pmlx->pl.posy -= pmlx->pl.diry * pmlx->pl.movespeed;
}

void	rot_left(t_pmlx *pmlx)
{
	pmlx->pl.olddirx = pmlx->pl.dirx;
	pmlx->pl.dirx = pmlx->pl.dirx * cos(pmlx->pl.rotspeed) -\
					pmlx->pl.diry * sin(pmlx->pl.rotspeed);
	pmlx->pl.diry = pmlx->pl.olddirx * sin(pmlx->pl.rotspeed) +\
					pmlx->pl.diry * cos(pmlx->pl.rotspeed);
	pmlx->pl.oldplanex = pmlx->pl.planex;
	pmlx->pl.planex = pmlx->pl.planex * cos(pmlx->pl.rotspeed) -\
					pmlx->pl.planey * sin(pmlx->pl.rotspeed);
	pmlx->pl.planey = pmlx->pl.oldplanex * sin(pmlx->pl.rotspeed) +\
					pmlx->pl.planey * cos(pmlx->pl.rotspeed);
}

void	rot_right(t_pmlx *pmlx)
{
	pmlx->pl.olddirx = pmlx->pl.dirx;
	pmlx->pl.dirx = pmlx->pl.dirx * cos(-pmlx->pl.rotspeed) -\
					pmlx->pl.diry * sin(-pmlx->pl.rotspeed);
	pmlx->pl.diry = pmlx->pl.olddirx * sin(-pmlx->pl.rotspeed) +\
					pmlx->pl.diry * cos(-pmlx->pl.rotspeed);
	pmlx->pl.oldplanex = pmlx->pl.planex;
	pmlx->pl.planex = pmlx->pl.planex * cos(-pmlx->pl.rotspeed) -\
					pmlx->pl.planey * sin(-pmlx->pl.rotspeed);
	pmlx->pl.planey = pmlx->pl.oldplanex * sin(-pmlx->pl.rotspeed) +\
					pmlx->pl.planey * cos(-pmlx->pl.rotspeed);
}
