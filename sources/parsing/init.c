#include "../../includes/parsing.h"

t_parse     init_parse()
{
    t_parse s;

    s.NO = NULL;
    s.SO = NULL;
    s.WE = NULL;
    s.EA = NULL;
    s.S = NULL;
    return (s);
}

t_w_check   init_w_check()
{
    t_w_check w;
    w.s = 0;
    w.n = 0;
    w.o = 0;
    w.e = 0;
    return (w);
}