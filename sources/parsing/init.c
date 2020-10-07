/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:42 by bemoreau          #+#    #+#             */
/*   Updated: 2020/10/07 17:59:02 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_mlx(t_pmlx *pmlx)
{
	int x;
	int y;

	pmlx->img.bpp = 0;
	pmlx->img.s_line = 0;
	pmlx->img.endian = 0;
	pmlx->mlx.mlx_ptr = mlx_init();
	// mlx_get_screen_size(pmlx->mlx.mlx_ptr, &(x), &(y));
	x = 1920;
	y = 1080;
	pmlx->s.r.x = (x < pmlx->s.r.x) ? x : pmlx->s.r.x;
	pmlx->s.r.y = (y < pmlx->s.r.y) ? y : pmlx->s.r.y;
	pmlx->mlx.win_ptr = mlx_new_window(pmlx->mlx.mlx_ptr, pmlx->s.r.x,\
	pmlx->s.r.y, "Cub3D");
	pmlx->mlx.img_ptr = NULL;
	pmlx->mlx.data_addr = NULL;
}

static void	init_dir2(t_pmlx *pmlx)
{
	if (pmlx->s.id == 'W')
	{
		pmlx->pl.dirx = 0;
		pmlx->pl.diry = -1;
		pmlx->pl.planex = -0.66;
		pmlx->pl.planey = 0;
	}
	if (pmlx->s.id == 'E')
	{
		pmlx->pl.dirx = 0;
		pmlx->pl.diry = 1;
		pmlx->pl.planex = 0.66;
		pmlx->pl.planey = 0;
	}
}

static void	init_dir(t_pmlx *pmlx)
{
	if (pmlx->s.id == 'N')
	{
		pmlx->pl.dirx = -1;
		pmlx->pl.diry = 0;
		pmlx->pl.planex = 0;
		pmlx->pl.planey = 0.66;
	}
	if (pmlx->s.id == 'S')
	{
		pmlx->pl.dirx = 1;
		pmlx->pl.diry = 0;
		pmlx->pl.planex = 0;
		pmlx->pl.planey = -0.66;
	}
	init_dir2(pmlx);
}

void		init_player(t_pmlx *pmlx)
{
	pmlx->pl.movespeed = 0.09;
	pmlx->pl.rotspeed = 0.05;
	init_dir(pmlx);
}

t_w_check	init_w_check(void)
{
	t_w_check w;

	w.s = 0;
	w.n = 0;
	w.o = 0;
	w.e = 0;
	return (w);
}
