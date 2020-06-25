/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:28:21 by bemoreau          #+#    #+#             */
/*   Updated: 2020/02/04 01:09:48 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_len_f(char *str, int *i, int *tab)
{
	if (str[*i] == '0')
		tab[6] = 1;
	if (str[*i] == '-')
		tab[5] = 1;
	if (str[*i] == '*')
		tab[7] = 1;
	if (ft_isdigit(str[*i]))
		tab[1] = ft_atoi(str, i);
	*i = *i + 1;
}

void	ft_prec_f(char *str, int *i, int *tab)
{
	if (str[*i] == '*')
		tab[8] = 1;
	if (ft_isdigit(str[*i]))
		tab[2] = ft_atoi(str, i);
	*i = *i + 1;
}

char	*ft_nzero(void)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	str[0] = '\0';
	return (str);
}
