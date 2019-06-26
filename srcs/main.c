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

int key_press(int key, t_window *mr_struct)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window (mr_struct->mlx, mr_struct->window);
		exit(0);
	}
	return (key);
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		t_map	*map = parse(av[1]);
		void *mlx_ptr = mlx_init();
		void *windowptr = mlx_new_window(mlx_ptr, WINDOW_W, WINDOW_H, "fdf");
		t_window mr_struct = {"fdf", WINDOW_W / 2, WINDOW_H / 2, windowptr, mlx_ptr};
		create_grid(mr_struct, map, 'p');
		mlx_hook(windowptr, 2, (1L<<0), key_press, &mr_struct);

		mlx_loop(mlx_ptr);
	}
	else
		give_usage();
	return(0);
}