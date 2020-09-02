/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:09:05 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/02 20:21:19 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_pmlx *pmlx, int amount)
{
	t_vector	sprites[amount];
	int			i;
	int			j;

	i = -1;
	while (++i < amount)
	{
		sprites[i].distance = pmlx->sp.spriteDistance[i];
		sprites[i].ordre = pmlx->sp.spriteOrder[i];
	}
	i = -1;
	j = -1;
	while (++i < amount)
	{
		while (++j < amount)
			if (sprites[i].distance > sprites[j].distance)
				ft_swap(&(sprites[i]), &(sprites[j]));
		j = i;
	}
	i = -1;
	while (++i < amount)
	{
		pmlx->sp.spriteDistance[i] = sprites[amount - i - 1].distance;
		pmlx->sp.spriteOrder[i] = sprites[amount - i - 1].ordre;
	}
}

void	start_sp2(t_pmlx *pmlx, int i)
{
	if (pmlx->sp.drawStartY < 0)
		pmlx->sp.drawStartY = 0;
	pmlx->sp.drawEndY = pmlx->sp.spriteHeight / 2 +\
						pmlx->s.R.y / 2 + pmlx->sp.vMoveScreen;
	if (pmlx->sp.drawEndY >= pmlx->s.R.y)
		pmlx->sp.drawEndY = pmlx->s.R.y - 1;
	pmlx->sp.spriteWidth = abs((int)(pmlx->s.R.y /\
						(pmlx->sp.transformY))) / uDiv;
	pmlx->sp.drawStartX = -pmlx->sp.spriteWidth / 2 + pmlx->sp.spriteScreenX;
	if (pmlx->sp.drawStartX < 0)
		pmlx->sp.drawStartX = 0;
	pmlx->sp.drawEndX = pmlx->sp.spriteWidth / 2 + pmlx->sp.spriteScreenX;
	if (pmlx->sp.drawEndX >= pmlx->s.R.x)
		pmlx->sp.drawEndX = pmlx->s.R.x - 1;
}

void	start_sp(t_pmlx *pmlx, int i)
{
	pmlx->sp.spriteX = pmlx->s.list[pmlx->sp.spriteOrder[i]].x - pmlx->pl.posX;
	pmlx->sp.spriteY = pmlx->s.list[pmlx->sp.spriteOrder[i]].y - pmlx->pl.posY;
	pmlx->sp.invDet = 1.0 / (pmlx->pl.planeX * pmlx->pl.dirY -\
						pmlx->pl.dirX * pmlx->pl.planeY);
	pmlx->sp.transformX = pmlx->sp.invDet * (pmlx->pl.dirY *\
						pmlx->sp.spriteX - pmlx->pl.dirX * pmlx->sp.spriteY);
	pmlx->sp.transformY = pmlx->sp.invDet * (-pmlx->pl.planeY *\
					pmlx->sp.spriteX + pmlx->pl.planeX * pmlx->sp.spriteY);
	pmlx->sp.spriteScreenX = (int)((pmlx->s.R.x / 2) *\
						(1 + pmlx->sp.transformX / pmlx->sp.transformY));
	pmlx->sp.vMoveScreen = (int)(vMove / pmlx->sp.transformY);
	pmlx->sp.spriteHeight = abs((int)(pmlx->s.R.y /\
							(pmlx->sp.transformY))) / vDiv;
	pmlx->sp.drawStartY = -pmlx->sp.spriteHeight / 2 +\
							pmlx->s.R.y / 2 + pmlx->sp.vMoveScreen;
	start_sp2(pmlx, i);
}

void	sprites_2(t_pmlx *pmlx, int stripe)
{
	int		y;
	int		d;
	int		texy;
	t_color	color;

	y = pmlx->sp.drawStartY - 1;
	while (++y < pmlx->sp.drawEndY)
	{
		d = (y - pmlx->sp.vMoveScreen) * 256 - pmlx->s.R.y *\
							128 + pmlx->sp.spriteHeight * 128;
		texy = ((d * texHeight) / pmlx->sp.spriteHeight) / 256;
		color.R = pmlx->img.image[4][(texWidth *\
				texy + pmlx->sp.texX) * 4 + RED_COMP];
		color.G = pmlx->img.image[4][(texWidth *\
				texy + pmlx->sp.texX) * 4 + GREEN_COMP];
		color.B = pmlx->img.image[4][(texWidth *\
				texy + pmlx->sp.texX) * 4 + BLUE_COMP];
		if (!(color.R == 0 && color.G == 0 && color.B == 0))
			sp_rgb(pmlx, color, stripe, y);
	}
}

void	ft_sprites(t_pmlx *pmlx, double zbuffer[pmlx->s.R.x])
{
	int i;
	int stripe;

	init_sp_tab(pmlx);
	sort_sprites(pmlx, pmlx->s.sprite_num);
	i = -1;
	while (++i < pmlx->s.sprite_num)
	{
		start_sp(pmlx, i);
		stripe = pmlx->sp.drawStartX - 1;
		while (++stripe < pmlx->sp.drawEndX)
		{
			pmlx->sp.texX = (int)(256 * (stripe - (-pmlx->sp.spriteWidth / 2 +\
			pmlx->sp.spriteScreenX)) * texWidth / pmlx->sp.spriteWidth) / 256;
			if (pmlx->sp.transformY > 0 && stripe > 0 &&\
				stripe < pmlx->s.R.x && pmlx->sp.transformY < zbuffer[stripe])
				sprites_2(pmlx, stripe);
		}
	}
}
