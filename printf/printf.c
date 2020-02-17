/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:23:04 by bemoreau          #+#    #+#             */
/*   Updated: 2020/01/28 21:58:19 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	func_init(int (*func_ptr[10])(va_list *ap, int *tab))
{
	func_ptr[0] = &printf_char;
	func_ptr[1] = &printf_str;
	func_ptr[2] = &printf_addr;
	func_ptr[3] = &printf_nbr;
	func_ptr[4] = &printf_nbr;
	func_ptr[5] = &printf_unbr;
	func_ptr[6] = &printf_hnbr_l;
	func_ptr[7] = &printf_hnbr_u;
	func_ptr[8] = &printf_pourc;
}

static int	ft_free_tab(int **tab, va_list *ap, int len)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	va_end(*ap);
	return (len);
}

static int	print_all(char *str, int **tab, va_list *ap)
{
	int i;
	int j;
	int tlen;
	int len;
	int (*func_ptr[10])(va_list *ap, int *tab);

	func_init(func_ptr);
	j = 0;
	i = 0;
	len = 0;
	tlen = count_args(str);
	while (str[i] && tlen != 0)
	{
		while ((j < tlen) && (str[i]) && (i < tab[j][3]))
			len += ft_putchar(str[i++]);
		if (j < tlen)
			len += (int)func_ptr[tab[j][0]](ap, tab[j]);
		i = tab[j++][4] + 1;
		while (j >= tlen && str[i])
			len += ft_putchar(str[i++]);
	}
	while (str[i] && tlen == 0)
		len += ft_putchar(str[i++]);
	return (ft_free_tab(tab, ap, len));
}

int			ft_printf(char *const format, ...)
{
	va_list	ap;
	int		**list;

	va_start(ap, format);
	list = init_tab(format);
	det_args(format, &list);
	return (print_all(format, list, &ap));
}
