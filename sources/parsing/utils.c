/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:49 by bemoreau          #+#    #+#             */
/*   Updated: 2020/07/25 13:08:49 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     find_char (char *str, char c)
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

int     tab_len(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        i++;
    }
    return (i);
}

void    store_rgb(t_color *c, int nb, int index)
{
    if(index == 1)
        c->R = nb;
    if(index == 2)
        c->G = nb;
    if(index == 3)
        c->B = nb;                                       
}

void put_rgb(t_color *c, char **tab)
{
    int i;
    int j;
    int nb;

    i = 0;
    j = 0;
    nb = 0;
    while (++j != 4)
    {
        while (tab[1][i + 1] && tab[1][i] != ',' && tab[1][i + 1] != '\n')
        {
            if (tab[1][i] >= '0' && tab[1][i] <= '9')
                nb = nb * 10 + tab[1][i] - '0';
            i++;
        }
        i++;
        store_rgb(c, nb, j);
        nb = 0;
    }
}


int tab_is_rgb(char **tab)
{
    int i;
    int j;
    int nb;

    i = 0;
    j = 0;
    nb = 0;
    while (j++ != 3)
    {
        while (tab[1][i + 1] && tab[1][i] != ',' && tab[1][i + 1] != '\n')
        {
            if (tab[1][i] >= '0' && tab[1][i] <= '9')
                nb = nb * 10 + tab[1][i] - '0';
            else
                return (0);
            i++;
        }
        i++;
        if (nb < 0 || nb > 255)
            return (0);
        nb = 0;
    }
    return (1);
}

int tab_is_digit(char **tab)
{
    int y;
    int i;

    y = 0;
    i = 0;
    while (tab[++y])
    {
        while (tab[i])
        {
            if (!(tab[y][i] >= '0' && tab[y][i] <= '9'))
                return (0);
            i++;
        }
    }
    return (1);
}
