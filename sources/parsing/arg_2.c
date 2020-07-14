#include "../../includes/parsing.h"

int    store_no(t_parse *s)
{
    int fd;

    if (((tab_len(s->tab)) != 2) || (fd = open(s->tab[1], O_RDONLY)) < 0)
        return (0);
    s->NO = ft_strdup(s->tab[1]);
    close(fd);
    return (1);
}

int    store_so(t_parse *s)
{
    int fd;

    if (((tab_len(s->tab)) != 2) || (fd = open(s->tab[1], O_RDONLY)) < 0)
        return (0);
    s->SO = ft_strdup(s->tab[1]);
    close(fd);
    return (1);
}

int    store_we(t_parse *s)
{
    int fd;

    if (((tab_len(s->tab)) != 2) || (fd = open(s->tab[1], O_RDONLY)) < 0)
        return (0);
    s->WE = ft_strdup(s->tab[1]);
    close(fd);
    return (1);
}

int    store_ea(t_parse *s)
{
    int fd;

    if (((tab_len(s->tab)) != 2) || (fd = open(s->tab[1], O_RDONLY)) < 0)
        return (0);
    s->EA = ft_strdup(s->tab[1]);
    close(fd);
    return (1);
}

int    store_s(t_parse *s)
{
    int fd;
    if (((tab_len(s->tab)) != 2) || (fd = open(s->tab[1], O_RDONLY)) < 0)
        return (0);
    s->S = ft_strdup(s->tab[1]);
    close(fd);
    return (1);
}