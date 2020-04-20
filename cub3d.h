#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "gnl/get_next_line.h"
#include "printf/libftprintf.h"
#include <mlx.h>
typedef struct  s_map
{
	char		**grid;
	int			win_x;
	int			win_y;
	char		*no[1];
	char		*so[1];
	char		*we[1];
	char		*est[1];
	char		*spr[1];
	int			fl_r;
	int			fl_g;
	int			fl_b;
	int			cl_r;
	int			cl_g;
	int			cl_b;
}			   t_map;

int			is_bin(int nb)
int			is_rgb(int nb);
char		**ft_plit(char *str);
char		*init_tab(unsigned int len);
int			is_digit(char c);
int			is_rgb(int nb);
int			ft_atoi(char *str);
int			parse(char *arg, t_map *map);
int			ft_strstr(char *src, char *to_find);
int			add_r(char **tab, t_map *map);
int			add_path(char **tab, char *var[1]);
int			add_rgb(char **tab, int *r, int *g, int *b);
#endif