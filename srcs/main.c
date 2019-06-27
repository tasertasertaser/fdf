#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		// parse(av[1]);
		t_map	*map = parse(av[1]);
		void *mlx_ptr = mlx_init();
		void *windowptr = mlx_new_window(mlx_ptr, WINDOW_W, WINDOW_H, "fdf");
		t_bigstruct mr_struct = {WINDOW_W / 2, WINDOW_H / 2, windowptr, mlx_ptr, map, 'o', (t_coord){0, 0, WHT}, 10};

		//void *image = mlx_new_image (mlx_ptr, WINDOW_W, WINDOW_H);
		mlx_string_put(mr_struct.mlx, mr_struct.window, mr_struct.center_x - 95, WINDOW_H - 30, GRY, "Press \"H\" for help");
		draw_linestar(mr_struct);
		//create_grid(mr_struct, map, mr_struct.proj);
		mlx_hook(windowptr, 2, (1L<<0), key_press, &mr_struct);

		mlx_loop(mlx_ptr);
	}
	else
		give_usage();
	return(0);
}