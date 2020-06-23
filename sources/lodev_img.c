#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int main()
{
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
    double posX = 22, posY = 12;  //x and y start position
    double dirX = -1, dirY = 0; //initial direction vector
    double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame

    //screen(screenWidth, screenHeight, 0, "Raycaster");
    int x = -1;
    int w = screenWidth;
    int h = screenHeight;
    while(x + 1 < w) // !done
    {
        while (++x < w)
        {
          //calculate ray position and direction
            double cameraX;
            double rayDirX;
            double rayDirY;
            double deltaDistX;
            double perpWallDist;
            double deltaDistY;
        //length of ray from current position to next x or y-side
            double sideDistY;
            double sideDistX;
            int mapX;
            int mapY;
            //what direction to step in x or y-direction (either +1 or -1)
            int stepX;
            int stepY;
            cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
            rayDirX = dirX + planeX * cameraX;
            rayDirY = dirY + planeY * cameraX;
            //which box of the map we're in
            mapX = (int)posX;
            mapY = (int)posY;
            //length of ray from one x or y-side to next x or y-side
            deltaDistX = 1 / rayDirX;
            deltaDistY = abs(1 / rayDirY);



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
            else            perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

            //Calculate height of line to draw on screen
            int lineHeight = (int)(h / perpWallDist);

            //calculate lowest and highest pixel to fill in current stripe
            int drawStart = -lineHeight / 2 + h / 2;
            if(drawStart < 0)drawStart = 0;
            int drawEnd = lineHeight / 2 + h / 2;
            if(drawEnd >= h)drawEnd = h - 1;

            //choose wall color
            /*
            ColorRGB color;
            if (worldMap[mapX][mapY] == 1)
              color = RGB_Red;
            else if (worldMap[mapX][mapY] == 2)
              color = RGB_Green;
            else if (worldMap[mapX][mapY] == 3)
              color = RGB_Blue;
            else if (worldMap[mapX][mapY] == 4)
              color = RGB_White;
            else
              color = RGB_Yellow;
            //give x and y sides different brightness
            if(side == 1) {color = color / 2;}

            //draw the pixels of the stripe as a vertical line
            verLine(x, drawStart, drawEnd, color);
            */
           printf("%f\n", perpWallDist);
        }
    }
}
