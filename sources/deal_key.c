/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:49:55 by bemoreau          #+#    #+#             */
/*   Updated: 2020/06/25 19:17:33 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		deal_key_press(int key, t_pmlx *pmlx)
{
	printf("%d\n", key);
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
	printf("%d\n", key);
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