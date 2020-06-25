/*
Copyright (c) 2004-2019, Lode Vandevenne

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

      * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
      * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"

/*
g++ *.cpp -lSDL -O3 -W -Wall -ansi -pedantic
g++ *.cpp -lSDL
*/


#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
    {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
    {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
    {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
    {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
    {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
    {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
    {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
    {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
    {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
    {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
    {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
    {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
    {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
    {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
    {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
    {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
    {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
    {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
    {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
    {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
    {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};



char	*ft_conv_hex(int nb)
{
	char	*base = "0123456789ABCDEF";
	char	*str;
	int		len;
	int		mult;

	len = nb / 16;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return(NULL);
	str[len--] = '\0';
	mult = 1;
	while (nb >= 0)
	{
		str[len--] = base[nb % 16];
		nb -= 16 * mult++;
	}
	return(str);
}

char **ft_hex(int **buffer)
{
	char **tab;
	int x;
	int y;

	x = 0;
	y = 0;
	while (buffer[x])
	{
		while(buffer[x][y])
			y++;
		x++;
	}
	char tab[x][y];
	x = -1;
	y = -1;
	while (buffer[++x])
		while(buffer[x][++y])
			tab[x][y] = ft_conv_hex(buffer[x][y]);
	return(tab);
}


int main(int argc, char **argv)
{
	void	*ptr;
	void	*win_ptr;
    (void)argc;
    (void)argv;
    unsigned int buffer[screenHeight][screenWidth];
    double posX = 22.0, posY = 11.5;  //x and y start position
    double dirX = -1.0, dirY = 0.0; //initial direction vector
    double planeX = 0.0, planeY = 0.66; //the 2d raycaster version of camera plane

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame

    unsigned int *texture[8];
    int i = -1;

	while (++i <= 8)
    {
        if (!(texture[i] = (unsigned int *)malloc(sizeof(int) * (texWidth * texHeight))))
            return (0); //
    }

    //screen(screenWidth,screenHeight, 0, "Raycaster"); // start MLX
	
	ptr = mlx_init();
	win_ptr = mlx_new_window(ptr, screenHeight, screenWidth, "Cub3D");

    //generate some textures
    for(int x = 0; x < texWidth; x++)
    {
        for(int y = 0; y < texHeight; y++)
        {
            int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
            //int xcolor = x * 256 / texWidth;
            int ycolor = y * 256 / texHeight;
            int xycolor = y * 128 / texHeight + x * 128 / texWidth;
      
            texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
            texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
            texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
            texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
            texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
            texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
            texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
            texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
                    }
    }
    else // SOUCIS CAR RETURN VOID *
    {
    //generate some textures
        //unsigned long tw;
        //unsigned long th;
        //texture[0] = mlx_xpm_file_to_image(mlx_ptr, tw, th, "pics/eagle.png");
        //texture[1] = mlx_xpm_file_to_image(mlx_ptr, tw, th, "pics/redbrick.png");
        //texture[2] = mlx_xpm_file_to_image(mlx_ptr, tw, th, "pics/purplestone.png");
        //texture[3] = mlx_xpm_file_to_image(mlx_ptr, tw, th, "pics/greystone.png");
        //texture[4] = mlx_xpm_file_to_image(mlx_ptr, tw, th, "pics/bluestone.png");
        //texture[5] = mlx_xpm_file_to_image(mlx_ptr, tw, th, "pics/mossy.png");
        //texture[6] = mlx_xpm_file_to_image(mlx_ptr, tw, th, "pics/wood.png");
        //texture[7] = mlx_xpm_file_to_image(mlx_ptr, tw, th, "pics/colorstone.png");
    }
    int w = screenWidth;
    int h = screenHeight;
    //start the main loop
    int bis = 0;
    while(!bis++)
    {
      for(int x = 0; x < w; x++)
      {
          //calculate ray position and direction
          double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
          double rayDirX = dirX + planeX*cameraX;
          double rayDirY = dirY + planeY*cameraX;

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

          //Calculate distance of perpendicular ray (Euclidean distance will give fisheye effect!)
          if(side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
          else              perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

          //Calculate height of line to draw on screen
          int lineHeight = (int)(h / perpWallDist);

          //calculate lowest and highest pixel to fill in current stripe
          int drawStart = -lineHeight / 2 + h / 2;
          if(drawStart < 0) drawStart = 0;
          int drawEnd = lineHeight / 2 + h / 2;
          if(drawEnd >= h) drawEnd = h - 1;

          //texturing calculations
          int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!

          //calculate value of wallX
          double wallX; //where exactly the wall was hit
          if(side == 0) wallX = posY + perpWallDist * rayDirY;
          else              wallX = posX + perpWallDist * rayDirX;
          wallX -= floor((wallX));

          //x coordinate on the texture
          int texX = (int)(wallX * (double)texWidth);
          if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
          if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

          // TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
          // How much to increase the texture coordinate per screen pixel
          double step = 1.0 * texHeight / lineHeight;
          // Starting texture coordinate
          double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
          for(int y = drawStart; y < drawEnd; y++)
          {
            // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
            int texY = (int)texPos & (texHeight - 1);
            texPos += step;
            unsigned int color = texture[texNum][texHeight * texY + texX];
            //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
            if(side == 1) 
				color = (color >> 1) & 8355711;
            buffer[y][x] = color;
          }
      }
      (void)time;
      (void)oldTime;
    }
		void	*img_ptr;
		char	*img;
		int		bits;
		int		bits_extended;
		int		endian;
		img_ptr = mlx_new_image(ptr, screenWidth, screenHeight);
		img = mlx_get_data_addr(ptr, &bits, &bits_extended, &endian);

	  /*
	  for(int y = 0; y < h; y++) for(int x = 0; x < w; x++) buffer[y][x] = 0; //clear the buffer instead of cls()
      //timing for input and FPS counter
      oldTime = time;
      time = getTicks();
      double frameTime = (time - oldTime) / 1000.0; //frametime is the time this frame has taken, in seconds
      print(1.0 / frameTime); //FPS counter
      redraw();

      //speed modifiers
      double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
      double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

      readKeys();
      //move forward if no wall in front of you
      if(keyDown(SDLK_UP))
      {
          if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
          if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
      }
      //move backwards if no wall behind you
      if(keyDown(SDLK_DOWN))
      {
          if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
          if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
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
      if(keyDown(SDLK_ESCAPE))
      {
          break;
      }
    }
	*/
}
