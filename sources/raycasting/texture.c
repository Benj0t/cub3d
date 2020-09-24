/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:09:09 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/20 16:16:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_pmlx *pmlx)
{
	int i;

	if (!(pmlx->img.image = (char **)malloc(sizeof(char *) * (6))))
		ray_err("Error\n(malloc)", pmlx, 1);
	if (!(pmlx->img.addr = (void **)malloc(sizeof(void *) * (6))))
		ray_err("Error\n(malloc)", pmlx, 1);
	pmlx->img.image[5] = NULL;
	pmlx->img.addr[5] = NULL;
	pmlx->img.addr[0] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, pmlx->s.so,\
						&(pmlx->img.img_w), &(pmlx->img.img_h));
	pmlx->img.addr[1] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, pmlx->s.we,\
						&(pmlx->img.img_w), &(pmlx->img.img_h));
	pmlx->img.addr[2] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, pmlx->s.no,\
						&(pmlx->img.img_w), &(pmlx->img.img_h));
	pmlx->img.addr[3] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, pmlx->s.ea,\
						&(pmlx->img.img_w), &(pmlx->img.img_h));
	pmlx->img.addr[4] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, pmlx->s.s,\
						&(pmlx->img.img_w), &(pmlx->img.img_h));
	i = 0;
	while (i < 5)
	{
		pmlx->img.image[i] = mlx_get_data_addr(pmlx->img.addr[i],\
				&(pmlx->img.bpp), &(pmlx->img.s_line), &(pmlx->img.endian));
		i++;
	}
}
