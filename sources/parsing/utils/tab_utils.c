/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 12:58:53 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/03 16:24:18 by bemoreau         ###   ########.fr       */
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

void	free_itab(int **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
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
