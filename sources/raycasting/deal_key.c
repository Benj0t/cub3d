/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:49:55 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/03 16:37:44 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key_leave(int key, t_pmlx *pmlx)
{
	ray_err("Leaving program", pmlx);
	return (0);
}

int		deal_key_press(int key, t_pmlx *pmlx)
{
	if (key == ESC_KEY_L)
		ray_err("Leaving program", pmlx);
	if (key == W_KEY_L)
		pmlx->b.bool_w = 1;
	if (key == S_KEY_L)
		pmlx->b.bool_s = 1;
	if (key == 65361)
		pmlx->b.bool_l = 1;
	if (key == 65363)
		pmlx->b.bool_r = 1;
	if (key == A_KEY_L)
		pmlx->b.bool_a = 1;
	if (key == D_KEY_L)
		pmlx->b.bool_d = 1;
	main_loop(pmlx);
	return (0);
}

int		deal_key_release(int key, t_pmlx *pmlx)
{
	if (key == ESC_KEY_L)
		ray_err("Leaving program", pmlx);
	if (key == W_KEY_L)
		pmlx->b.bool_w = 0;
	if (key == S_KEY_L)
		pmlx->b.bool_s = 0;
	if (key == 65361)
		pmlx->b.bool_l = 0;
	if (key == 65363)
		pmlx->b.bool_r = 0;
	if (key == A_KEY_L)
		pmlx->b.bool_a = 0;
	if (key == D_KEY_L)
		pmlx->b.bool_d = 0;
	main_loop(pmlx);
	return (0);
}
