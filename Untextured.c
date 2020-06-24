/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untextured.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:25:37 by bemoreau          #+#    #+#             */
/*   Updated: 2020/06/24 18:29:43 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mlx.h"

//place the example code below here:

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24
#define RGB_RED 16711680
#define RGB_GREEN 65280
#define RGB_BLUE 255
#define RGB_WHITE 16777215
#define RGB_YELLOW 16776960

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

void	putpix_R(char *data_addr, int x, int y, int color)
{
	int pos;
	pos = (y * screenWidth + x) * 4;
	data_addr[pos + RED_COMP] = 127;
	data_addr[pos + GREEN_COMP] = 0;
	data_addr[pos + BLUE_COMP] = 0;
}

void	putpix_V(char *data_addr, int x, int y, int color)
{
	int pos;
	pos = (y * screenWidth + x) * 4;
	data_addr[pos + RED_COMP] = 0;
	data_addr[pos + GREEN_COMP] = 127;
	data_addr[pos + BLUE_COMP] = 0;
}

void	putpix_B(char *data_addr, int x, int y, int color)
{
	int pos;
	pos = (y * screenWidth + x) * 4;
	data_addr[pos + RED_COMP] = 0;
	data_addr[pos + GREEN_COMP] = 0;
	data_addr[pos + BLUE_COMP] = 127;
}

void	draw_ray(char *data_addr, int x, int start, int end, int color)
{
	int y;

	y = 0;
	while (y < screenHeight)
	{
		if (y < start)
			putpix_R(data_addr, x, y, RGB_YELLOW);
		else if (y >= start && y <= end)
			putpix_V(data_addr, x, y, color);
		else
		{
			putpix_B(data_addr, x, y, RGB_GREEN);
		}
		y++;
	}
}

int main()//(int argc, char *argv[])
{
	double posX = 22, posY = 12;	//x and y start position
	double dirX = -1, dirY = 0; //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	char *data_addr;
	int endian;
	int bpp;
	int size_l;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "Cub3D");
	img_ptr = mlx_new_image(mlx_ptr, screenWidth, screenHeight);
	data_addr = mlx_get_data_addr(img_ptr, &bpp, &size_l, &endian);
	//while(x != screenWidth)
	//{
		for(int x = 0; x < screenWidth; x++)
		{
			//calculate ray position and direction
			double cameraX = 2 * x / (double)screenWidth - 1; //x-coordinate in camera space
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;
			//which box of the map we're in
			int mapX = (int)posX;
			int mapY = (int)posY;

			//length of ray from current position to next x or y-side
			double sideDistX;
			double sideDistY;

			 //length of ray from one x or y-side to next x or y-side
			double deltaDistX = fabs(1 / rayDirX);
			double deltaDistY = fabs(1 / rayDirY);
			double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?
			//calculate step and initial sideDist
			if(rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			}
			if(rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			}
			//perform DDA
			while (hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if(sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if(worldMap[mapX][mapY] > 0) hit = 1;
			}
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			if(side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
			else					perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

			//Calculate height of line to draw on screen
			int lineHeight = (int)(screenHeight / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + screenHeight / 2;
			if(drawStart < 0)drawStart = 0;
			int drawEnd = lineHeight / 2 + screenHeight / 2;
			if(drawEnd >= screenHeight)drawEnd = screenHeight - 1;

			//choose wall color
			int color;
			if (worldMap[mapX][mapY] == 1)
				color = RGB_RED; //red
			if (worldMap[mapX][mapY] == 2)
				color = RGB_GREEN; //green
			if (worldMap[mapX][mapY] == 3)
				color = RGB_BLUE; //blue
			if (worldMap[mapX][mapY] == 4)
				color = RGB_WHITE; //white
			else
			{
				color = RGB_YELLOW; //yellow
			}
			//give x and y sides different brightness
			if(side == 1)
				color = color / 2;
			//draw the pixels of the stripe as a vertical line
			draw_ray(data_addr, x, drawStart, drawEnd, color);
		}
		//printf("%s\n", data_addr);
		mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
		mlx_loop(mlx_ptr);
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
			if(worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == 0) posX += dirX * moveSpeed;
			if(worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == 0) posY += dirY * moveSpeed;
		}
		//move backwards if no wall behind you
		if(keyDown(SDLK_DOWN))
		{
			if(worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == 0) posX -= dirX * moveSpeed;
			if(worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == 0) posY -= dirY * moveSpeed;
		}
		//rotate to the right
		if(keyDown(SDLK_RIGHT))
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = dirX;
			dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
			dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
			planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
		}
		//rotate to the left
		if(keyDown(SDLK_LEFT))
		{
			//both camera direction and camera plane must be rotated
			double oldDirX = dirX;
			dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
			dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
			double oldPlaneX = planeX;
			planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
			planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
		}
		*/
	//}
}