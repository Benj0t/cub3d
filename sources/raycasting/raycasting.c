/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 15:48:12 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/26 18:17:04 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_ray *ray, t_pmlx *pmlx)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			pmlx->pl.mapX += pmlx->pl.stepX;
			ray->side = 0;
			pmlx->tex.texNum = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			pmlx->pl.mapY += pmlx->pl.stepY;
			ray->side = 1;
			pmlx->tex.texNum = 1;
		}
		if (pmlx->s.map[pmlx->pl.mapX][pmlx->pl.mapY] > 0)
			ray->hit = 1;
	}
	if (pmlx->tex.texNum == 0 && pmlx->pl.posX > pmlx->pl.mapX)
		pmlx->tex.texNum = 2;
	else if (pmlx->tex.texNum && pmlx->pl.posY > pmlx->pl.mapY)
		pmlx->tex.texNum = 3;
}

void	putpix(t_pmlx *pmlx, int x, int y, t_color color)
{
	int pos;

	pos = (y * pmlx->s.R.x + x) * 4;
	pmlx->mlx.data_addr[pos + RED_COMP] = color.R;
	pmlx->mlx.data_addr[pos + GREEN_COMP] = color.G;
	pmlx->mlx.data_addr[pos + BLUE_COMP] = color.B;
}

void	draw_ray(t_pmlx *pmlx, int x, t_draw draw, t_ray ray)
{
	int		y;
	t_color	color;

	y = 0;
	while (y < pmlx->s.R.y)
	{
		if (y < draw.Start)
			putpix(pmlx, x, y, pmlx->s.ceil);
		else if (y >= draw.Start && y <= draw.End)
		{
			pmlx->tex.step = (1.0 * texHeight) / draw.lineHeight;
			pmlx->tex.texY = (int)pmlx->tex.texPos & (texHeight - 1);
			pmlx->tex.texPos += pmlx->tex.step;
			color.R = pmlx->img.image[pmlx->tex.texNum]\
			[(texHeight * pmlx->tex.texY + pmlx->tex.texX) * 4 + RED_COMP];
			color.G = pmlx->img.image[pmlx->tex.texNum]\
			[(texHeight * pmlx->tex.texY + pmlx->tex.texX) * 4 + BLUE_COMP];
			color.B = pmlx->img.image[pmlx->tex.texNum]\
			[(texHeight * pmlx->tex.texY + pmlx->tex.texX) * 4 + GREEN_COMP];
			putpix(pmlx, x, y, color);
		}
		else
			putpix(pmlx, x, y, pmlx->s.floor);
		y++;
	}
}

void	init_dda(t_ray *ray, t_pmlx *pmlx)
{
	if (ray->rayDirX < 0)
	{
		pmlx->pl.stepX = -1;
		ray->sideDistX = (pmlx->pl.posX - pmlx->pl.mapX) * ray->deltaDistX;
	}
	else
	{
		pmlx->pl.stepX = 1;
		ray->sideDistX = (pmlx->pl.mapX + 1.0 - \
		pmlx->pl.posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		pmlx->pl.stepY = -1;
		ray->sideDistY = (pmlx->pl.posY - pmlx->pl.mapY) * ray->deltaDistY;
	}
	else
	{
		pmlx->pl.stepY = 1;
		ray->sideDistY = (pmlx->pl.mapY + 1.0 - pmlx->pl.posY) *\
		ray->deltaDistY;
	}
	dda(ray, pmlx);
}

void	init_loop(t_ray *ray, t_pmlx *pmlx, int x)
{
	ray->cameraX = 2 * x / (double)pmlx->s.R.x - 1;
	ray->rayDirX = pmlx->pl.dirX + pmlx->pl.planeX * ray->cameraX;
	ray->rayDirY = pmlx->pl.dirY + pmlx->pl.planeY * ray->cameraX;
	pmlx->pl.mapX = (int)pmlx->pl.posX;
	pmlx->pl.mapY = (int)pmlx->pl.posY;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0;
	init_dda(ray, pmlx);
}

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

void	err_raycast(t_pmlx *pmlx)
{
	//FAIRE UN AUTRE BAIL
}

void	ray_err(char *str, t_pmlx *pmlx)
{
	ft_putendl(str);
	err_raycast(pmlx);
	exit(1);
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
