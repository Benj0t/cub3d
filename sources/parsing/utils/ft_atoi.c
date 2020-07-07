/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:38:11 by bemoreau          #+#    #+#             */
/*   Updated: 2020/02/14 17:55:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static	int		ft_isdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

static	int		ft_iswhspaces(int ch)
{
	if ((ch <= 13 && ch >= 9) || ch == 32)
		return (1);
	return (0);
}

int				ft_atoi(char *str)
{
	int i;
	int nb;
	int neg;

	i = 0;
	nb = 0;
	while (ft_iswhspaces(str[i]))
		i++;
	neg = (str[i] == '-') ? 1 : 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		nb = nb * 10 + (str[i++] - 48);
	return ((neg == 1) ? -nb : nb);
}
