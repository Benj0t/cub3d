/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 15:48:12 by bemoreau          #+#    #+#             */
/*   Updated: 2020/10/11 14:59:57 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fake_mlx(t_pmlx *pmlx)
{
	int x;
	int y;

	pmlx->mlx.mlx_ptr = mlx_init();
	mlx_get_screen_size(pmlx->mlx.mlx_ptr, &(x), &(y));
	pmlx->s.r.x = (x < pmlx->s.r.x) ? x : pmlx->s.r.x;
	pmlx->s.r.y = (y < pmlx->s.r.y) ? y : pmlx->s.r.y;
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
		ray_err("Error\nSprite initialisation error", pmlx, 1);
	init_texture(pmlx);
	main_loop(pmlx);
	screenshot(pmlx);
	exit(2);
}
