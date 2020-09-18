/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:51:21 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/18 12:23:11 by bemoreau         ###   ########.fr       */
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

# define RED_COMP 2
# define GREEN_COMP 1
# define BLUE_COMP 0
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

typedef struct	s_svec
{
	double		x;
	double		y;
}				t_svec;

typedef struct	s_vec
{
	int			x;
	int			y;
}				t_vec;

typedef struct	s_texture
{
	int			x;
	int			y;
	int			texture;
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
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}				t_color;

typedef struct	s_parse
{
	int			sprite_num;
	t_svec		*list;
	int			tabheight;
	char		id;
	char		*tmp;
	char		*map_join;
	char		**cmap;
	int			**map;
	char		*line;
	char		**tab;
	int			fd;
	int			n_key;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		*c;
	t_color		floor;
	t_color		ceil;
	t_vec		r;

}				t_parse;

typedef struct	s_vector
{
	double		distance;
	int			ordre;
}				t_vector;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		endian;
	int		bpp;
	int		size_l;
	int		sizex;
	int		sizey;
}				t_mlx;

typedef struct	s_ray
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		hit;
	int		side;
}				t_ray;

typedef struct	s_draw
{
	int		lineheight;
	int		start;
	int		end;
}				t_draw;

typedef struct	s_player
{
	double		olddirx;
	double		oldplanex;
	double		movespeed;
	double		rotspeed;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		stepx;
	double		stepy;
	int			mapx;
	int			mapy;
}				t_player;

typedef struct	s_wall
{
	int			texnum;
	double		wallx;
	double		texpos;
	int			texx;
	int			texy;
	double		step;
}				t_wall;

typedef struct	s_img
{
	int		bpp;
	int		s_line;
	int		endian;
	void	**addr;
	char	**image;
	int		img_h;
	int		img_w;
}				t_img;

typedef struct	s_sprite
{
	int			*sprite_order;
	double		*sprite_distance;
	double		spritex;
	double		spritey;
	double		spritescreenx;
	double		invdet;
	double		transformx;
	double		transformy;
	int			vmove_screen;
	int			spriteheight;
	int			drawstarty;
	int			drawstartx;
	int			drawendy;
	int			drawendx;
	int			stripe;
	int			spritewidth;
	int			texx;
	int			texy;
	int			d;

	double		x;
	double		y;
	int			sprite;
}				t_sprite;

typedef struct	s_bool
{
	int			bool_w;
	int			bool_a;
	int			bool_s;
	int			bool_d;
	int			bool_l;
	int			bool_r;
}				t_bool;

typedef struct	s_pmlx
{
	t_sprite	sp;
	t_img		img;
	t_wall		tex;
	t_mlx		mlx;
	t_player	pl;
	t_parse		s;
	t_bool		b;
	int			screenshot;
}				t_pmlx;

typedef struct	s_coords_sprite
{
	double		x;
	double		y;
	int			texture;
}				t_coords_sprite;

typedef struct	s_bmp
{
	int size;
	int reserved;
	int offset_bits;
	int header_bytes;
	int planes;
}				t_bmp;

void			fake_mlx(t_pmlx *pmlx);
void			take_screenshot(t_pmlx *pmlx);
void			mv_left(t_pmlx *pmlx);
void			mv_right(t_pmlx *pmlx);
int				ft_parse(t_pmlx *pmlx, char *filename);
void			putpix(t_pmlx *pmlx, int x, int y, t_color color);
int				raycast();
void			dda(t_ray *ray, t_pmlx *pmlx);
void			init_dda(t_ray *ray, t_pmlx *pmlx);
void			init_loop(t_ray *ray, t_pmlx *pmlx, int x);
void			ft_sprites(t_pmlx *pmlx, double zbuffer[pmlx->s.r.x]);
void			sort_sprites(t_pmlx *pmlx, int amount);
void			ft_swap(t_vector *a, t_vector *b);
void			err_raycast(t_pmlx *pmlx);
void			draw_ray(t_pmlx *pmlx, int x, t_draw draw, t_ray ray);
int				deal_key_press(int key, t_pmlx *pmlx);
int				deal_key_release(int key, t_pmlx *pmlx);
int				deal_key_leave(t_pmlx *pmlx);
int				deal_key(int key, t_pmlx *pmlx);
void			forward(t_pmlx *pmlx);
void			downward(t_pmlx *pmlx);
void			rot_left(t_pmlx *pmlx);
void			rot_right(t_pmlx *pmlx);
void			main_loop(t_pmlx *pmlx);
void			init_texture(t_pmlx *pmlx);
t_w_check		init_w_check();
void			init_parse();
int				init_sprite(t_pmlx *pmlx);
void			init_mlx(t_pmlx *pmlx);
void			init_player(t_pmlx *pmlx);
int				ft_strlen(char *str);
int				find_char (char *str, char c);
int				valid_map(t_pmlx *pmlx);
char			*ft_substr(char *s, int start, int len);
int				create_map(t_pmlx *pmlx);
char			*ft_strjoin(char *s1, char *s2, int len);
char			*ft_strjoin_n(char *s1, char *s2, int len);
int				store_map(t_parse *s);
void			ft_putstr(char *str);
char			*ft_strdup(const char *src);
char			*ft_strdup_n(const char *src);
int				ft_atoi(char *str);
char			**ft_split(char *str, t_pmlx *pmlx);
int				store_res(t_pmlx *pmlx);
int				store_no(t_pmlx *pmlx);
int				store_so(t_pmlx *pmlx);
int				store_we(t_pmlx *pmlx);
int				store_ea(t_pmlx *pmlx);
int				store_s(t_pmlx *pmlx);
int				store_f(t_pmlx *pmlx);
int				store_c(t_pmlx *pmlx);
int				tab_is_digit(char **tab);
int				tab_is_rgb(char **tab);
void			put_rgb(t_color *c, char **tab);
void			sp_rgb(t_pmlx *pmlx, t_color color, int stripe, int y);
int				tab_len(char **tab);
void			pos_north(t_pmlx *pmlx);
void			pos_east(t_pmlx *pmlx);
void			pos_south(t_pmlx *pmlx);
void			pos_west(t_pmlx *pmlx);
void			pos_dealer(t_pmlx *pmlx, char c);
int				screenshot(t_pmlx *pmlx);
void			err_parsing(t_pmlx *pmlx);
int				ft_strcmp(char *str1, char *str2);
void			ray_err(char *str, t_pmlx *pmlx);
void			ft_destroy(t_pmlx *pmlx);
void			ft_puterr(char *str, t_pmlx *pmlx);
void			ft_putchar(char c);
void			ft_putendl(char *str);
void			ft_putstr(char *str);
int				convert_map(t_pmlx *pmlx);
int				map_closed(t_pmlx *pmlx, int y, int x);
int				get_char(char c);
int				get_pos(t_pmlx *pmlx);
void			set_pos(t_pmlx *pmlx, int j, int i);
int				check_tex(t_pmlx *pmlx);
int				ext_check(char *str, char *ext);
int				sprites_tab(t_pmlx *pmlx);
void			spr_fix(t_pmlx *pmlx, int n);
void			free_tab(char **tab);
void			set_null(t_pmlx *pmlx);
void			init_sp_tab(t_pmlx *pmlx);
int				init_sprite(t_pmlx *pmlx);
void			free_tab(char **tab);
void			free_itab(int **tab);
#endif
