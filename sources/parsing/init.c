/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:42 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/02 20:39:08 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_mlx(t_pmlx *pmlx)
{
	pmlx->img.bpp = 0;
	pmlx->img.s_line = 0;
	pmlx->img.endian = 0;
	pmlx->mlx.mlx_ptr = mlx_init();
	pmlx->mlx.win_ptr = mlx_new_window(pmlx->mlx.mlx_ptr, pmlx->s.R.x,\
	pmlx->s.R.y, "Cub3D");
	pmlx->mlx.img_ptr = mlx_new_image(pmlx->mlx.mlx_ptr,\
	pmlx->s.R.x, pmlx->s.R.y);
	pmlx->mlx.data_addr = mlx_get_data_addr(pmlx->mlx.img_ptr,\
	&(pmlx->mlx.bpp), &(pmlx->mlx.size_l), &(pmlx->mlx.endian));
}

static void	init_dir2(t_pmlx *pmlx)
{
	if (pmlx->s.id == 'W')
	{
		pmlx->pl.dirX = 0;
		pmlx->pl.dirY = -1;
		pmlx->pl.planeX = -0.66;
		pmlx->pl.planeY = 0;
	}
	if (pmlx->s.id == 'E')
	{
		pmlx->pl.dirX = 0;
		pmlx->pl.dirY = 1;
		pmlx->pl.planeX = 0.66;
		pmlx->pl.planeY = 0;
	}
}

static void	init_dir(t_pmlx *pmlx)
{
	if (pmlx->s.id == 'N')
	{
		pmlx->pl.dirX = -1;
		pmlx->pl.dirY = 0;
		pmlx->pl.planeX = 0;
		pmlx->pl.planeY = 0.66;
	}
	if (pmlx->s.id == 'S')
	{
		pmlx->pl.dirX = 1;
		pmlx->pl.dirY = 0;
		pmlx->pl.planeX = 0;
		pmlx->pl.planeY = -0.66;
	}
	init_dir2(pmlx);
}

void		init_player(t_pmlx *pmlx)
{
	pmlx->pl.moveSpeed = 0.09;
	pmlx->pl.rotSpeed = 0.05;
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
