#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
//#include "utils/gnl/get_next_line.h"
//#include "utils/printf/libftprintf.h"
#include "mlx.h"

#define RED_COMP 2
#define GREEN_COMP 1
#define BLUE_COMP 0
#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24
#define RGB_RED 16711680
#define RGB_GREEN 65280
#define RGB_BLUE 255
#define RGB_WHITE 16777215
#define RGB_YELLOW 16776960

typedef struct  s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		endian;
	int		bpp;
	int		size_l;
}				t_mlx;

typedef struct s_ray
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		hit;
	int		side; //was a NS or a EW wall ray.hit?
}				t_ray;

typedef struct s_draw
{
	int		lineHeight;
	int		Start;
	int		End;
}				t_draw;

typedef struct s_player
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		stepX;
	double		stepY;
	int		mapX;
	int		mapY;
}				t_player;

typedef struct s_color
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char A;
}				t_color;

t_color	ft_light_blue();
t_color	ft_gray();
t_color	ft_red();
t_color	ft_green();
t_color	ft_blue();
t_color	ft_white();
t_color	ft_yellow();
t_color ft_color_divide(t_color color);
#endif