#include "../../includes/parsing.h"

int     get_arg(t_parse *s)
{
    if (!s->tab[0] || s->tab[0] == '\0')
    {
        free(s->tab);
        return (1);
    }
    if (s->tab[0] == "R")
        return (store_res(s));
    else if (s->tab[0] == "NO")
        return (store_no(s));
    else if (s->tab[0] == "SO")
        return (store_so(s));
    else if (s->tab[0] == "WE")
        return (store_we(s));
    else if (s->tab[0] == "EA")
        return (store_ea(s));
    else if (s->tab[0] == "S")
        return (store_s(s));
    else if (s->tab[0] == "F")
        return (store_f(s));
    else if (s->tab[0] == "C")
        return (store_c(s));
    else
    {
        return(0);
    }
}

int ft_parse(t_parse *s, char *filename)
{
    char    *line;
    char    **tab;

    s->fd = open(filename, O_RDONLY);
    while (get_next_line(s->fd, &line) > 0)
    {
        if (!(tab = ft_split(line)))
        {
            free(line);
            return (NULL);
        }
        get_arg(s);
    }
}

int main(int argc, char **argv)
{
    t_parse s;

    ft_parse(&s, argv[1]);
    printf("%s\n", s.NO);
    printf("%s\n", s.NO);
    printf("%s\n", s.SO);
    printf("%s\n", s.WE);
    printf("%s\n", s.EA);
}