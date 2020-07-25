#include "cub3d.h"

void    init_texture(t_pmlx *pmlx)
{
    int i;

    pmlx->img.bpp = 0;
    pmlx->img.s_line = 0;
    pmlx->img.endian = 0;
    if (!(pmlx->img.image = (char **)malloc(sizeof(char *) * (10))))
        return;
    if (!(pmlx->img.addr = (void **)malloc(sizeof(void *) * (10))))
        return;
    pmlx->img.image[9] = NULL;
    pmlx->img.addr[9] = NULL;
    pmlx->img.addr[0] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, "./images/wood.xpm", &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[1] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, "./images/greystone.xpm", &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[2] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, "./images/redbrick.xpm", &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[3] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, "./images/eagle.xpm", &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[4] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, "./images/colorstone.xpm", &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[5] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, "./images/tonneau.xpm", &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[6] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, "./images/potal.xpm", &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[7] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, "./images/lamp.xpm", &(pmlx->img.img_W), &(pmlx->img.img_H));
    pmlx->img.addr[8] = mlx_xpm_file_to_image(pmlx->mlx.mlx_ptr, "./images/mv.xpm", &(pmlx->img.img_W), &(pmlx->img.img_H));
    i = 0;
    while (i < 9)
    {
        pmlx->img.image[i] = mlx_get_data_addr(pmlx->img.addr[i], &(pmlx->img.bpp), &(pmlx->img.s_line), &(pmlx->img.endian));
        i++;
    }
}