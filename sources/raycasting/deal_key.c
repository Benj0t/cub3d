/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:49:55 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/26 14:45:44 by bemoreau         ###   ########.fr       */
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

int		deal_key_leave(int key, t_pmlx *pmlx)
{
	err_raycast(pmlx);
	exit(1);
	return (0);
}

int		deal_key_press(int key, t_pmlx *pmlx)
{
	if (key == ESC_KEY_M)
		pmlx->bool_ESC = 1;
	if (key == W_KEY_M)//W
		pmlx->bool_W = 1;
	if (key == S_KEY_M)//S
		pmlx->bool_S = 1;
	if (key == A_KEY_M)//A
		pmlx->bool_A = 1;
	if (key == D_KEY_M)//D
		pmlx->bool_D = 1;
	main_loop(pmlx);
	return(0);
}

int		deal_key_release(int key, t_pmlx *pmlx)
{
	if (key == ESC_KEY_M)
		ft_destroy(pmlx);
	if (key == W_KEY_M)//W
		pmlx->bool_W = 0;
	if (key == S_KEY_M)//S
		pmlx->bool_S = 0;
	if (key == A_KEY_M)//A
		pmlx->bool_A = 0;
	if (key == D_KEY_M)//D
		pmlx->bool_D = 0;
	main_loop(pmlx);
	return(0);
}