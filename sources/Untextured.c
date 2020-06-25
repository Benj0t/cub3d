/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untextured.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:25:37 by bemoreau          #+#    #+#             */
/*   Updated: 2020/06/25 16:30:14 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//place the example code below here:

int worldMap[mapWidth][mapHeight]=
{
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
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
t_color	ft_choose_color(t_player pl)
{
	t_color color;

	if (worldMap[pl.mapX][pl.mapY] == 1)
		color = ft_red();
	else if (worldMap[pl.mapX][pl.mapY] == 2)
		color = ft_blue(); //green
	else if (worldMap[pl.mapX][pl.mapY] == 3)
		color = ft_green(); //blue
	else if (worldMap[pl.mapX][pl.mapY] == 4)
		color = ft_white(); //white
	else
	{
		color = ft_yellow(); //yellow
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

void	draw_ray(char *data_addr, int x, t_draw draw, t_color color)
{
	int y;

	y = 0;
	while (y < screenHeight)
	{
		if (y < draw.Start)
			putpix(data_addr, x, y, ft_light_blue());
		else if (y >= draw.Start && y <= draw.End)
			putpix(data_addr, x, y, color);
		else
		{
			putpix(data_addr, x, y, ft_gray());
		}
		y++;
	}
}

int main()//(int argc, char *argv[])
{
	t_mlx mlx;
	t_ray ray;
	t_player pl;
	t_color color;
	t_draw draw;
	
	pl.posX = 22;
	pl.posY = 12;	//x and y start position
	pl.dirX = -1;
	pl.dirY = 0; //initial direction vector
	pl.planeX = 0;
	pl.planeY = 0.66; //the 2d raycaster version of camera plane

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, screenWidth, screenHeight, "Cub3D");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, screenWidth, screenHeight);
	mlx.data_addr = mlx_get_data_addr(mlx.img_ptr, &(mlx.bpp), &(mlx.size_l), &(mlx.endian));
	//while(x != screenWidth)
	//{
		for(int x = 0; x < screenWidth; x++)
		{
			//calculate ray position and direction
			ray.cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
			ray.rayDirX = pl.dirX + pl.planeX * ray.cameraX;
			ray.rayDirY = pl.dirY + pl.planeY * ray.cameraX;
			//which box of the map we're in
			pl.mapX = (int)pl.posX;
			pl.mapY = (int)pl.posY;

			 //length of ray from one x or y-side to next x or y-side
			ray.deltaDistX = fabs(1 / ray.rayDirX);
			ray.deltaDistY = fabs(1 / ray.rayDirY);
			
			ray.hit = 0;
			//calculate step and initial sideDist
			if(ray.rayDirX < 0)
			{
				pl.stepX = -1;
				ray.sideDistX = (pl.posX - pl.mapX) * ray.deltaDistX;
			}
			else
			{
				pl.stepX = 1;
				ray.sideDistX = (pl.mapX + 1.0 - pl.posX) * ray.deltaDistX;
			}
			if(ray.rayDirY < 0)
			{
				pl.stepY = -1;
				ray.sideDistY = (pl.posY - pl.mapY) * ray.deltaDistY;
			}
			else
			{
				pl.stepY = 1;
				ray.sideDistY = (pl.mapY + 1.0 - pl.posY) * ray.deltaDistY;
			}
			//perform DDA
			while (ray.hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if(ray.sideDistX < ray.sideDistY)
				{
					ray.sideDistX += ray.deltaDistX;
					pl.mapX += pl.stepX;
					ray.side = 0;
				}
				else
				{
					ray.sideDistY += ray.deltaDistY;
					pl.mapY += pl.stepY;
					ray.side = 1;
				}
				//Check if ray has ray.hit a wall
				if(worldMap[pl.mapX][pl.mapY] > 0) ray.hit = 1;
			}
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			if(ray.side == 0) ray.perpWallDist = (pl.mapX - pl.posX + (1 - pl.stepX) / 2) / ray.rayDirX;
			else					ray.perpWallDist = (pl.mapY - pl.posY + (1 - pl.stepY) / 2) / ray.rayDirY;

			//Calculate height of line to draw on screen
			draw.lineHeight = (int)(screenHeight / ray.perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			draw.Start = -draw.lineHeight / 2 + screenHeight / 2;
			if(draw.Start < 0)draw.Start = 0;
			draw.End = draw.lineHeight / 2 + screenHeight / 2;
			if(draw.End >= screenHeight)draw.End = screenHeight - 1;

			//choose wall color /!\ A REFAIRE /!\x
			color = ft_choose_color(pl);
			//give x and y sides different brightness
			if(ray.side == 1)
				color = ft_color_divide(color);
			//draw the pixels of the stripe as a vertical line
			draw_ray(mlx.data_addr, x, draw, color);
		}
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
		mlx_loop(mlx.mlx_ptr);
		//timing for input and FPS counter
//		oldTime = time;
//		time = getTicks();
//		double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
//		print(1.0 / frameTime); //FPS counter

		//speed modifiers
		double moveSpeed = 0.5; //the constant value is in squares/second
		double rotSpeed = 0.3; //the constant value is in radians/second
		/*
		readKeys();
		//move forward if no wall in front of you
		if(keyDown(SDLK_UP))
		{
			if(worldMap[(int)(pl.posX + pl.dirX * moveSpeed)][(int)pl.posY] == 0) pl.posX += pl.dirX * moveSpeed;
			if(worldMap[(int)pl.posX][(int)(pl.posY + pl.dirY * moveSpeed)] == 0) pl.posY += pl.dirY * moveSpeed;
		}
		//move backwards if no wall behind you
		if(keyDown(SDLK_DOWN))
		{
			if(worldMap[(int)(pl.posX - pl.dirX * moveSpeed)][(int)pl.posY] == 0) pl.posX -= pl.dirX * moveSpeed;
			if(worldMap[(int)pl.posX][(int)(pl.posY - pl.dirY * moveSpeed)] == 0) pl.posY -= pl.dirY * moveSpeed;
		}
		//rotate to the right
		if(keyDown(SDLK_RIGHT))
		{
			//both camera direction and camera plane must be rotated
			double oldpl.DirX = pl.dirX;
			pl.dirX = pl.dirX * cos(-rotSpeed) - pl.dirY * sin(-rotSpeed);
			pl.dirY = oldpl.DirX * sin(-rotSpeed) + pl.dirY * cos(-rotSpeed);
			double oldpl.PlaneX = pl.planeX;
			pl.planeX = pl.planeX * cos(-rotSpeed) - pl.planeY * sin(-rotSpeed);
			pl.planeY = oldpl.PlaneX * sin(-rotSpeed) + pl.planeY * cos(-rotSpeed);
		}
		//rotate to the left
		if(keyDown(SDLK_LEFT))
		{
			//both camera direction and camera plane must be rotated
			double oldpl.DirX = pl.dirX;
			pl.dirX = pl.dirX * cos(rotSpeed) - pl.dirY * sin(rotSpeed);
			pl.dirY = oldpl.DirX * sin(rotSpeed) + pl.dirY * cos(rotSpeed);
			double oldpl.PlaneX = pl.planeX;
			pl.planeX = pl.planeX * cos(rotSpeed) - pl.planeY * sin(rotSpeed);
			pl.planeY = oldpl.PlaneX * sin(rotSpeed) + pl.planeY * cos(rotSpeed);
		}
		*/
	//}
}