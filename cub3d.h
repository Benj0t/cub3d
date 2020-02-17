#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gnl/get_next_line.h"
#include "printf/libftprintf.h"

typedef struct  s_map
{
    char        **map;
    char        *resol[2];
    char        **no;
    char        **so;
    char        **we;
    char        **est;
    char        **spr;
    char        **fl;
    char        **ceil;
}               t_map;

int         is_digit(char c);
int         is_rgb(int nb);
int         ft_atoi(char *str);
int         parse(char *arg, t_map *map);
int         ft_strstr(char *src, char *to_find);
#endif