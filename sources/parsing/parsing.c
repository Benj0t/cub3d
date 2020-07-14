#include "../../includes/parsing.h"

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &(str[i++]), 1);
    }
}

int     get_arg(t_parse *s)
{
    /*
    int i = 0;
    while (s->tab[i])
    {
        ft_putstr(s->tab[i++]);
    }
    write(1, "\n", 1);
    */
    if (s->tab[0] == NULL)
        return (0);
    if (s->tab[0][0] == 'R')
        return (store_res(s));
    else if (s->tab[0][0] == 'N' && s->tab[0][1] == 'O')
        return (store_no(s));
    else if (s->tab[0][0] == 'S' && s->tab[0][1] == 'O')
        return (store_so(s));
    else if (s->tab[0][0] == 'W' && s->tab[0][1] == 'E')
        return (store_we(s));
    else if (s->tab[0][0] == 'E' && s->tab[0][1] == 'A')
        return (store_ea(s));
    else if (s->tab[0][0] == 'S')
        return (store_s(s));
    else if (s->tab[0][0] == 'F')
        return (store_f(s));
    else if (s->tab[0][0] == 'C')
        return (store_c(s));
    else
    {
        return(0);
    }
}

void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i++]);
    }
    free(tab);
}

void    add_line(t_parse *s)
{
    s->map_join = ft_strdup_N(s->line);
    free(s->line);
    //ft_putstr(s->map_join);
    while ((get_next_line(s->fd, &(s->line))) > 0)
    {
        if (ft_strlen(s->line) > 0)
        {
            s->tmp = ft_strjoin_N(s->map_join, s->line, (ft_strlen(s->map_join) + ft_strlen(s->line)));
            free(s->map_join);
            s->map_join = ft_strdup(s->tmp);
            free(s->tmp);
            free(s->line);
        }
    }
    if (ft_strlen(s->line) > 1)
    {
        s->tmp = ft_strjoin(s->map_join, s->line, (ft_strlen(s->map_join) + ft_strlen(s->line)));
        free(s->map_join);
        s->map_join = ft_strdup(s->tmp);
        free(s->tmp);
    }
}

int ft_parse(t_parse *s, char *filename)
{
    if ((s->fd = open(filename, O_RDONLY)) <= 0)
        return (0);
    s->tmp = NULL;
    while ((get_next_line(s->fd, &(s->line))) > 0)
    {
        if ((s->tab = ft_split(s->line)) == NULL)
            free(s->line);
        else
        {
            if (s->tab[0][0] == '1')
                add_line(s);
            else
            {
                get_arg(s);
            } 
            free_tab(s->tab);
            free(s->line);
        }
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_parse s;
    s = init_parse();
    if (argc != 2)
        return (0);
    ft_parse(&s, argv[1]);
    create_map(&s);
    printf("Valide ? %d\n", valid_map(&s));

}
    /*
    printf("NO %s\n", s.NO);
    printf("SO %s\n", s.SO);
    printf("WE %s\n", s.WE);
    printf("EA %s\n", s.EA);
    printf("S %s\n", s.S);
    printf("Rx %d\n", s.R.x);
    printf("Ry %d\n", s.R.y);
    printf("F.r %d\n", s.floor.R);
    printf("F.g %d\n", s.floor.G);
    printf("F.b %d\n", s.floor.B);
    printf("C.r %d\n", s.ceil.R);
    printf("C.g %d\n", s.ceil.G);
    printf("C.b %d\n", s.ceil.B);
    printf("MAP:\n%s", s.map_join);
    */