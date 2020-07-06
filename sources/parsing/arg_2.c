#include "parsing.h"

int    store_no(t_parse *s)
{
    int fd;
    
    if ((tab_len(s->tab) != 2) || (fd = open(s->tab[1], O_RDONLY)) <= 0)
        return (0);
    close(fd);
    s->NO = ft_strdup(s->tab[1]);
    return (1);
}

int    store_so(t_parse *s)
{
    int fd;
    
    if ((tab_len(s->tab) != 2) || (fd = open(s->tab[1], O_RDONLY)) <= 0)
        return (0);
    close(fd);
    s->SO = ft_strdup(s->tab[1]);
    return (1);
}

int    store_we(t_parse *s)
{
    int fd;
    
    if ((tab_len(s->tab) != 2) || (fd = open(s->tab[1], O_RDONLY)) <= 0)
        return (0);
    close(fd);
    s->WE = ft_strdup(s->tab[1]);
    return (1);
}

int    store_ea(t_parse *s)
{
    int fd;
    
    if ((tab_len(s->tab) != 2) || (fd = open(s->tab[1], O_RDONLY)) <= 0)
        return (0);
    close(fd);
    s->EA = ft_strdup(s->tab[1]);
    return (1);
}

int    store_s(t_parse *s)
{
    int fd;
    
    if ((tab_len(s->tab) != 2) || (fd = open(s->tab[1], O_RDONLY)) <= 0)
        return (0);
    close(fd);
    s->S = ft_strdup(s->tab[1]);
    return (1);
}