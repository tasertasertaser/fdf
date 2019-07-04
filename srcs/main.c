#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		t_map	*map = parse(av[1]);
		t_coord **grid;

		grid = malloc_grid(map);		
		void *mlx_ptr = mlx_init();
		void *windowptr = mlx_new_window(mlx_ptr, WINDOW_W, WINDOW_H + 100, "fdf");
		t_im	*image = img_factory(mlx_ptr);
		t_bigstruct mr_struct = {av[1], WINDOW_W / 2, WINDOW_H / 2, windowptr, mlx_ptr, image, map, grid, I_KEY, (t_coord){0, 0, BLK}, 1, 3, 0, 0, WHT, GRY, 0};
		mr_struct.unit = get_unit(mr_struct);
		mr_struct.origin = get_origin(mr_struct, mr_struct.unit);
		
		if (TEST0)
			draw_linestar(mr_struct);
		if (TEST1)
			draw_centerline(mr_struct, TEST1);
		
		// t_image	*img = NULL;
		// img = make_image(mr_struct);
		
		// mlx_put_image_to_window(mr_struct.mlx, mr_struct.window, img, 0, 0);
		

		create_grid(mr_struct, map, mr_struct.proj);
		mlx_string_put(mr_struct.mlx, mr_struct.window, 40, WINDOW_H + 40, GRY, av[1]);
		mlx_string_put(mr_struct.mlx, mr_struct.window, WINDOW_W - 230, WINDOW_H + 40, GRY, "Press \"H\" for help");
		//create_grid(mr_struct, map, mr_struct.proj);

		mlx_hook(windowptr, 2, (1L<<0), key_press, &mr_struct);
		mlx_loop(mlx_ptr);
	}
	else
		give_usage();
	return(0);
}