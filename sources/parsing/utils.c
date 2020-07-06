#include "parsing.h"

int tab_len(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        i++;
    }
    return (i);
}

int tab_is_rgb(char **tab)
{
    int i;

    i = 1;
    while (tab[i])
        if (!(ft_atoi(tab[i]) >= 0 && ft_atoi(tab[i]) <= 255))
            return (0);
    return (1);
}

int tab_is_digit(char **tab)
{
    int y;
    int i;

    y = 0;
    i = 0;
    while (tab[++y])
    {
        while (tab[i])
        {
            if (!(tab[y][i] >= '0' || tab[y][i] <= '9'))
                return (0);
            i++;
        }
    }
    return (1);
}
