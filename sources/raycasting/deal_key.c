/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:49:55 by bemoreau          #+#    #+#             */
/*   Updated: 2020/07/06 23:31:45 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_destroy(t_pmlx *pmlx)
{
	int i;
	
	i = 0;
	while (i <= 5)
	{
		free(pmlx->img.addr[i]);
		free(pmlx->img.image[i++]);
	}
	free(pmlx->img.addr);
	free(pmlx->img.image);
	free(pmlx->mlx.data_addr);
	mlx_destroy_window(pmlx->mlx.mlx_ptr, pmlx->mlx.win_ptr);
	//mlx_destroy_image(pmlx->mlx.mlx_ptr, pmlx->mlx.img_ptr);
	free(pmlx->mlx.img_ptr);
	free(pmlx->mlx.mlx_ptr);
	exit(1);
}

int		deal_key_press(int key, t_pmlx *pmlx)
{
	if (key == ESC_KEY_L)
		pmlx->bool_ESC = 1;
	if (key == W_KEY_L)//W
		pmlx->bool_W = 1;
	if (key == S_KEY_L)//S
		pmlx->bool_S = 1;
	if (key == A_KEY_L)//A
		pmlx->bool_A = 1;
	if (key == D_KEY_L)//D
		pmlx->bool_D = 1;
	main_loop(pmlx);
	return(0);
}

int		deal_key_release(int key, t_pmlx *pmlx)
{
	if (key == ESC_KEY_L)
		ft_destroy(pmlx);
	if (key == W_KEY_L)//W
		pmlx->bool_W = 0;
	if (key == S_KEY_L)//S
		pmlx->bool_S = 0;
	if (key == A_KEY_L)//A
		pmlx->bool_A = 0;
	if (key == D_KEY_L)//D
		pmlx->bool_D = 0;
	main_loop(pmlx);
	return(0);
}