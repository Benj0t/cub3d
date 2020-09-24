/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:09:05 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/20 16:16:27 by marvin           ###   ########.fr       */
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
		sprites[i].distance = pmlx->sp.sprite_distance[i];
		sprites[i].ordre = pmlx->sp.sprite_order[i];
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
		pmlx->sp.sprite_distance[i] = sprites[amount - i - 1].distance;
		pmlx->sp.sprite_order[i] = sprites[amount - i - 1].ordre;
	}
}

void	start_sp2(t_pmlx *pmlx)
{
	if (pmlx->sp.drawstarty < 0)
	{
		pmlx->sp.drawstarty = 0;
	}
	pmlx->sp.drawendy = pmlx->sp.spriteheight / 2 +\
						pmlx->s.r.y / 2 + pmlx->sp.vmove_screen;
	if (pmlx->sp.drawendy >= pmlx->s.r.y)
		pmlx->sp.drawendy = pmlx->s.r.y - 1;
	pmlx->sp.spritewidth = abs((int)(pmlx->s.r.y /\
						(pmlx->sp.transformy))) / UDIV;
	pmlx->sp.drawstartx = -pmlx->sp.spritewidth / 2 + pmlx->sp.spritescreenx;
	if (pmlx->sp.drawstartx < 0)
		pmlx->sp.drawstartx = 0;
	pmlx->sp.drawendx = pmlx->sp.spritewidth / 2 + pmlx->sp.spritescreenx;
	if (pmlx->sp.drawendx >= pmlx->s.r.x)
		pmlx->sp.drawendx = pmlx->s.r.x - 1;
}

void	start_sp(t_pmlx *pmlx, int i)
{
	pmlx->sp.spritex = pmlx->s.list[pmlx->sp.sprite_order[i]].x - pmlx->pl.posx;
	pmlx->sp.spritey = pmlx->s.list[pmlx->sp.sprite_order[i]].y - pmlx->pl.posy;
	pmlx->sp.invdet = 1.0 / (pmlx->pl.planex * pmlx->pl.diry -\
						pmlx->pl.dirx * pmlx->pl.planey);
	pmlx->sp.transformx = pmlx->sp.invdet * (pmlx->pl.diry *\
						pmlx->sp.spritex - pmlx->pl.dirx * pmlx->sp.spritey);
	pmlx->sp.transformy = pmlx->sp.invdet * (-pmlx->pl.planey *\
					pmlx->sp.spritex + pmlx->pl.planex * pmlx->sp.spritey);
	pmlx->sp.spritescreenx = (int)((pmlx->s.r.x / 2) *\
						(1 + pmlx->sp.transformx / pmlx->sp.transformy));
	pmlx->sp.vmove_screen = (int)(VMOVE / pmlx->sp.transformy);
	pmlx->sp.spriteheight = abs((int)(pmlx->s.r.y /\
							(pmlx->sp.transformy))) / VDIV;
	pmlx->sp.drawstarty = -pmlx->sp.spriteheight / 2 +\
							pmlx->s.r.y / 2 + pmlx->sp.vmove_screen;
	start_sp2(pmlx);
}

void	sprites_2(t_pmlx *pmlx, int stripe)
{
	int		y;
	int		d;
	int		texy;
	t_color	color;

	y = pmlx->sp.drawstarty - 1;
	while (++y < pmlx->sp.drawendy)
	{
		d = (y - pmlx->sp.vmove_screen) * 256 - pmlx->s.r.y *\
							128 + pmlx->sp.spriteheight * 128;
		texy = ((d * TEXHEIGHT) / pmlx->sp.spriteheight) / 256;
		color.r = pmlx->img.image[4][(TEXWIDTH *\
				texy + pmlx->sp.texx) * 4 + RED_COMP];
		color.g = pmlx->img.image[4][(TEXWIDTH *\
				texy + pmlx->sp.texx) * 4 + GREEN_COMP];
		color.b = pmlx->img.image[4][(TEXWIDTH *\
				texy + pmlx->sp.texx) * 4 + BLUE_COMP];
		if (!(color.r == 0 && color.g == 0 && color.b == 0))
			sp_rgb(pmlx, color, stripe, y);
	}
}

void	ft_sprites(t_pmlx *pmlx, double zbuffer[pmlx->s.r.x])
{
	int i;
	int stripe;

	init_sp_tab(pmlx);
	sort_sprites(pmlx, pmlx->s.sprite_num);
	i = -1;
	while (++i < pmlx->s.sprite_num)
	{
		start_sp(pmlx, i);
		stripe = pmlx->sp.drawstartx - 1;
		while (++stripe < pmlx->sp.drawendx)
		{
			pmlx->sp.texx = (int)(256 * (stripe - (-pmlx->sp.spritewidth / 2 +\
			pmlx->sp.spritescreenx)) * TEXWIDTH / pmlx->sp.spritewidth) / 256;
			if (pmlx->sp.transformy > 0 && stripe > 0 &&\
				stripe < pmlx->s.r.x && pmlx->sp.transformy < zbuffer[stripe])
				sprites_2(pmlx, stripe);
		}
	}
}
