/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:09:09 by bemoreau          #+#    #+#             */
/*   Updated: 2020/07/25 13:09:09 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_texture(t_pmlx *pmlx)
{
    int i;

    pmlx->img.bpp = 0;
    pmlx->img.s_line = 0;
    pmlx->img.endian = 0;
    if (!(pmlx->img.image = (char **)malloc(sizeof(char *) * (6))))
        return;
    if (!(pmlx->img.addr = (void **)malloc(sizeof(void *) * (6))))
        return;
    pmlx->img.image[5] = NULL;
    pmlx->img.addr[5] = NULL;
    pmlx->img.addr[0] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, pmlx->s.SO, &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[1] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, pmlx->s.WE, &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[2] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, pmlx->s.NO, &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[3] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, pmlx->s.EA, &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[4] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, pmlx->s.S, &(pmlx->img.img_W), &(pmlx->img.img_H));
    i = 0;
    while (i < 5)
    {
        pmlx->img.image[i] = mlx_get_data_addr(pmlx->img.addr[i], &(pmlx->img.bpp), &(pmlx->img.s_line), &(pmlx->img.endian));
        i++;
    }
} 