#include "cub3d.h"

//arrays used to sort the sprites
t_coords_sprite sprite[numSprites] =
{
  {18.5, 10.5, 6},
  {18.5, 11.5, 6},
  {18.5, 12.5, 6},
  {6.5, 8.5, 8},
  {20.5, 11.5, 7}, //green light in front of playerstart
  //green lights in every room
  {18.5,4.5, 7},
  {10.0,4.5, 7},
  {10.0,12.5,7},
  {3.5, 6.5, 7},
  {3.5, 20.5,7},
  {3.5, 14.5,7},
  {14.5,20.5,7},

  //row of pillars in front of wall: fisheye test

  //some barrels around the map
  {21.5, 1.5, 5},
  {15.5, 1.5, 5},
  {16.0, 1.8, 5},
  {16.2, 1.2, 5},
  {3.5,  2.5, 5},
  {9.5, 15.5, 5},
  {10.0, 15.1,5},
  {10.5, 15.8,5},
};

void    ft_swap(t_vector *a, t_vector *b)
{
    t_vector c;
    c = *a;
    *a = *b;
    *b = c;
}

void    sortSprites(t_pmlx *pmlx, int amount)
{
    t_vector sprites[amount];
    for(int k = 0; k < amount; k++) {
    sprites[k].distance = pmlx->sp.spriteDistance[k];
    sprites[k].ordre = pmlx->sp.spriteOrder[k];
    }
    int i;
    int j;

    i = -1;
    j = -1;
    while (++i < amount)
    {
        while (++j < amount)
        {
            if (sprites[i].distance > sprites[j].distance)
            ft_swap(&(sprites[i]), &(sprites[j]));
        }
        j = i;
    }
  // restore in reverse order to go from farthest to nearest   
	for(int f = 0; f < amount; f++)
    {
      pmlx->sp.spriteDistance[f] = sprites[amount - f - 1].distance;
      pmlx->sp.spriteOrder[f] = sprites[amount - f - 1].ordre;
    }
}

void    ft_sprites(t_pmlx *pmlx)
{
	for(int i = 0; i < numSprites; i++)
	{
		pmlx->sp.spriteOrder[i] = i;
		pmlx->sp.spriteDistance[i] = ((pmlx->pl.posX - sprite[i].x) * (pmlx->pl.posX - sprite[i].x) + (pmlx->pl.posY - sprite[i].y) * (pmlx->pl.posY - sprite[i].y)); //sqrt not taken, unneeded
	}
	sortSprites(pmlx, numSprites);
	//after sorting the sprites, do the projection and draw them
	for(int i = 0; i < numSprites; i++)
	{
		//translate sprite position to relative to camera
		pmlx->sp.spriteX = sprite[pmlx->sp.spriteOrder[i]].x - pmlx->pl.posX;
		pmlx->sp.spriteY = sprite[pmlx->sp.spriteOrder[i]].y - pmlx->pl.posY;

		pmlx->sp.invDet = 1.0 / (pmlx->pl.planeX * pmlx->pl.dirY - pmlx->pl.dirX * pmlx->pl.planeY); //required for correct matrix multiplication

		pmlx->sp.transformX = pmlx->sp.invDet * (pmlx->pl.dirY * pmlx->sp.spriteX - pmlx->pl.dirX * pmlx->sp.spriteY);
		pmlx->sp.transformY = pmlx->sp.invDet * (-pmlx->pl.planeY * pmlx->sp.spriteX + pmlx->pl.planeX * pmlx->sp.spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(pmlx->sp.spriteDistance[i])

		pmlx->sp.spriteScreenX = (int)((screenWidth / 2) * (1 + pmlx->sp.transformX / pmlx->sp.transformY));

		//parameters for scaling and moving the sprites
		pmlx->sp.vMoveScreen = (int)(vMove / pmlx->sp.transformY);

		//calculate height of the sprite on screen
		pmlx->sp.spriteHeight = abs((int)(screenHeight / (pmlx->sp.transformY))) / vDiv; //using "pmlx->sp.transformY" instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		pmlx->sp.drawStartY = -pmlx->sp.spriteHeight / 2 + screenHeight / 2 + pmlx->sp.vMoveScreen;
		if(pmlx->sp.drawStartY < 0)
			pmlx->sp.drawStartY = 0;
		pmlx->sp.drawEndY = pmlx->sp.spriteHeight / 2 + screenHeight / 2 + pmlx->sp.vMoveScreen;
		if(pmlx->sp.drawEndY >= screenHeight) pmlx->sp.drawEndY = screenHeight - 1;

		//calculate width of the sprite
		pmlx->sp.spriteWidth = abs((int)(screenHeight / (pmlx->sp.transformY))) / uDiv;
		pmlx->sp.drawStartX = -pmlx->sp.spriteWidth / 2 + pmlx->sp.spriteScreenX;
		if(pmlx->sp.drawStartX < 0) pmlx->sp.drawStartX = 0;
		pmlx->sp.drawEndX = pmlx->sp.spriteWidth / 2 + pmlx->sp.spriteScreenX;
		if(pmlx->sp.drawEndX >= screenWidth) pmlx->sp.drawEndX = screenWidth - 1;

		//loop through every vertical stripe of the sprite on screen
		for(int stripe = pmlx->sp.drawStartX; stripe < pmlx->sp.drawEndX; stripe++)
		{
			pmlx->sp.texX = (int)(256 * (stripe - (-pmlx->sp.spriteWidth / 2 + pmlx->sp.spriteScreenX)) * texWidth / pmlx->sp.spriteWidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
            //printf("%f, %d, %f\n", pmlx->sp.transformY, stripe, pmlx->sp.ZBuffer[stripe]);
            if(pmlx->sp.transformY > 0 && stripe > 0 && stripe < screenWidth && pmlx->sp.transformY < pmlx->sp.ZBuffer[stripe])
			{
                //printf("Michel Forever Tonight\n");
				for(int y = pmlx->sp.drawStartY; y < pmlx->sp.drawEndY; y++) //for every pixel of the current stripe
				{
					int d = (y-pmlx->sp.vMoveScreen) * 256 - screenHeight * 128 + pmlx->sp.spriteHeight * 128; //256 and 128 factors to avoid floats
					int texY = ((d * texHeight) / pmlx->sp.spriteHeight) / 256;
					t_color color;
					color.R = pmlx->img.image[sprite[pmlx->sp.spriteOrder[i]].texture][(texWidth * texY + pmlx->sp.texX) * 4 + RED_COMP]; //get current color from the texture
					color.G = pmlx->img.image[sprite[pmlx->sp.spriteOrder[i]].texture][(texWidth * texY + pmlx->sp.texX) * 4 + GREEN_COMP]; //get current color from the texture
					color.B = pmlx->img.image[sprite[pmlx->sp.spriteOrder[i]].texture][(texWidth * texY + pmlx->sp.texX) * 4 + BLUE_COMP]; //get current color from the texture
                    //printf("R : %d\nG : %d\nB : %d\n", color.R, color.G, color.B);
					if(!(color.R == 0 && color.G == 0 && color.B == 0))
					{
						pmlx->mlx.data_addr[(y * screenWidth + stripe) * 4 + RED_COMP] = color.R;//paint pixel if it isn't black, black is the invisible color
						pmlx->mlx.data_addr[(y * screenWidth + stripe) * 4 + GREEN_COMP] = color.G;
						pmlx->mlx.data_addr[(y * screenWidth + stripe) * 4 + BLUE_COMP] = color.B; 
                    }
				}
			}
		}
    }
}