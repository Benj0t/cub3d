/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:10:26 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/02 20:41:33 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_null(t_pmlx *pmlx)
{
	init_parse(pmlx);
	pmlx->sp.spriteDistance = NULL;
	pmlx->sp.spriteOrder = NULL;
	pmlx->img.addr = NULL;
	pmlx->img.image = NULL;
	pmlx->mlx.img_ptr = NULL;
	pmlx->mlx.win_ptr = NULL;
	pmlx->mlx.data_addr = NULL;
	pmlx->mlx.sizex = 1920;
	pmlx->mlx.sizey = 1080;
	//mlx_get_screen_size(pmlx->mlx.mlx_ptr, &(pmlx->mlx.sizex), &(pmlx->mlx.sizey));
}

void		init_parse(t_pmlx *pmlx)
{
	pmlx->s.n_key = 0;
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
