/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 09:51:55 by bemoreau          #+#    #+#             */
/*   Updated: 2020/01/29 09:44:08 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*conv_hex_add(unsigned long long int nb, int bool)
{
	char					*str;
	char					*charset;
	unsigned long long int	tmp;
	int						len;

	charset = (bool == 0) ? "0123456789abcdef" : "0123456789ABCDEF";
	tmp = nb;
	len = 0;
	while ((tmp /= 16) != 0)
		len++;
	len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (nb / 16 != 0)
	{
		str[len--] = charset[nb % 16];
		nb = nb / 16;
	}
	str[len] = charset[nb % 16];
	return (str);
}

int			printf_addr(va_list *ap, int *tab)
{
	char	*addr;
	int		len;
	int		tmp;

	if (tab[1] == 0 && tab[7] == 1)
		tab[1] = va_arg(*ap, int);
	addr = conv_hex_add((unsigned long long int)va_arg(*ap, void *), 0);
	tmp = tab[1];
	len = ft_strlen(addr) + 2;
	if (tab[5] == 1)
	{
		ft_putstrr("0x");
		ft_putstrr(addr);
	}
	while (tmp-- > len)
		ft_putchar((tab[6] == 1) ? '0' : ' ');
	if (tab[5] == 0)
	{
		ft_putstrr("0x");
		ft_putstrr(addr);
	}
	free(addr);
	return ((tab[1] > len) ? tab[1] : len);
}

char		*conv_nbr_hex(unsigned int nb, int bool, int prec)
{
	char				*str;
	char				*charset;
	unsigned int		tmp;
	int					len;
	int					diff;

	charset = (bool == 0) ? "0123456789abcdef" : "0123456789ABCDEF";
	tmp = nb;
	len = 1;
	while ((tmp /= 16) != 0)
		len++;
	diff = prec - len;
	len = len + ((diff > 0) ? diff : 0);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (nb / 16 != 0)
	{
		str[len--] = charset[nb % 16];
		nb = nb / 16;
	}
	str[len--] = charset[nb % 16];
	while (len >= 0)
		str[len--] = '0';
	return (str);
}

int			printf_hnbr_l(va_list *ap, int *tab)
{
	char			*str;
	int				len;
	int				tmp;
	unsigned int	nb;

	ft_hex_args(tab, ap);
	nb = (unsigned int)va_arg(*ap, int);
	if (nb == 0 && tab[10] == 1 && tab[2] == 0)
		return (ft_zero(tab[1]));
	str = conv_nbr_hex(nb, 0, tab[2]);
	tmp = tab[1];
	len = ft_strlen(str);
	if (tab[10] == 1 || tab[5] == 1)
		tab[6] = 0;
	if (tab[5] == 1)
		ft_putstrr(str);
	while (tmp-- > len)
		ft_putchar((tab[6] == 1) ? '0' : ' ');
	if (tab[5] == 0)
		ft_putstrr(str);
	free(str);
	return ((tab[1] > len) ? tab[1] : len);
}

int			printf_hnbr_u(va_list *ap, int *tab)
{
	char			*str;
	int				len;
	int				tmp;
	unsigned int	nb;

	ft_hex_args(tab, ap);
	nb = (unsigned int)va_arg(*ap, int);
	if (nb == 0 && tab[10] == 1 && tab[2] == 0)
		return (ft_zero(tab[1]));
	str = conv_nbr_hex(nb, 1, tab[2]);
	tmp = tab[1];
	len = ft_strlen(str);
	if (tab[10] == 1 || tab[5] == 1)
		tab[6] = 0;
	if (tab[5] == 1)
		ft_putstrr(str);
	while (tmp-- > len)
		ft_putchar((tab[6] == 1) ? '0' : ' ');
	if (tab[5] == 0)
		ft_putstrr(str);
	free(str);
	return ((tab[1] > len) ? tab[1] : len);
}
