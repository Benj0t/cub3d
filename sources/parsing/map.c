#include "../../includes/parsing.h"

static int     count_n(char *str)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (str[i])
        if (str[i++] == '\n')
            n++;
    return (n);
}

int     create_map(t_parse *s)
{
    int n;
    int i;
    int j;
    int start;
    int len;

    i = -1;
    j = 0;
    start = 0;
    n = count_n(s->map_join);
    printf("%d\n", n);
    if (!(s->map = (char **)malloc(sizeof(char *) * (n + 1))))
        return (0);
    s->map[n] = NULL;
    while (j < n)
    {
        start = ++i;
        while (s->map_join[i] != '\n' || s->map_join[i] == '\r')
            i++;
        len = i - start;
        s->map[j++] = ft_substr(s->map_join, start, len);
    }
    int f = 0;
    while (s->map[f])
    {
        printf("%s\n", s->map[f++]);
    }
    return (1);
}