/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:04:25 by bemoreau          #+#    #+#             */
/*   Updated: 2020/02/04 01:09:30 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_prec(int nb, int prec, int check, int len)
{
	int					i;
	char				*str;
	unsigned int		nbr;

	i = 0;
	nbr = (nb < 0) ? -nb : nb;
	if (prec == 0 && check == 1 && nbr == 0)
		return (ft_nzero());
	while (len < prec--)
		i++;
	len = len + i;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (i >= 0)
		str[i--] = '0';
	if (nbr == 0)
		str[--len] = '0';
	while (nbr != 0)
	{
		str[--len] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}

int			printf_nbr(va_list *ap, int *tab)
{
	char	*str;
	int		len;
	int		tmp;
	int		nb;
	int		bool;

	bool = 0;
	ft_nbr_args(tab, ap);
	nb = va_arg(*ap, int);
	str = ft_prec(nb, tab[2], tab[10], ft_intlen_u((nb < 0) ? -nb : nb));
	len = ft_strlen(str) + ((nb < 0) ? 1 : 0);
	tmp = tab[1];
	ft_if_minus(tab, &bool, nb, str);
	if (tab[10] == 1 || tab[5] == 1)
		tab[6] = 0;
	if (nb < 0 && tab[5] == 0 && tab[6] == 1)
	{
		bool = 1;
		ft_putchar('-');
	}
	while (len < tmp--)
		ft_putchar((tab[6] == 1) ? '0' : ' ');
	ft_ifnot_minus(tab, bool, nb, str);
	free(str);
	return ((len > tab[1]) ? len : tab[1]);
}

static char	*ft_prec_u(unsigned int nb, int prec, int check)
{
	int		i;
	int		len;
	char	*str;
	int		index;

	index = 0;
	len = ft_intlen_u(nb);
	i = 0;
	if (prec == 0 && check == 1 && nb == 0)
		return (ft_nzero());
	while (len < prec--)
		i++;
	len = len + i;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (i-- >= 0)
		str[index++] = '0';
	while (nb != 0)
	{
		str[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}

int			printf_unbr(va_list *ap, int *tab)
{
	char	*str;
	int		len;
	int		tmp;

	ft_unbr_args(tab, ap);
	str = ft_prec_u(va_arg(*ap, unsigned int), tab[2], tab[10]);
	len = ft_strlen(str);
	tmp = tab[1];
	if (tab[5] == 1)
		ft_putstrr(str);
	if (tab[10] == 1 || tab[5] == 1)
		tab[6] = 0;
	while (len < tmp--)
		ft_putchar((tab[6] == 1) ? '0' : ' ');
	if (tab[5] == 0)
		ft_putstrr(str);
	free(str);
	return ((len > tab[1]) ? len : tab[1]);
}
