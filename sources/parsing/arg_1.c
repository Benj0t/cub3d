#include "parsing.h"

int    store_res(t_parse *s)
{
    if ((!tab_is_digit(s->tab)) || tab_len(s->tab) != 3)
        return (0);
    s->R.x = ft_atoi(s->tab[1]);
    s->R.y = ft_atoi(s->tab[2]);
    return (1);
}

int    store_f(t_parse *s)
{
    if ((!tab_is_rgb(s->tab)) || tab_len(s->tab) != 4)
        return (0);
    s->floor.R = ft_atoi(s->tab[1]);
    s->floor.G = ft_atoi(s->tab[2]);
    s->floor.B = ft_atoi(s->tab[3]);
    return (1);
}

int    store_c(t_parse *s)
{
    if ((!tab_is_rgb(s->tab)) || tab_len(s->tab) != 4)
        return (0);
    s->ceil.R = ft_atoi(s->tab[1]);
    s->ceil.G = ft_atoi(s->tab[2]);
    s->ceil.B = ft_atoi(s->tab[3]);
    return (1);
}