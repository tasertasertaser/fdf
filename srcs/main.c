#include "../includes/fdf.h"

void	give_usage()
{
	ft_putstr("Usage:\n\t");
	ft_putstr(" ./fdf \"filename.fdf\"\n");
	ft_putstr("Controls:\n");
	ft_putstr("\t[Esc]        -> Exit the program\n");
	ft_putstr("\t[R]          -> Reset the map\n");
	ft_putstr("\t[C]          -> Color toggle\n");
	ft_putstr("\t[Z][X]       -> Zoom in/out\n");
	ft_putstr("\t[J][K]       -> Elevation\n");
	ft_putstr("\t[I][O][P]    -> Projection (Iso <> Ortho <> Perspective)\n");
	ft_putstr("\t[W][A][S][D] -> Move the map\n");
	ft_putstr("\t[H]          -> Help\n");
	ft_putstr(P_GY);
	ft_putstr("\t[=]          -> Secret bonus mode\n\n");
	ft_putstr(P_X);
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		// parse(av[1]);
		t_map	*map = parse(av[1]);
		void *mlx_ptr = mlx_init();
		void *windowptr = mlx_new_window(mlx_ptr, WINDOW_W, WINDOW_H, "fdf");
		t_bigstruct mr_struct = {WINDOW_W / 2, WINDOW_H / 2, windowptr, mlx_ptr, map, 'o', (t_coord){400, 150}};

		//void *image = mlx_new_image (mlx_ptr, WINDOW_W, WINDOW_H);
		mlx_string_put(mr_struct.mlx, mr_struct.window, mr_struct.center_x - 95, WINDOW_H - 30, GRY, "Press \"H\" for help");
		create_grid(mr_struct, map, mr_struct.proj);
		mlx_hook(windowptr, 2, (1L<<0), key_press, &mr_struct);

		mlx_loop(mlx_ptr);
	}
	else
		give_usage();
	return(0);
}