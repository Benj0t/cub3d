/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:51:21 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/28 11:24:01 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdint.h>
# include <pthread.h>
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "get_next_line.h"

#define RED_COMP 2
#define GREEN_COMP 1
#define BLUE_COMP 0
#define texWidth 64
#define texHeight 64

#define uDiv 1
#define vDiv 1
#define vMove 0.0

typedef struct	s_svec
{
	double x;
	double y;
}				t_svec;

typedef struct	s_vec
{
	int	 x;
	int	 y;
}				t_vec;

typedef struct	s_texture
{
	int		x;
	int		y;
	int		texture;
}				t_texture;

typedef struct	s_w_check
{
	int			s;
	int			n;
	int			e;
	int			o;
}				t_w_check;

typedef struct	s_color
{
	unsigned char	R;
	unsigned char	G;
	unsigned char	B;
	unsigned char	A;
}				t_color;

typedef struct	s_parse
{
	int			sprite_num;
	t_svec		*list;
	int			tabHeight;
	char		id;
	char		*tmp;
	char		*map_join;
	char		**cmap;
	int			**map;
	char		*line;
	char		**tab;
	int	 		fd;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*S;
	char		*C;
	t_color 	floor;
	t_color 	ceil;
	t_vec		R;

}				t_parse;

typedef struct	s_vector
{
	double	distance;
	int		ordre;
}				t_vector;

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
	int		side;
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

typedef struct	s_sprite
{
	int			*spriteOrder;
	double		*spriteDistance;
	double		spriteX;
	double		spriteY;
	double		spriteScreenX;
	double		invDet;
	double		transformX;
	double		transformY;
	int			vMoveScreen;
	int			spriteHeight;
	int			drawStartY;
	int			drawStartX;
	int			drawEndY;
	int			drawEndX;
	int			stripe;
	int			spriteWidth;
	int			texX;
	int			texY;
	int			d;

	double		x;
	double		y;
	int			sprite;
}				t_sprite;


typedef struct	s_pmlx
{
	t_sprite	sp;
	t_img		img;
	t_wall		tex; 
	t_mlx		mlx;
	t_player	pl;
	t_parse		s;
	int			screenshot;
	int			bool_W;
	int			bool_A;
	int			bool_S;
	int			bool_D;
	int			bool_ESC;
}				t_pmlx;

typedef struct s_coords_sprite
{
	double		x;
	double		y;
	int			texture;
}				t_coords_sprite;

typedef struct s_bmp
{
	int size;
	int reserved;
	int offset_bits;
	int header_bytes;
	int planes;
}				t_bmp;

int			raycast();
void		ft_sprites(t_pmlx *pmlx, double ZBuffer[pmlx->s.R.x]);
void		sortSprites(t_pmlx *pmlx, int amount);
void		ft_swap(t_vector *a, t_vector *b);
t_color		ft_light_blue();
t_color		ft_gray();
t_color		ft_red();
t_color		ft_green();
t_color		ft_blue();
t_color		ft_white();
t_color		ft_yellow();
t_color		ft_dark();
t_color 	ft_color_divide(t_color color);
void		err_raycast(t_pmlx *pmlx);
void		draw_ray(t_pmlx *pmlx, int x, t_draw draw, t_ray ray);
int			deal_key_press(int key, t_pmlx *pmlx);
int			deal_key_release(int key, t_pmlx *pmlx);
int			deal_key_leave(int key, t_pmlx *pmlx);
int			deal_key(int key, t_pmlx *pmlx);
void		forward(t_pmlx *pmlx);
void		downward(t_pmlx *pmlx);
void		mv_left(t_pmlx *pmlx);
void		mv_right(t_pmlx *pmlx);
void		main_loop(t_pmlx *pmlx);
void		init_texture(t_pmlx *pmlx);
t_w_check	init_w_check();
void	 	init_parse();
int         init_sprite(t_pmlx *pmlx);
void		init_mlx(t_pmlx *pmlx);
void		init_player(t_pmlx *pmlx);
int			ft_strlen(char *str);
int			find_char (char *str, char c);
int			valid_map(t_pmlx *pmlx);
char		*ft_substr(char *s, int start, int len);
int			create_map(t_pmlx *pmlx);
char		*ft_strjoin(char *s1, char *s2, int len);
char		*ft_strjoin_n(char *s1, char *s2, int len);
int			store_map(t_parse *s);
void		ft_putstr(char *str);
char		*ft_strdup(const char *src);
char		*ft_strdup_n(const char *src);
int			ft_atoi(char *str);
char		**ft_split(char *str, t_pmlx *pmlx);
int			store_res(t_pmlx *pmlx);
int			store_no(t_pmlx *pmlx);
int			store_so(t_pmlx *pmlx);
int			store_we(t_pmlx *pmlx);
int			store_ea(t_pmlx *pmlx);
int			store_s(t_pmlx *pmlx);
int			store_f(t_pmlx *pmlx);
int			store_c(t_pmlx *pmlx);
int			tab_is_digit(char **tab);
int			tab_is_rgb(char **tab);
void		put_rgb(t_color *c, char **tab);
int			tab_len(char **tab);
void		pos_north(t_pmlx *pmlx);
void		pos_east(t_pmlx *pmlx);
void		pos_south(t_pmlx *pmlx);
void		pos_west(t_pmlx *pmlx);
void		pos_dealer(t_pmlx *pmlx, char c);
int			screenshot(t_pmlx *pmlx);
void		err_parsing(t_pmlx *pmlx);
int			ft_strcmp(char *str1, char *str2);
void		ray_err(char *str, t_pmlx *pmlx);
void		ft_puterr(char *str, t_pmlx *pmlx);

void		ft_putchar(char c);
void		ft_putendl(char *str);
void		ft_putstr(char *str);

int			convert_map(t_pmlx *pmlx);
int			map_closed(t_pmlx *pmlx, int y, int x);

int			get_char(char c);
int			get_pos(t_pmlx *pmlx);
void		set_pos(t_pmlx *pmlx, int j, int i);
int			check_tex(t_pmlx *pmlx);
int			ext_check(char *str, char *ext);

int			sprites_tab(t_pmlx *pmlx);
void		free_tab(char **tab);
void		set_null(t_pmlx *pmlx);
#endif