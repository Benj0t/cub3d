#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
//#include "utils/gnl/get_next_line.h"
//#include "utils/printf/libftprintf.h"
#define ALIEN ..\images\alien.png
#define BRICK ..\images\brick.png
#define COBBLE ..\images\cobblestone.png
#define EAGLE ..\images\eagle.png
#define GLOWSTONE ..\images\glowstone.png
#define GRAVEL ..\images\gravel.png
#define LAPIS ..\images\lapis.png
#define WOOD ..\images\wood.png

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
#define texWidth 64
#define texHeight 64

typedef struct	s_image
{
	void		*img_ptr;
	int			x;
	int			y;

	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			*pixels;
}				t_image;

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
	double		oldDirX;
	double		oldPlaneX;
	double		moveSpeed;
	double		rotSpeed;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		stepX;
	double		stepY;
	int			mapX;
	int			mapY;
}				t_player;

typedef struct s_color
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char A;
}				t_color;

typedef struct s_wall
{
	int		texNum;
	double	wallX;
	double	texPos;
	int		texX;
	int		texY;
	double		step;
}				t_wall;

typedef struct s_img
{
	int		bpp;
	int		s_line;
	int		endian;
	void	**addr;
	char	**image;
	int		img_H;
	int		img_W;
}				t_img;

typedef struct	s_pmlx
{
	t_img		img;
	t_wall		tex;
	t_mlx		mlx;
	t_player	pl;
	int			bool_W;
	int			bool_A;
	int			bool_S;
	int			bool_D;
	int			bool_ESC;
}				t_pmlx;

t_color	ft_light_blue();
t_color	ft_gray();
t_color	ft_red();
t_color	ft_green();
t_color	ft_blue();
t_color	ft_white();
t_color	ft_yellow();
t_color ft_color_divide(t_color color);
void	draw_ray(char *data_addr, int x, t_draw draw, t_color color, t_pmlx *pmlx, t_ray ray);
int		deal_key_press(int key, t_pmlx *pmlx);
int		deal_key_release(int key, t_pmlx *pmlx);
int		deal_key(int key, t_pmlx *pmlx);
void    forward(t_pmlx *pmlx);
void    downward(t_pmlx *pmlx);
void    mv_left(t_pmlx *pmlx);
void    mv_right(t_pmlx *pmlx);
void	main_loop(t_pmlx *pmlx);
void    init_texture(t_pmlx *pmlx);
#endif