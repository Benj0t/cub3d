/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:00:59 by bemoreau          #+#    #+#             */
/*   Updated: 2020/01/28 22:03:20 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_flags(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = " -.*0123456789";
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int			count_args(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] && (ft_flags(str[i]) == 1))
				i++;
			if (str[i] && ft_charset(str[i--]) >= 0)
			{
				nb++;
				if (ft_charset(str[i + 1] == 8))
					i++;
			}
		}
		i++;
	}
	return (nb);
}

int			**init_tab(char *str)
{
	int **tab;
	int tlen;
	int pos;
	int pos2;

	pos = 0;
	tlen = count_args(str);
	if (!(tab = (int **)malloc(sizeof(int *) * (tlen + 1))))
		return (NULL);
	tab[tlen] = NULL;
	while (pos < tlen)
	{
		pos2 = 0;
		tab[pos] = (int *)malloc(sizeof(int) * 13);
		while (pos2 < 12)
			tab[pos][pos2++] = 0;
		tab[pos++][pos2] = '\0';
	}
	return (tab);
}

int			findarg(char *str, int *i, int *tab)
{
	int j;

	j = *i;
	tab[3] = *i;
	*i = *i + 1;
	while (str[*i] && str[*i] != '.' && (ft_charset(str[*i]) < 0))
		ft_len_f(str, i, tab);
	if (str[*i] == '.')
		tab[10] = 1;
	while (str[*i] && (ft_charset(str[*i]) < 0) && tab[10] == 1)
		ft_prec_f(str, i, tab);
	if (ft_charset(str[*i]) >= 0)
	{
		tab[4] = *i;
		tab[0] = ft_charset(str[*i]);
	}
	if (tab[5] == 1)
		tab[6] = 0;
	return (ft_charset(str[*i]));
}

void		det_args(char *str, int ***tab)
{
	int i;
	int pos;
	int tlen;
	int *tmp;

	i = -1;
	pos = 0;
	tlen = count_args(str);
	tmp = NULL;
	pos = 0;
	while (str[++i] && pos < tlen)
		if (str[i] == '%')
		{
			findarg(str, &i, tab[0][pos]);
			pos++;
		}
}
