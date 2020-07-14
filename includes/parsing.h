#ifndef PARSING_H
# define PARSING_H

#include "./cub3d.h"
#include "./get_next_line.h"

typedef struct  s_vec
{
    int     x;
    int     y;
}               t_vec;

typedef struct  s_w_check
{
    int     s;
    int     n;
    int     e;
    int     o;
}               t_w_check;

typedef struct  s_parse
{
    char    *f_line;
    char    *tmp;
    char    *map_join;
    char    **map;
    char    *line;
    char    **tab;
    int     fd;
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

t_w_check   init_w_check();
t_parse     init_parse();
int         find_char (char *str, char c);
int         valid_map(t_parse *s);
char	    *ft_substr(char *s, int start, int len);
int         create_map(t_parse *s);
char	    *ft_strjoin(char *s1, char *s2, int len);
char	    *ft_strjoin_N(char *s1, char *s2, int len);
int         store_map(t_parse *s);
void        ft_putstr(char *str);
char	    *ft_strdup(const char *src);
char	    *ft_strdup_N(const char *src);
int		    ft_atoi(char *str);
char        **ft_split(char *str);
int         store_res(t_parse *s);
int         store_no(t_parse *s);
int         store_so(t_parse *s);
int         store_we(t_parse *s);
int         store_ea(t_parse *s);
int         store_s(t_parse *s);
int         store_f(t_parse *s);
int         store_c(t_parse *s);
int         tab_is_digit(char **tab);
int         tab_is_rgb(char **tab);
void        put_rgb(t_color *c, char **tab);
int         tab_len(char **tab);
#endif