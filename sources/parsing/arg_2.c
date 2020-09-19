/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:38 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/20 00:54:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	store_no(t_pmlx *pmlx)
{
	int fd;

	if (((tab_len(pmlx->s.tab)) != 2) ||\
		(fd = open(pmlx->s.tab[1], O_RDONLY)) <= 0 ||\
		(ext_check(pmlx->s.tab[1], ".xpm") != 0))
		return (0);
	if ((pmlx->s.no = ft_strdup(pmlx->s.tab[1])) == NULL)
		ft_puterr("Error", pmlx, 1);
	close(fd);
	pmlx->s.n_key++;
	return (1);
}

int	store_so(t_pmlx *pmlx)
{
	int fd;

	if (((tab_len(pmlx->s.tab)) != 2) ||\
		(fd = open(pmlx->s.tab[1], O_RDONLY)) <= 0 ||\
		(ext_check(pmlx->s.tab[1], ".xpm") != 0))
		return (0);
	if ((pmlx->s.so = ft_strdup(pmlx->s.tab[1])) == NULL)
		ft_puterr("Error", pmlx, 1);
	close(fd);
	pmlx->s.n_key++;
	return (1);
}

int	store_we(t_pmlx *pmlx)
{
	int fd;

	if (((tab_len(pmlx->s.tab)) != 2) ||\
		(fd = open(pmlx->s.tab[1], O_RDONLY)) <= 0 ||\
		(ext_check(pmlx->s.tab[1], ".xpm") != 0))
		return (0);
	if ((pmlx->s.we = ft_strdup(pmlx->s.tab[1])) == NULL)
		ft_puterr("Error", pmlx, 1);
	close(fd);
	pmlx->s.n_key++;
	return (1);
}

int	store_ea(t_pmlx *pmlx)
{
	int fd;

	if (((tab_len(pmlx->s.tab)) != 2) ||\
		(fd = open(pmlx->s.tab[1], O_RDONLY)) <= 0 ||\
		(ext_check(pmlx->s.tab[1], ".xpm") != 0))
		return (0);
	if ((pmlx->s.ea = ft_strdup(pmlx->s.tab[1])) == NULL)
		ft_puterr("Error", pmlx, 1);
	close(fd);
	pmlx->s.n_key++;
	return (1);
}

int	store_s(t_pmlx *pmlx)
{
	int fd;

	if (((tab_len(pmlx->s.tab)) != 2) ||\
		(fd = open(pmlx->s.tab[1], O_RDONLY)) <= 0 ||\
		(ext_check(pmlx->s.tab[1], ".xpm") != 0))
		return (0);
	if ((pmlx->s.s = ft_strdup(pmlx->s.tab[1])) == NULL)
		ft_puterr("Error", pmlx, 1);
	close(fd);
	pmlx->s.n_key++;
	return (1);
}
