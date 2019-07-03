#include "../includes/fdf.h"

void	give_usage()
{
	size_t i;

	i = 0;
	ft_putstr(P_BL);
	ft_putstr("\nUsage:\n\t");
	ft_putstr(" ./fdf \"filename.fdf\"\n\n");
	ft_putstr(P_GY);
	static const char *helpstring[] = {
		"Controls:\n",
		"[Esc]        -> Exit the program\n",
		"[Space]      -> Reset the map\n",
		"[C]          -> Color toggle\n",
		"[Z][X]       -> Zoom in/out\n",
		"[J][K]       -> Elevation\n",
		"[I][O][P]    -> Projection (Iso <> Ortho <> Perspective)\n",
		"[W][A][S][D] -> Move the map\n",
		"[H]          -> Help\n",
		"[=]          -> Secret bonus mode\n",
	};
	while (i < sizeof(helpstring)/sizeof(helpstring[0]))
	{
		ft_putstr(helpstring[i]);
		i++;
	}
	ft_putstr(P_X);
}

void	help(t_bigstruct *mr_struct)
{
	size_t i;

	i = 0;
	static const char *helpstring[] = {
		"Controls:\n",
		"[Esc]        -> Exit the program\n",
		"[Space]      -> Reset the map\n",
		"[C]          -> Color toggle\n",
		"[Z][X]       -> Zoom in/out\n",
		"[J][K]       -> Elevation\n",
		"[I][O][P]    -> Projection (Iso <> Ortho <> Perspective)\n",
		"[W][A][S][D] -> Move the map\n",
		"[H]          -> Help\n",
		"[=]          -> Secret bonus mode\n",
	};
	mlx_clear_window (mr_struct->mlx, mr_struct->window);
	while (i < sizeof(helpstring)/sizeof(helpstring[0]))
	{
		mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x - 250, 290 + (i * 20), GRY, (char *)helpstring[i]);
		i++;
	}
}

void	reset(t_bigstruct *mr_struct)
{
	mr_struct->unit = get_unit(*mr_struct);;
	mr_struct->origin = get_origin(*mr_struct, mr_struct->unit);
	mr_struct->z_mod = 3;
	create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
}

int key_press(int key, t_bigstruct *mr_struct)
{
	if (key == ESC_KEY)
	{
		free_grid(mr_struct->grid, *mr_struct);
		mlx_destroy_image(mr_struct->mlx, mr_struct->img);
		mlx_destroy_window(mr_struct->mlx, mr_struct->window);
		exit(0);
	}
	if (key == SPACE_KEY)
		reset(mr_struct);
	if (key == I_KEY)
	{
		mr_struct->proj = 'i';
		//mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == O_KEY)
	{
		mr_struct->proj = 'o';
		// mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == P_KEY)
	{
		mr_struct->proj = 'p';
		// mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == A_KEY)
	{
		mr_struct->origin.x -= 10;
		// mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == D_KEY)
	{
		mr_struct->origin.x += 10;
		// mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == W_KEY)
	{
		mr_struct->origin.y -= 10;
		// mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == S_KEY)
	{
		mr_struct->origin.y += 10;
		// mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == J_KEY)
	{
		mr_struct->z_mod--;
		// mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == K_KEY)
	{
		mr_struct->z_mod++;
		// mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == Z_KEY)
	{
		if (mr_struct->unit < ZOOM_MAX)
		{
			mr_struct->unit++;
			mr_struct->z_mod *= 1.05;
			// mlx_clear_window (mr_struct->mlx, mr_struct->window);
			create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
		}
	}
	if (key == X_KEY)
	{
		if (mr_struct->unit > 2)
		{
			mr_struct->unit--;
			mr_struct->z_mod *= 0.95;
			// mlx_clear_window (mr_struct->mlx, mr_struct->window);
			create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
		}
	}
	if (key == C_KEY)
	{
		if (mr_struct->clr == 0)
			mr_struct->clr = 1;
		else if (mr_struct->clr == 1)
			mr_struct->clr = 2;
		else if (mr_struct->clr == 2)
			mr_struct->clr = 3;
		else 
			mr_struct->clr = 0;
		// mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == H_KEY)
	{
		if (!mr_struct->helptoggle)
		{
			help(mr_struct);
			mr_struct->helptoggle = 1;
			mlx_string_put(mr_struct->mlx, mr_struct->window, WINDOW_W - 230, WINDOW_H + 40, GRY, "Press \"H\" to exit");
		}
		else
		{
			mlx_clear_window(mr_struct->mlx, mr_struct->window);
			create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
			mr_struct->helptoggle = 0;
			mlx_string_put(mr_struct->mlx, mr_struct->window, WINDOW_W - 230, WINDOW_H + 40, GRY, "Press \"H\" for help");
		}
		mlx_string_put(mr_struct->mlx, mr_struct->window, 40, WINDOW_H + 40, GRY, mr_struct->file);
		
	}
	if (key == TESTKEY)
	{
		mlx_string_put(mr_struct->mlx, mr_struct->window, WINDOW_W - 530, WINDOW_H + 40, PRP, ft_itoa(mr_struct->z_mod));
	}
	return (key);
}