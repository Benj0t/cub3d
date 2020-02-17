/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:58:42 by bemoreau          #+#    #+#             */
/*   Updated: 2020/02/03 23:56:49 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_charset(char c)
{
	int		i;
	char	*charset;

	charset = "cspdiuxX%";
	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (i);
	return (-1);
}

int		ft_intlen_u(unsigned int nb)
{
	int i;

	i = 1;
	while (nb / 10 != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int		ft_intlen(int nb)
{
	int i;

	i = (nb < 0) ? 2 : 1;
	while (nb / 10 != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int		ft_isdigit(int ch)
{
	if (ch <= 57 && ch >= 48)
		return (1);
	return (0);
}

int		ft_atoi(char *str, int *i)
{
	int nb;
	int neg;

	nb = 0;
	if (str[*i] == '*')
	{
		*i = *i + 1;
		return (0);
	}
	while ((str[*i] <= 13 && str[*i] >= 9) || str[*i] == 32)
		*i = *i + 1;
	neg = (str[*i] == '-') ? 1 : 0;
	if (str[*i] == '-' || str[*i] == '+')
		*i = *i + 1;
	while (ft_isdigit(str[*i]))
	{
		nb = nb * 10 + (str[*i] - 48);
		*i = *i + 1;
	}
	*i = *i - 1;
	return ((neg == 1) ? -nb : nb);
}
