#include "mlx.h"
#include <stdio.h>
#include <unistd.h>

int deal_key(int key)
{
    write(1, &key, 1);
    return(0);
}


int main()
{
    void *mlx_ptr;
    void *win_ptr;
    int i;
    int y;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "PAPAAAA");
    mlx_key_hook(win_ptr, deal_key, (void *)0);
    i = 0;
    y = 100;
    while (++i <= 500)
    {
        y = 100;
        while (++y < 300)
            mlx_pixel_put(mlx_ptr, win_ptr, i, y, 10548868);
    }
        
    mlx_loop(mlx_ptr);
    return(0);
}