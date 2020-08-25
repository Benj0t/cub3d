/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:38 by bemoreau          #+#    #+#             */
/*   Updated: 2020/07/25 13:08:38 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    store_no(t_pmlx *pmlx)
{
    int fd;;

    if (((tab_len(pmlx->s.tab)) != 2) || (fd = open(pmlx->s.tab[1], O_RDONLY)) <= 0)
        return (0);
    pmlx->s.NO = ft_strdup(pmlx->s.tab[1]);
    close(fd);
    return (1);
}

int    store_so(t_pmlx *pmlx)
{
    int fd;

    if (((tab_len(pmlx->s.tab)) != 2) || (fd = open(pmlx->s.tab[1], O_RDONLY)) < 0)
        return (0);
    pmlx->s.SO = ft_strdup(pmlx->s.tab[1]);
    close(fd);
    return (1);
}

int    store_we(t_pmlx *pmlx)
{
    int fd;

    if (((tab_len(pmlx->s.tab)) != 2) || (fd = open(pmlx->s.tab[1], O_RDONLY)) < 0)
        return (0);
    pmlx->s.WE = ft_strdup(pmlx->s.tab[1]);
    close(fd);
    return (1);
}

int    store_ea(t_pmlx *pmlx)
{
    int fd;

    if (((tab_len(pmlx->s.tab)) != 2) || (fd = open(pmlx->s.tab[1], O_RDONLY)) < 0)
        return (0);
    pmlx->s.EA = ft_strdup(pmlx->s.tab[1]);
    close(fd);
    return (1);
}

int    store_s(t_pmlx *pmlx)
{
    int fd;

    if (((tab_len(pmlx->s.tab)) != 2) || (fd = open(pmlx->s.tab[1], O_RDONLY)) < 0)
        return (0);
    pmlx->s.S = ft_strdup(pmlx->s.tab[1]);
    close(fd);
    return (1);
}