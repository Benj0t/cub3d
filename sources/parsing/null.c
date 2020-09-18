/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:10:26 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/18 12:36:17 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_null(t_pmlx *pmlx)
{
	init_parse(pmlx);
	pmlx->screenshot = 0;
	pmlx->sp.sprite_distance = NULL;
	pmlx->sp.sprite_order = NULL;
	pmlx->img.addr = NULL;
	pmlx->img.image = NULL;
	pmlx->mlx.img_ptr = NULL;
	pmlx->mlx.win_ptr = NULL;
	pmlx->mlx.data_addr = NULL;
}

void		init_parse(t_pmlx *pmlx)
{
	pmlx->s.n_key = 0;
	pmlx->s.sprite_num = 0;
	pmlx->s.list = NULL;
	pmlx->s.no = NULL;
	pmlx->s.so = NULL;
	pmlx->s.we = NULL;
	pmlx->s.ea = NULL;
	pmlx->s.s = NULL;
	pmlx->s.line = NULL;
	pmlx->s.tmp = NULL;
	pmlx->s.map_join = NULL;
	pmlx->s.cmap = NULL;
	pmlx->s.map = NULL;
	pmlx->s.c = NULL;
}
