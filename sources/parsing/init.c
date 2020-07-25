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

void        init_mlx(t_pmlx *pmlx)
{
    pmlx->mlx.mlx_ptr = mlx_init();
	pmlx->mlx.win_ptr = mlx_new_window(pmlx->mlx.mlx_ptr, pmlx->s.R.x, pmlx->s.R.y, "Cub3D");
	pmlx->mlx.img_ptr = mlx_new_image(pmlx->mlx.mlx_ptr, pmlx->s.R.x, pmlx->s.R.y);
	pmlx->mlx.data_addr = mlx_get_data_addr(pmlx->mlx.img_ptr, &(pmlx->mlx.bpp), &(pmlx->mlx.size_l), &(pmlx->mlx.endian));
}

void        init_player(t_pmlx *pmlx)
{
	pmlx->bool_ESC = 0;
    /*
    N : x -1 y 0 P : y 0.66 x 0
S : x 1 y 0 P : y -0.66 x 0
E : x 0 y 1 P : y 0 x 0.66
W : x 0 y -1 P : y 0 x -0.66
    */
	pmlx->pl.dirX = 0;
	pmlx->pl.dirY = -1; //initial direction vector
	pmlx->pl.planeX = -0.66;
    pmlx->pl.planeY = 0;
	//the 2d raycaster version of camera plane
	pmlx->pl.moveSpeed = 0.075;
	pmlx->pl.rotSpeed = 0.05;
}

t_parse     init_parse()
{
    t_parse s;

    s.NO = NULL;
    s.SO = NULL;
    s.WE = NULL;
    s.EA = NULL;
    s.S = NULL;
    return (s);
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