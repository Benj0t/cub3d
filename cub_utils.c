#include "cub3d.h"

int is_rgb(int nb)
{
    if (0 <= nb && nb <= 255)
        return (1);
    return (0);
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
       return (1);
    return (0);
}