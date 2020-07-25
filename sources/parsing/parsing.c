#include "cub3d.h"

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &(str[i++]), 1);
    }
}

int     get_arg(t_pmlx *pmlx)
{
    if (pmlx->s.tab[0] == NULL)
        return (0);
    if (pmlx->s.tab[0][0] == 'R')
        return (store_res(pmlx));
    else if (pmlx->s.tab[0][0] == 'N' && pmlx->s.tab[0][1] == 'O')
        return (store_no(pmlx));
    else if (pmlx->s.tab[0][0] == 'S' && pmlx->s.tab[0][1] == 'O')
        return (store_so(pmlx));
    else if (pmlx->s.tab[0][0] == 'W' && pmlx->s.tab[0][1] == 'E')
        return (store_we(pmlx));
    else if (pmlx->s.tab[0][0] == 'E' && pmlx->s.tab[0][1] == 'A')
        return (store_ea(pmlx));
    else if (pmlx->s.tab[0][0] == 'S')
        return (store_s(pmlx));
    else if (pmlx->s.tab[0][0] == 'F')
        return (store_f(pmlx));
    else if (pmlx->s.tab[0][0] == 'C')
        return (store_c(pmlx));
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

void    add_line(t_pmlx *pmlx)
{
    pmlx->s.map_join = ft_strdup_N(pmlx->s.line);
    free(pmlx->s.line);
    while ((get_next_line(pmlx->s.fd, &(pmlx->s.line))) > 0)
    {
        if (ft_strlen(pmlx->s.line) > 0)
        {
            pmlx->s.tmp = ft_strjoin_N(pmlx->s.map_join, pmlx->s.line, (ft_strlen(pmlx->s.map_join) + ft_strlen(pmlx->s.line)));
            free(pmlx->s.map_join);
            pmlx->s.map_join = ft_strdup(pmlx->s.tmp);
            free(pmlx->s.tmp);
            free(pmlx->s.line);
        }
    }
    if (ft_strlen(pmlx->s.line) > 1)
    {
        pmlx->s.tmp = ft_strjoin(pmlx->s.map_join, pmlx->s.line, (ft_strlen(pmlx->s.map_join) + ft_strlen(pmlx->s.line)));
        free(pmlx->s.map_join);
        pmlx->s.map_join = ft_strdup(pmlx->s.tmp);
        free(pmlx->s.tmp);
    }
}

int ft_parse(t_pmlx *pmlx, char *filename)
{
    if ((pmlx->s.fd = open(filename, O_RDONLY)) <= 0)
        return (0);
    pmlx->s.tmp = NULL;
    while ((get_next_line(pmlx->s.fd, &(pmlx->s.line))) > 0)
    {
        if ((pmlx->s.tab = ft_split(pmlx->s.line)) == NULL)
            free(pmlx->s.line);
        else
        {
            if (pmlx->s.tab[0][0] == '1')
                add_line(pmlx);
            else
            {
                get_arg(pmlx);
            } 
            free_tab(pmlx->s.tab);
            free(pmlx->s.line);
        }
    }
    return (1);
}

int get_pos(t_pmlx *pmlx)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (pmlx->s.cmap[j])
    {
        while (pmlx->s.cmap[j][i])
        {
            if (find_char("NESW", pmlx->s.cmap[j][i]))
            {
                pmlx->s.dir = pmlx->s.cmap[j][i];
                pmlx->s.cmap[j][i] = '0';
                pmlx->pl.posX = j;
                pmlx->pl.posY = i;
                return (1);
            }
            i++;
        }
        i = 0;
        j++;
    }
    return (0);
}

int get_char(char c)
{
    if (c == ' ')
        return (32);
    if (c == '0')
        return (0);
    if (c == '1')
        return (1);
    return (-1);
}

int convert_map(t_pmlx *pmlx)
{
    int len;
    int height;
    int i;
    int j;

    i = 0;
    j = 0;
    height = tab_len(pmlx->s.cmap);
    if (!(pmlx->s.map = (int **)malloc(sizeof(int *) * (height + 1))))
        return (0);
    pmlx->s.map[height] = NULL;
    while (i < height)
    {
        len = ft_strlen(pmlx->s.cmap[i]);
        if (!(pmlx->s.map[i] = (int *)malloc(sizeof(int) * (len + 1))))
            return (0);
        pmlx->s.map[i][len] = '\0';
        while (j < len)
        {
            pmlx->s.map[i][j] = get_char(pmlx->s.cmap[i][j]);
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}
// SPRITES COO = 2 dans la cmap // LISTE CHAINEES
// PLAYER COO | S E O N > delete // DONE
// SOLVE RAYCASTING PROBLEM

int main(int argc, char **argv)
{
    t_pmlx pmlx;
    pmlx.s = init_parse();
    if (argc != 2)
        return (0);
    if (!(ft_parse(&pmlx, argv[1])))
        return (0);
    if (!(create_map(&pmlx)))
        return (0);
    if (valid_map(&pmlx) || (!get_pos(&pmlx)) || (!convert_map(&pmlx)))
        return (0);
    raycast(&pmlx);
    
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
    printf("cMAP:\n%s", s.cmap_join);
    */