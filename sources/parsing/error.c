/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:49:36 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/28 14:52:10 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	err_raycast(t_pmlx *pmlx)
{
	return ;
}

void	ray_err(char *str, t_pmlx *pmlx)
{
	ft_putendl(str);
	err_raycast(pmlx);
	exit(1);
}

void	err_parsing(t_pmlx *pmlx)
{
	(pmlx->s.list) ? free(pmlx->s.list) : 0;
	(pmlx->s.NO) ? free(pmlx->s.NO) : 0;
	(pmlx->s.SO) ? free(pmlx->s.SO) : 0;
	(pmlx->s.WE) ? free(pmlx->s.WE) : 0;
	(pmlx->s.EA) ? free(pmlx->s.EA) : 0;
	(pmlx->s.S) ? free(pmlx->s.S) : 0;
	(pmlx->s.line) ? free(pmlx->s.line) : 0;
	(pmlx->s.tmp) ? free(pmlx->s.tmp) : 0;
	(pmlx->s.map_join) ? free(pmlx->s.map_join) : 0;
	(pmlx->s.cmap) ? free(pmlx->s.cmap) : 0;
	(pmlx->s.map) ? free(pmlx->s.map) : 0;
	(pmlx->s.C) ? free(pmlx->s.C) : 0;
	(pmlx->sp.spriteDistance) ? free(pmlx->sp.spriteDistance) : 0;
	(pmlx->sp.spriteOrder) ? free(pmlx->sp.spriteOrder) : 0;
	(pmlx->img.addr) ? free(pmlx->img.addr) : 0;
	(pmlx->img.image) ? free(pmlx->img.image) : 0;
	(pmlx->mlx.img_ptr) ? free(pmlx->mlx.img_ptr) : 0;
	(pmlx->mlx.win_ptr) ? free(pmlx->mlx.win_ptr) : 0;
	(pmlx->mlx.data_addr) ? free(pmlx->mlx.data_addr) : 0;
}

void	ft_puterr(char *str, t_pmlx *pmlx)
{
	ft_putendl(str);
	err_parsing(pmlx);
	exit(1);
}
