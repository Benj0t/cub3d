#ifndef PARSING_H
# define PARSING_H

#include "./cub3d.h"
#include "./get_next_line.h"

typedef struct  s_vec
{
    int     x;
    int     y;
}               t_vec;

typedef struct  s_parse
{
    char    **tab;
    int     fd;
    char    **map;
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *S;
    char    *C;
    t_color floor;
    t_color ceil;
    t_vec   R;

}               t_parse;
void    ft_putstr(char *str);
char	*ft_strdup(const char *src);
int		ft_atoi(char *str);
char    **ft_split(char *str);
int     store_res(t_parse *s);
int     store_no(t_parse *s);
int     store_so(t_parse *s);
int     store_we(t_parse *s);
int     store_ea(t_parse *s);
int     store_s(t_parse *s);
int     store_f(t_parse *s);
int     store_c(t_parse *s);
int     tab_is_digit(char **tab);
int     tab_is_rgb(char **tab);
void    put_rgb(t_color *c, char **tab);
int     tab_len(char **tab);
#endif