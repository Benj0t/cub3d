/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 15:48:12 by bemoreau          #+#    #+#             */
/*   Updated: 2020/10/06 18:37:05 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_tex_prop(t_ray *ray, t_pmlx *pmlx, t_draw *draw)
{
	draw->start = -draw->lineheight / 2 + pmlx->s.r.y / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = draw->lineheight / 2 + pmlx->s.r.y / 2;
	if (draw->end >= pmlx->s.r.y)
		draw->end = pmlx->s.r.y - 1;
	if (ray->side == 0)
		pmlx->tex.wallx = pmlx->pl.posy + ray->perpwalldist * ray->raydiry;
	else
	{
		pmlx->tex.wallx = pmlx->pl.posx + ray->perpwalldist * ray->raydirx;
	}
	pmlx->tex.wallx -= floor((pmlx->tex.wallx));
	pmlx->tex.texx = (int)(pmlx->tex.wallx * (double)TEXWIDTH);
	pmlx->tex.texpos = (draw->start - pmlx->s.r.y / 2 +\
	draw->lineheight / 2) * pmlx->tex.step;
	if (ray->side == 0 && ray->raydirx > 0)
		pmlx->tex.texx = TEXWIDTH - pmlx->tex.texx - 1;
	if (ray->side == 1 && ray->raydiry < 0)
		pmlx->tex.texx = TEXWIDTH - pmlx->tex.texx - 1;
	pmlx->tex.step = (1.0 * TEXHEIGHT) / draw->lineheight;
	pmlx->tex.texpos = (draw->start - pmlx->s.r.y / 2 +\
	draw->lineheight / 2) * pmlx->tex.step;
}

void	main_loop(t_pmlx *pmlx)
{
	int		x;
	t_ray	ray;
	t_draw	draw;
	double	zbuffer[pmlx->s.r.x];

	x = -1;
	while (++x < pmlx->s.r.x)
	{
		init_loop(&ray, pmlx, x);
		if (ray.side == 0)
			ray.perpwalldist = (pmlx->pl.mapx - pmlx->pl.posx +\
			(1 - pmlx->pl.stepx) / 2) / ray.raydirx;
		else
		{
			ray.perpwalldist = (pmlx->pl.mapy - pmlx->pl.posy +\
			(1 - pmlx->pl.stepy) / 2) / ray.raydiry;
		}
		draw.lineheight = (int)(pmlx->s.r.y / ray.perpwalldist);
		set_tex_prop(&ray, pmlx, &draw);
		draw_ray(pmlx, x, draw);
		zbuffer[x] = ray.perpwalldist;
	}
	ft_sprites(pmlx, zbuffer);
}

void	init_image(t_pmlx *pmlx)
{
	if (pmlx->mlx.img_ptr)
		mlx_destroy_image(pmlx->mlx.mlx_ptr, pmlx->mlx.img_ptr);
	pmlx->mlx.img_ptr = mlx_new_image(pmlx->mlx.mlx_ptr,\
	pmlx->s.r.x, pmlx->s.r.y);
	pmlx->mlx.data_addr = mlx_get_data_addr(pmlx->mlx.img_ptr,\
	&(pmlx->mlx.bpp), &(pmlx->mlx.size_l), &(pmlx->mlx.endian));
}

int		loop(t_pmlx *pmlx)
{
	init_image(pmlx);
	if (pmlx->b.bool_w == 1)
		forward(pmlx);
	if (pmlx->b.bool_s == 1)
		downward(pmlx);
	if (pmlx->b.bool_a == 1)
		mv_left(pmlx);
	if (pmlx->b.bool_d == 1)
		mv_right(pmlx);
	if (pmlx->b.bool_l == 1)
		rot_left(pmlx);
	if (pmlx->b.bool_r == 1)
		rot_right(pmlx);
	main_loop(pmlx);
	(pmlx->screenshot == 0) ? mlx_put_image_to_window(pmlx->mlx.mlx_ptr,\
		pmlx->mlx.win_ptr, pmlx->mlx.img_ptr, 0, 0) : 0;
	return (0);
}

int		raycast(t_pmlx *pmlx)
{
	(pmlx->screenshot == 1) ? take_screenshot(pmlx) : init_mlx(pmlx);
	init_player(pmlx);
	init_texture(pmlx);
	if (init_sprite(pmlx) == 0)
		ray_err("Error\nSprite initialisation error", pmlx, 1);
	mlx_hook(pmlx->mlx.win_ptr, KEYPRESS, (1L << 0),\
	&deal_key_press, pmlx);
	mlx_hook(pmlx->mlx.win_ptr, KEYRELEASE, (1L << 1),\
	&deal_key_release, pmlx);
	mlx_hook(pmlx->mlx.win_ptr, 33, (1L << 17),\
	&deal_key_leave, pmlx);
	mlx_loop_hook(pmlx->mlx.mlx_ptr, &loop, pmlx);
	mlx_loop(pmlx->mlx.mlx_ptr);
	return (1);
}
