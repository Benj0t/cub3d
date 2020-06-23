#include <mlx.h>

int main()
{
	void *ptr;
	void *w_ptr;

	ptr = mlx_init();
	w_ptr = mlx_new_window(ptr, 500, 500, "oui");
	mlx_loop(ptr);
}