/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:51:24 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/20 01:12:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fake_mlx(t_pmlx *pmlx)
{
	pmlx->mlx.mlx_ptr = mlx_init();
	pmlx->mlx.win_ptr = NULL;
	pmlx->mlx.img_ptr = mlx_new_image(pmlx->mlx.mlx_ptr,\
	pmlx->s.r.x, pmlx->s.r.y);
	pmlx->mlx.data_addr = mlx_get_data_addr(pmlx->mlx.img_ptr,\
	&(pmlx->mlx.bpp), &(pmlx->mlx.size_l), &(pmlx->mlx.endian));
}

void	take_screenshot(t_pmlx *pmlx)
{
	fake_mlx(pmlx);
	init_player(pmlx);
	if (init_sprite(pmlx) == 0)
		ray_err("Error", pmlx, 1);
	init_texture(pmlx);
	main_loop(pmlx);
	screenshot(pmlx);
	exit(2);
}
