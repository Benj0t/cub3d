/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:42 by bemoreau          #+#    #+#             */
/*   Updated: 2020/07/25 13:08:42 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        init_parse(t_pmlx *pmlx)
{
    pmlx->s.sprite_num = 0;
    pmlx->s.list = NULL;
   	pmlx->s.NO = NULL;
    pmlx->s.SO = NULL;
    pmlx->s.WE = NULL;
    pmlx->s.EA = NULL;
    pmlx->s.S = NULL;
    pmlx->s.line = NULL;
    pmlx->s.tmp = NULL;
    pmlx->s.map_join = NULL;
    pmlx->s.cmap = NULL;
    pmlx->s.map = NULL;
    pmlx->s.C = NULL;
}

void        init_mlx(t_pmlx *pmlx)
{
    pmlx->mlx.mlx_ptr = mlx_init();
	pmlx->mlx.win_ptr = mlx_new_window(pmlx->mlx.mlx_ptr, pmlx->s.R.x, pmlx->s.R.y, "Cub3D");
    pmlx->mlx.img_ptr = mlx_new_image(pmlx->mlx.mlx_ptr, pmlx->s.R.x, pmlx->s.R.y);
    pmlx->mlx.data_addr = mlx_get_data_addr(pmlx->mlx.img_ptr, &(pmlx->mlx.bpp), &(pmlx->mlx.size_l), &(pmlx->mlx.endian));
}

int         init_sprite(t_pmlx *pmlx)
{
    if (!(pmlx->sp.spriteOrder = (int *)malloc(sizeof(int) * (pmlx->s.sprite_num))))
        return (0);
    if (!(pmlx->sp.spriteDistance = (double *)malloc(sizeof(double) * (pmlx->s.sprite_num))))
        return (0);
    return (1);
}

void        init_player(t_pmlx *pmlx)
{
	pmlx->bool_ESC = 0;
	pmlx->pl.dirX = 0;
	pmlx->pl.dirY = -1; //initial direction vector
	pmlx->pl.planeX = -0.66;
    pmlx->pl.planeY = 0;
	//the 2d raycaster version of camera plane
	pmlx->pl.moveSpeed = 0.075;
	pmlx->pl.rotSpeed = 0.05;
}

t_w_check   init_w_check()
{
    t_w_check w;
    w.s = 0;
    w.n = 0;
    w.o = 0;
    w.e = 0;
    return (w);
}