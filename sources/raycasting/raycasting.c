/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 15:48:12 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/28 13:23:19 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_tex_prop(t_ray *ray, t_pmlx *pmlx, t_draw *draw)
{
	draw->Start = -draw->lineHeight / 2 + pmlx->s.R.y / 2;
	if (draw->Start < 0)
		draw->Start = 0;
	draw->End = draw->lineHeight / 2 + pmlx->s.R.y / 2;
	if (draw->End >= pmlx->s.R.y)
		draw->End = pmlx->s.R.y - 1;
	if (ray->side == 0)
		pmlx->tex.wallX = pmlx->pl.posY + ray->perpWallDist * ray->rayDirY;
	else
	{
		pmlx->tex.wallX = pmlx->pl.posX + ray->perpWallDist * ray->rayDirX;
	}
	pmlx->tex.wallX -= floor((pmlx->tex.wallX));
	pmlx->tex.texX = (int)(pmlx->tex.wallX * (double)texWidth);
	pmlx->tex.texPos = (draw->Start - pmlx->s.R.y / 2 +\
	draw->lineHeight / 2) * pmlx->tex.step;
	if (ray->side == 0 && ray->rayDirX > 0)
		pmlx->tex.texX = texWidth - pmlx->tex.texX - 1;
	if (ray->side == 1 && ray->rayDirY < 0)
		pmlx->tex.texX = texWidth - pmlx->tex.texX - 1;
	pmlx->tex.step = (1.0 * texHeight) / draw->lineHeight;
	pmlx->tex.texPos = (draw->Start - pmlx->s.R.y / 2 +\
	draw->lineHeight / 2) * pmlx->tex.step;
}

void	main_loop(t_pmlx *pmlx)
{
	int		x;
	t_ray	ray;
	t_draw	draw;
	double	zbuffer[pmlx->s.R.x];

	x = -1;
	while (++x < pmlx->s.R.x)
	{
		init_loop(&ray, pmlx, x);
		if (ray.side == 0)
			ray.perpWallDist = (pmlx->pl.mapX - pmlx->pl.posX +\
			(1 - pmlx->pl.stepX) / 2) / ray.rayDirX;
		else
		{
			ray.perpWallDist = (pmlx->pl.mapY - pmlx->pl.posY +\
			(1 - pmlx->pl.stepY) / 2) / ray.rayDirY;
		}
		draw.lineHeight = (int)(pmlx->s.R.y / ray.perpWallDist);
		set_tex_prop(&ray, pmlx, &draw);
		draw_ray(pmlx, x, draw, ray);
		zbuffer[x] = ray.perpWallDist;
	}
	ft_sprites(pmlx, zbuffer);
	mlx_put_image_to_window(pmlx->mlx.mlx_ptr, pmlx->mlx.win_ptr,\
	pmlx->mlx.img_ptr, 0, 0);
}

int		loop(t_pmlx *pmlx)
{
	if (pmlx->bool_W == 1)
		forward(pmlx);
	if (pmlx->bool_S == 1)
		downward(pmlx);
	if (pmlx->bool_A == 1)
		mv_left(pmlx);
	if (pmlx->bool_D == 1)
		mv_right(pmlx);
	main_loop(pmlx);
	return (0);
}

int		raycast(t_pmlx *pmlx)
{
	init_player(pmlx);
	init_mlx(pmlx);
	if (init_sprite(pmlx) == 0)
		ray_err("Sprites initialisation failed", pmlx);
	init_texture(pmlx);
	mlx_hook(pmlx->mlx.win_ptr, KEYPRESS, KEYPRESSMASK,\
	&deal_key_press, pmlx);
	mlx_hook(pmlx->mlx.win_ptr, KEYRELEASE, KEYRELEASEMASK,\
	&deal_key_release, pmlx);
	mlx_hook(pmlx->mlx.win_ptr, DESTROYNOTIFY, LEAVEWINDOWMASK,\
	&deal_key_leave, pmlx);
	mlx_loop_hook(pmlx->mlx.mlx_ptr, &loop, pmlx);
	mlx_loop(pmlx->mlx.mlx_ptr);
	return (1);
}
