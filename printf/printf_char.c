/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:05:07 by bemoreau          #+#    #+#             */
/*   Updated: 2020/01/28 20:27:16 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		printf_char(va_list *ap, int *tab)
{
	char	c;
	int		i;

	if (tab[7] == 1)
		if ((tab[1] = va_arg(*ap, int)) < 0)
		{
			tab[1] = -tab[1];
			tab[5] = 1;
		}
	c = va_arg(*ap, int);
	i = 0;
	if (tab[1] > 0)
	{
		if (tab[5] == 1)
			write(1, &c, 1);
		while (++i < tab[1])
			write(1, (tab[6] == 1) ? "0" : " ", 1);
		if (tab[5] == 0)
			write(1, &c, 1);
	}
	else
		ft_putchar(c);
	return ((tab[1] > 0) ? tab[1] : 1);
}

int		printf_str(va_list *ap, int *tab)
{
	int		len;
	char	*var;

	ft_str_args(tab, ap);
	var = va_arg(*ap, char *);
	if (var == NULL)
		var = "(null)";
	if (tab[11] == 1)
		tab[2] = ft_strlen(var);
	if (var && ((tab[2] > 0) || (tab[2] == 0 && tab[10] == 1)))
		var = ft_substr(var, 0, tab[2]);
	len = (var) ? ft_strlen(var) : 0;
	if (var && tab[5] == 1)
		ft_putstrr(var);
	while (tab[1] > len++)
		ft_putchar((tab[6] == 1) ? '0' : ' ');
	len--;
	if (var && tab[5] == 0)
		ft_putstrr(var);
	if (var && tab[2] > 0)
		free(var);
	return (len);
}

int		printf_pourc(va_list *ap, int *tab)
{
	int len;

	if (tab[7] == 1)
		if ((tab[1] = va_arg(*ap, int)) < 0)
		{
			tab[1] = -tab[1];
			tab[5] = 1;
		}
	if (tab[8] == 1)
		if ((tab[2] = va_arg(*ap, int)) < 0)
			tab[2] = -tab[2];
	len = tab[1];
	if (tab[5] == 1)
		ft_putchar('%');
	while (--len > 0)
		ft_putchar((tab[6] == 1) ? '0' : ' ');
	if (tab[5] == 0)
		ft_putchar('%');
	return ((tab[1] > 0) ? tab[1] : 1);
}
