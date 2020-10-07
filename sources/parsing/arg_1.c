/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:12:23 by bemoreau          #+#    #+#             */
/*   Updated: 2020/10/07 18:13:48 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	store_res(t_pmlx *pmlx)
{
	long long int x;
	long long int y;

	if (pmlx->s.r_key++ != 0)
		ft_puterr("Error\nKey encountered twice", pmlx, 1);
	if (tab_len(pmlx->s.tab) != 3 || (!tab_is_digit(pmlx->s.tab)))
		return (0);
	x = ft_atoll(pmlx->s.tab[1]);
	y = ft_atoll(pmlx->s.tab[2]);
	pmlx->s.r.x = (x > 2147483647) ? 2147483647 : x;
	pmlx->s.r.y = (y > 2147483647) ? 2147483647 : y;
	if (pmlx->s.r.x <= 0 || pmlx->s.r.y <= 0)
		return (0);
	pmlx->s.n_key++;
	return (1);
}

int	store_f(t_pmlx *pmlx)
{
	if (pmlx->s.f_key++ != 0)
		ft_puterr("Error\nKey encountered twice", pmlx, 1);
	if (tab_len(pmlx->s.tab) != 2 || (!tab_is_rgb(pmlx->s.tab)))
		return (0);
	put_rgb(&(pmlx->s.floor), pmlx->s.tab);
	pmlx->s.n_key++;
	return (1);
}

int	store_c(t_pmlx *pmlx)
{
	if (pmlx->s.c_key++ != 0)
		ft_puterr("Error\nKey encountered twice", pmlx, 1);
	if (tab_len(pmlx->s.tab) != 2 || (!tab_is_rgb(pmlx->s.tab)))
		return (0);
	put_rgb(&(pmlx->s.ceil), pmlx->s.tab);
	pmlx->s.n_key++;
	return (1);
}
