/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:47:29 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/20 00:55:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putendl_fd(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(fd, &(str[i++]), 1);
	}
	write(fd, "\n", 1);
}

void	ft_putendl(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &(str[i++]), 1);
	write(1, "\n", 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &(str[i++]), 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
