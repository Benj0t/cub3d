/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:49:36 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/02 18:02:21 by bemoreau         ###   ########.fr       */
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

void	ft_destroy(t_pmlx *pmlx)
{
	int i;

	i = 0;
	while (pmlx->img.addr[i])
	{
		free(pmlx->img.addr[i]);
		free(pmlx->img.image[i++]);
	}
	free(pmlx->img.addr);
	free(pmlx->img.image);
	mlx_destroy_image(pmlx->mlx.mlx_ptr, pmlx->mlx.img_ptr);
	mlx_destroy_window(pmlx->mlx.mlx_ptr, pmlx->mlx.win_ptr);
	i = -1;
	int j = 0;
}

void	err_raycast(t_pmlx *pmlx)
{
	return ;
}

void	ray_err(char *str, t_pmlx *pmlx)
{
	ft_putendl(str);
	err_parsing(pmlx);
	err_raycast(pmlx);
	ft_destroy(pmlx);
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
	(pmlx->s.cmap) ? free_tab(pmlx->s.cmap) : 0;
	(pmlx->s.map) ? free_itab(pmlx->s.map) : 0;
	(pmlx->s.C) ? free(pmlx->s.C) : 0;
	(pmlx->sp.spriteDistance) ? free(pmlx->sp.spriteDistance) : 0;
	(pmlx->sp.spriteOrder) ? free(pmlx->sp.spriteOrder) : 0;
}

void	ft_puterr(char *str, t_pmlx *pmlx)
{
	ft_putendl(str);
	err_parsing(pmlx);
	exit(1);
}
