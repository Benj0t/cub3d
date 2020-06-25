/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:23:28 by bemoreau          #+#    #+#             */
/*   Updated: 2020/01/28 21:50:26 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_if_minus(int *tab, int *bool, int nb, char *str)
{
	if (tab[5] == 1)
	{
		if (nb < 0)
		{
			*bool = 1;
			ft_putchar('-');
		}
		ft_putstrr(str);
	}
}

void	ft_ifnot_minus(int *tab, int bool, int nb, char *str)
{
	if (tab[5] == 0)
	{
		if (nb < 0 && bool == 0)
			ft_putchar('-');
		ft_putstrr(str);
	}
}
