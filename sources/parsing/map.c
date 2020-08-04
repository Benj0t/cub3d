/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:20 by bemoreau          #+#    #+#             */
/*   Updated: 2020/07/25 13:08:20 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int     count_n(char *str)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (str[i])
        if (str[i++] == '\n')
            n++;
    return (n);
}

int     create_map(t_pmlx *pmlx)
{
    int n;
    int i;
    int j;
    int start;
    int len;

    i = -1;
    j = 0;
    start = 0;
    n = count_n(pmlx->s.map_join);
    if (!(pmlx->s.cmap = (char **)malloc(sizeof(char *) * (n + 1))))
        return (0);
    pmlx->s.cmap[n] = NULL;
    while (j < n)
    {
        start = ++i;
        while (pmlx->s.map_join[i] != '\n' || pmlx->s.map_join[i] == '\r')
            i++;
        len = i - start;
        pmlx->s.cmap[j++] = ft_substr(pmlx->s.map_join, start, len);
    }
    return (1);
}