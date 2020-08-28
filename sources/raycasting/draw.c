/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:23:40 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/28 14:50:16 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
