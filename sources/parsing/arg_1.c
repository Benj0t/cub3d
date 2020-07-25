/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:34 by bemoreau          #+#    #+#             */
/*   Updated: 2020/07/25 13:08:34 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    store_res(t_pmlx *pmlx)
{
    if ((!tab_is_digit(pmlx->s.tab)) || tab_len(pmlx->s.tab) != 3)
        return (0);
    pmlx->s.R.x = ft_atoi(pmlx->s.tab[1]);
    pmlx->s.R.y = ft_atoi(pmlx->s.tab[2]);
    return (1);
}

int    store_f(t_pmlx *pmlx)
{
    if ((!tab_is_rgb(pmlx->s.tab)) || tab_len(pmlx->s.tab) != 2)
        return (0);
    put_rgb(&(pmlx->s.floor), pmlx->s.tab);
    return (1);
}

int    store_c(t_pmlx *pmlx)
{
    if ((!tab_is_rgb(pmlx->s.tab)) || tab_len(pmlx->s.tab) != 2)
        return (0);
    put_rgb(&(pmlx->s.ceil), pmlx->s.tab);
    return (1);
}
