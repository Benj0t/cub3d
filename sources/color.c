/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 15:48:12 by bemoreau          #+#    #+#             */
/*   Updated: 2020/06/25 18:54:14 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// /!\ 6 functions

t_color ft_color_divide(t_color color)
{
	t_color new;
	new.R = (color.R) ? color.R / 2 : color.R;
	new.G = (color.G) ? color.G / 2 : color.G;
	new.B = (color.B) ? color.B / 2 : color.B;
	return (new);
}

t_color	ft_light_blue()
{
	t_color color;

	color.R = 53;
	color.G = 155;
	color.B = 255;
	return (color);
}

t_color	ft_gray()
{
	t_color color;

	color.R = 128;
	color.G = 128;
	color.B = 128;
	return (color);
}

t_color	ft_red()
{
	t_color color;

	color.R = 255;
	color.G = 0;
	color.B = 0;
	return (color);
}

t_color	ft_green()
{
	t_color color;

	color.R = 0;
	color.G = 255;
	color.B = 0;
	return (color);
}

t_color	ft_blue()
{
	t_color color;

	color.R = 0;
	color.G = 0;
	color.B = 255;
	return (color);
}

t_color	ft_white()
{
	t_color color;

	color.R = 255;
	color.G = 255;
	color.B = 255;
	return (color);
}

t_color	ft_yellow()
{
	t_color color;

	color.R = 255;
	color.G = 255;
	color.B = 0;
	return (color);
}

t_color	ft_dark()
{
	t_color color;

	color.R = 0;
	color.G = 0;
	color.B = 0;
	return (color);
}