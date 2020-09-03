/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:23:40 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/03 16:32:48 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	putpix(t_pmlx *pmlx, int x, int y, t_color color)
{
	int pos;

	pos = (y * pmlx->s.r.x + x) * 4;
	pmlx->mlx.data_addr[pos + RED_COMP] = color.r;
	pmlx->mlx.data_addr[pos + GREEN_COMP] = color.g;
	pmlx->mlx.data_addr[pos + BLUE_COMP] = color.b;
}

void	draw_ray(t_pmlx *pmlx, int x, t_draw draw, t_ray ray)
{
	int		y;
	t_color	color;

	y = 0;
	while (y < pmlx->s.r.y)
	{
		if (y < draw.start)
			putpix(pmlx, x, y, pmlx->s.ceil);
		else if (y >= draw.start && y <= draw.end)
		{
			pmlx->tex.step = (1.0 * TEXHEIGHT) / draw.lineheight;
			pmlx->tex.texy = (int)pmlx->tex.texpos & (TEXHEIGHT - 1);
			pmlx->tex.texpos += pmlx->tex.step;
			color.r = pmlx->img.image[pmlx->tex.texnum]\
			[(TEXHEIGHT * pmlx->tex.texy + pmlx->tex.texx) * 4 + RED_COMP];
			color.g = pmlx->img.image[pmlx->tex.texnum]\
			[(TEXHEIGHT * pmlx->tex.texy + pmlx->tex.texx) * 4 + BLUE_COMP];
			color.b = pmlx->img.image[pmlx->tex.texnum]\
			[(TEXHEIGHT * pmlx->tex.texy + pmlx->tex.texx) * 4 + GREEN_COMP];
			putpix(pmlx, x, y, color);
		}
		else
			putpix(pmlx, x, y, pmlx->s.floor);
		y++;
	}
}
