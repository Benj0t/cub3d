/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:49:36 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/04 12:17:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_void(void **par)
{
	int i;

	i = 0;
	while (par[i])
		free(par[i++]);
	free(par);
}

void	ft_destroy(t_pmlx *pmlx)
{
	free_void(pmlx->img.addr);
	mlx_destroy_image(pmlx->mlx.mlx_ptr, pmlx->mlx.img_ptr);
	mlx_destroy_window(pmlx->mlx.mlx_ptr, pmlx->mlx.win_ptr);
}

void	ray_err(char *str, t_pmlx *pmlx)
{
	ft_putendl(str);
	err_parsing(pmlx);
	ft_putendl("O s k o u r");
	ft_destroy(pmlx);
	exit(1);
}

void	err_parsing(t_pmlx *pmlx)
{
	ft_putendl("O s k o u r");
	pmlx->s.list = NULL;
	(pmlx->s.list) ? free(pmlx->s.list) : 0;
	ft_putendl("O s k o u r");
	(pmlx->s.no) ? free(pmlx->s.no) : 0;
	(pmlx->s.so) ? free(pmlx->s.so) : 0;
	(pmlx->s.we) ? free(pmlx->s.we) : 0;
	(pmlx->s.ea) ? free(pmlx->s.ea) : 0;
	(pmlx->s.s) ? free(pmlx->s.s) : 0;
	(pmlx->s.line) ? free(pmlx->s.line) : 0;
	(pmlx->s.tmp) ? free(pmlx->s.tmp) : 0;
	(pmlx->s.map_join) ? free(pmlx->s.map_join) : 0;
	ft_putendl("O s k o u r1");
	(pmlx->s.cmap) ? free_tab(pmlx->s.cmap) : 0;
	ft_putendl("O s k o u r2");
	(pmlx->s.map) ? free_itab(pmlx->s.map) : 0;
	ft_putendl("O s k o u r3");
	(pmlx->s.c) ? free(pmlx->s.c) : 0;
	(pmlx->sp.sprite_distance) ? free(pmlx->sp.sprite_distance) : 0;
	(pmlx->sp.sprite_order) ? free(pmlx->sp.sprite_order) : 0;
}

void	ft_puterr(char *str, t_pmlx *pmlx)
{
	ft_putendl(str);
	err_parsing(pmlx);
	exit(1);
}
