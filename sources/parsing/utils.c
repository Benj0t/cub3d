/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:49 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/27 16:04:19 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		find_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}

int		tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

int		tab_is_digit(char **tab)
{
	int y;
	int i;

	y = 0;
	i = 0;
	while (tab[++y])
	{
		while (tab[y][i])
		{
			if (!(tab[y][i] >= '0' && tab[y][i] <= '9'))
				return (0);
			i++;
		}
	}
	return (1);
}
