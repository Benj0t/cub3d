/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untextured.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:25:37 by bemoreau          #+#    #+#             */
/*   Updated: 2020/06/25 19:46:26 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	worldMap[mapWidth][mapHeight]={
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

//place the example code below here:
void	dda(t_ray *ray, t_pmlx *pmlx)
{
	while (ray->hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if(ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			pmlx->pl.mapX += pmlx->pl.stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			pmlx->pl.mapY += pmlx->pl.stepY;
			ray->side = 1;
		}
		//Check if ray has ray.hit a wall
		if(worldMap[pmlx->pl.mapX][pmlx->pl.mapY] > 0)
			ray->hit = 1;
	}
}

t_color	ft_choose_color(t_pmlx pmlx)
{
	t_color color;

	if (worldMap[pmlx.pl.mapX][pmlx.pl.mapY] == 1)
		color = ft_red();
	else if (worldMap[pmlx.pl.mapX][pmlx.pl.mapY] == 2)
		color = ft_blue(); //green
	else if (worldMap[pmlx.pl.mapX][pmlx.pl.mapY] == 3)
		color = ft_green(); //blue
	else if (worldMap[pmlx.pl.mapX][pmlx.pl.mapY] == 4)
		color = ft_yellow(); //white
	else
	{
		color = ft_white(); //yellow
	}
	return (color);
}

void	putpix(char *data_addr, int x, int y, t_color color)
{
	int pos;

	pos = (y * screenWidth + x) * 4;
	data_addr[pos + RED_COMP] = color.R;
	data_addr[pos + GREEN_COMP] = color.G;
	data_addr[pos + BLUE_COMP] = color.B;
}

void	draw_ray(char *data_addr, int x, t_draw draw, t_color color, t_pmlx *pmlx, t_ray ray)
{
	int y;

	y = 0;

	while (y < screenHeight)
	{
		if (y < draw.Start)
			putpix(data_addr, x, y, ft_light_blue());
		else if (y >= draw.Start && y <= draw.End)
		{
			pmlx->tex.step = (1.0 * texHeight) / draw.lineHeight;
			//pmlx->tex.texPos = (draw.Start - screenHeight / 2 + draw.lineHeight / 2) * pmlx->tex.step;
			pmlx->tex.texY = (int)pmlx->tex.texPos & (texHeight - 1);
			pmlx->tex.texPos += pmlx->tex.step;
			color.R = pmlx->img.image[pmlx->tex.texNum][(texHeight * pmlx->tex.texY + pmlx->tex.texX) * 4 + RED_COMP];
			color.G = pmlx->img.image[pmlx->tex.texNum][(texHeight * pmlx->tex.texY + pmlx->tex.texX) * 4 + BLUE_COMP];
			color.B = pmlx->img.image[pmlx->tex.texNum][(texHeight * pmlx->tex.texY + pmlx->tex.texX) * 4 + GREEN_COMP];			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			//pmlx->tex.texY += (int)pmlx->tex.texPos;
			if(ray.side == 1)
				color = ft_color_divide(color);
			putpix(data_addr, x, y, color);
		}
		else
		{
			putpix(data_addr, x, y, ft_gray());
		}
		y++;
	}
}
void	main_loop(t_pmlx *pmlx)
{
	t_ray ray;
	t_color color;
	t_draw draw;

	for(int x = 0; x < screenWidth; x++)
	{
		//calculate ray position and direction
		ray.cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
		ray.rayDirX = pmlx->pl.dirX + pmlx->pl.planeX * ray.cameraX;
		ray.rayDirY = pmlx->pl.dirY + pmlx->pl.planeY * ray.cameraX;
		//which box of the map we're in
		pmlx->pl.mapX = (int)pmlx->pl.posX;
		pmlx->pl.mapY = (int)pmlx->pl.posY;
		//length of ray from one x or y-side to next x or y-side
		ray.deltaDistX = fabs(1 / ray.rayDirX);
		ray.deltaDistY = fabs(1 / ray.rayDirY);
		ray.hit = 0;
		//calculate step and initial sideDist
		if(ray.rayDirX < 0)
		{
			pmlx->pl.stepX = -1;
			ray.sideDistX = (pmlx->pl.posX - pmlx->pl.mapX) * ray.deltaDistX;
		}
		else
		{
			pmlx->pl.stepX = 1;
			ray.sideDistX = (pmlx->pl.mapX + 1.0 - pmlx->pl.posX) * ray.deltaDistX;
		}
		if(ray.rayDirY < 0)
		{
			pmlx->pl.stepY = -1;
			ray.sideDistY = (pmlx->pl.posY - pmlx->pl.mapY) * ray.deltaDistY;
		}
		else
		{
			pmlx->pl.stepY = 1;
			ray.sideDistY = (pmlx->pl.mapY + 1.0 - pmlx->pl.posY) * ray.deltaDistY;
		}
		//perform DDA
		dda(&ray, pmlx);
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(ray.side == 0) 
			ray.perpWallDist = (pmlx->pl.mapX - pmlx->pl.posX + (1 - pmlx->pl.stepX) / 2) / ray.rayDirX;
		else
		{
			ray.perpWallDist = (pmlx->pl.mapY - pmlx->pl.posY + (1 - pmlx->pl.stepY) / 2) / ray.rayDirY;
		}
		//Calculate height of line to draw on screen
		draw.lineHeight = (int)(screenHeight / ray.perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		draw.Start = -draw.lineHeight / 2 + screenHeight / 2;

		if(draw.Start < 0)
			draw.Start = 0;
		draw.End = draw.lineHeight / 2 + screenHeight / 2;
		if(draw.End >= screenHeight)
			draw.End = screenHeight - 1;
		color = ft_choose_color(*pmlx);
		if(ray.side == 1)
			color = ft_color_divide(color);
		pmlx->tex.texNum = worldMap[pmlx->pl.mapX][pmlx->pl.mapY] - 1;
	    if(ray.side == 0)
			pmlx->tex.wallX = pmlx->pl.posY + ray.perpWallDist * ray.rayDirY;
		else
		{
			pmlx->tex.wallX = pmlx->pl.posX + ray.perpWallDist * ray.rayDirX;
		}
		pmlx->tex.wallX -= floor((pmlx->tex.wallX));

		pmlx->tex.texX = (int)(pmlx->tex.wallX * (double)texWidth);
		pmlx->tex.texPos = (draw.Start - screenHeight / 2 + draw.lineHeight / 2) * pmlx->tex.step;
		if(ray.side == 0 && ray.rayDirX > 0)
			pmlx->tex.texX = texWidth - pmlx->tex.texX - 1;
		if(ray.side == 1 && ray.rayDirY < 0)
			pmlx->tex.texX = texWidth - pmlx->tex.texX - 1;
		//draw the pixels of the stripe as a vertical line
		pmlx->tex.step = (1.0 * texHeight) / draw.lineHeight;
		pmlx->tex.texPos = (draw.Start - screenHeight / 2 + draw.lineHeight / 2) * pmlx->tex.step;
		//printf("%d\n", pmlx->tex.step);
		draw_ray(pmlx->mlx.data_addr, x, draw, color, pmlx, ray);
	}
	mlx_put_image_to_window(pmlx->mlx.mlx_ptr, pmlx->mlx.win_ptr, pmlx->mlx.img_ptr, 0, 0);
}

int	loop(t_pmlx *pmlx)
{
	if (pmlx->bool_W == 1)//W
		forward(pmlx);
	if (pmlx->bool_S == 1)//S
		downward(pmlx);
	if (pmlx->bool_A == 1)//A
		mv_left(pmlx);
	if (pmlx->bool_D == 1)//D
		mv_right(pmlx);
	main_loop(pmlx);
	return (0);
}

int main()//(int argc, char *argv[])
{
	t_pmlx pmlx;

	pmlx.bool_ESC = 0;
	pmlx.pl.posX = 22;
	pmlx.pl.posY = 12;	//x and y start position
	pmlx.pl.dirX = -1;
	pmlx.pl.dirY = 0; //initial direction vector
	pmlx.pl.planeX = 0;
	pmlx.pl.planeY = 0.66; //the 2d raycaster version of camera plane

	pmlx.pl.moveSpeed = 0.25;
	pmlx.pl.rotSpeed = 0.1;

	pmlx.mlx.mlx_ptr = mlx_init();
	pmlx.mlx.win_ptr = mlx_new_window(pmlx.mlx.mlx_ptr, screenWidth, screenHeight, "Cub3D");
	pmlx.mlx.img_ptr = mlx_new_image(pmlx.mlx.mlx_ptr, screenWidth, screenHeight);
	pmlx.mlx.data_addr = mlx_get_data_addr(pmlx.mlx.img_ptr, &(pmlx.mlx.bpp), &(pmlx.mlx.size_l), &(pmlx.mlx.endian));
	//while(x != screenWidth)
	init_texture(&pmlx);
	//main_loop(&pmlx);
	mlx_hook(pmlx.mlx.win_ptr, KEYPRESS, KEYPRESSMASK, &deal_key_press, &pmlx);
	mlx_hook(pmlx.mlx.win_ptr, KEYRELEASE, KEYRELEASEMASK, &deal_key_release, &pmlx);
	mlx_loop_hook(pmlx.mlx.mlx_ptr, &loop, &pmlx);
	mlx_loop(pmlx.mlx.mlx_ptr);
}