#include "../../includes/parsing.h"

void    hor_check(char **tab, t_w_check *wall, int y, int x)
{
    int i;

    i = y;
    while (tab[i])
    {
        if (tab[i++][x] == '1')
            wall->s = 1;
    }
    i = y;
    while (i >= 0)
    {
        if (tab[i--][x] == '1')
            wall->n = 1;
    }
}

void    ver_check(char **tab, t_w_check *wall, int y, int x)
{
    int i;

    i = x;
    while (tab[y][i])
    {
        if (tab[y][i++] == '1')
            wall->e = 1;
    }
    i = x;
    while (i >= 0)
    {
        if (tab[y][i--] == '1')
            wall->o = 1;
    }
}

int     verif_pos(char **tab, int y, int x)
{
    int i;
    int j;
    t_w_check wall;

    i = y;
    j = x;
    wall = init_w_check();
    ver_check(tab, &wall, y, x);
    hor_check(tab, &wall, y, x);
    if (!wall.n || !wall.s || !wall.o || !wall.e)
        return (1);
    return (0);
}

int     is_map_closed(t_parse *s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s->map[j])
    {
        while (s->map[j][i])
        {
            if (s->map[j][i] == '0')
                if (verif_pos(s->map, j, i))
                    return (1);
            i++;
        }
        i = 0;
        j++;
    }
    return (0);
}

int     auth_char(t_parse *s)
{
    int i;
    int j;
    char *str;

    str = "012NSEW ";
    i = 0;
    j = 0;
    while (s->map[j])
    {
        while (s->map[j][i])
        {
            if (!find_char(str, s->map[j][i]))
                return (1);
            i++;
        }
        i = 0;
        j++;
    }
    return (0);
}

int     valid_map(t_parse *s)
{
    int ret;

    ret = auth_char(s);
    if (!ret)
        ret = is_map_closed(s);
    return (ret);
}