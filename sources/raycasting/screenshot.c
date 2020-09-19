/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:53:01 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/20 01:13:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		bmp_header(t_pmlx *pmlx, int fd)
{
	t_bmp	head;
	int		i;

	i = 0;
	head.size = (4 * pmlx->s.r.x * pmlx->s.r.y);
	head.reserved = 0;
	head.offset_bits = 54;
	head.header_bytes = 40;
	head.planes = 1;
	write(fd, "BM", 2);
	write(fd, &head.size, 4);
	write(fd, &head.reserved, 4);
	write(fd, &head.offset_bits, 4);
	write(fd, &head.header_bytes, 4);
	write(fd, &pmlx->s.r.x, 4);
	write(fd, &pmlx->s.r.y, 4);
	write(fd, &head.planes, 2);
	write(fd, &pmlx->mlx.bpp, 2);
	while (i++ < 6)
		write(fd, &head.reserved, 4);
	return (0);
}

int		bmp_body(t_pmlx *pmlx, int fd)
{
	int		col;
	int		line;
	int		i_towrite;

	line = pmlx->s.r.y - 1;
	i_towrite = 0;
	while (line >= 0)
	{
		col = 0;
		while (col < pmlx->s.r.x)
		{
			i_towrite = (line * pmlx->s.r.x + col) * 4;
			write(fd, &pmlx->mlx.data_addr[i_towrite], 4);
			col++;
		}
		line--;
	}
	return (0);
}

int		screenshot(t_pmlx *pmlx)
{
	int fd;

	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ray_err("Error", pmlx, 1);
	if (bmp_header(pmlx, fd))
		ray_err("Error", pmlx, 1);
	if (bmp_body(pmlx, fd))
		ray_err("Error", pmlx, 1);
	close(fd);
	return (0);
}
