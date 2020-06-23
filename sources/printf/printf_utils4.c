/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:29:57 by bemoreau          #+#    #+#             */
/*   Updated: 2020/01/28 21:02:10 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_str_args(int *tab, va_list *ap)
{
	if (tab[7] == 1)
	{
		if ((tab[1] = va_arg(*ap, int)) < 0)
		{
			tab[1] = -tab[1];
			tab[5] = 1;
		}
	}
	if (tab[8] == 1)
	{
		if ((tab[2] = va_arg(*ap, int)) < 0)
			tab[11] = 1;
	}
}

void	ft_hex_args(int *tab, va_list *ap)
{
	if (tab[7] == 1)
	{
		if ((tab[1] = va_arg(*ap, int)) < 0)
		{
			tab[1] = -tab[1];
			tab[5] = 1;
		}
	}
	if (tab[8] == 1)
	{
		if ((tab[2] = va_arg(*ap, int)) < 0)
		{
			tab[10] = 0;
			tab[2] = 1;
		}
	}
}

void	ft_nbr_args(int *tab, va_list *ap)
{
	if (tab[7] == 1)
	{
		if ((tab[1] = va_arg(*ap, int)) < 0)
		{
			tab[1] = -tab[1];
			tab[5] = 1;
		}
	}
	if (tab[8] == 1)
	{
		if ((tab[2] = va_arg(*ap, int)) < 0)
		{
			tab[10] = 0;
			tab[2] = 1;
		}
	}
}

void	ft_unbr_args(int *tab, va_list *ap)
{
	if (tab[7] == 1)
	{
		if ((tab[1] = va_arg(*ap, int)) < 0)
		{
			tab[1] = -tab[1];
			tab[5] = 1;
		}
	}
	if (tab[8] == 1)
	{
		if ((tab[2] = va_arg(*ap, int)) < 0)
		{
			tab[10] = 0;
			tab[2] = 1;
		}
	}
}

int		ft_zero(int larg)
{
	int i;

	i = 0;
	while (larg > 0 && ++i <= larg)
		ft_putchar(' ');
	return (larg);
}
