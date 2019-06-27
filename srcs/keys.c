#include "../includes/fdf.h"

static const char *g_helpstring[] = {
	"Controls:\n",
	"[Esc]        -> Exit the program\n",
	"[R]          -> Reset the map\n",
	"[C]          -> Color toggle\n",
	"[Z][X]       -> Zoom in/out\n",
	"[J][K]       -> Elevation\n",
	"[I][O][P]    -> Projection (Iso <> Ortho <> Perspective)\n",
	"[W][A][S][D] -> Move the map\n",
	"[H]          -> Help\n",
	"[=]          -> Secret bonus mode\n",
};

void	give_usage()
{
	size_t i;

	i = 0;
	ft_putstr(P_BL);
	ft_putstr("\nUsage:\n\t");
	ft_putstr(" ./fdf \"filename.fdf\"\n\n");
	ft_putstr(P_GY);
	while (i < sizeof(g_helpstring)/sizeof(g_helpstring[0]))
	{
		ft_putstr(g_helpstring[i]);
		i++;
	}
	ft_putstr(P_X);
}

void	help(t_bigstruct *mr_struct)
{
	size_t i;

	i = 0;
	mlx_clear_window (mr_struct->mlx, mr_struct->window);
	while (i < sizeof(g_helpstring)/sizeof(g_helpstring[0]))
	{
		mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x - 250, 290 + (i * 20), GRY, (char *)g_helpstring[i]);
		i++;
	}
}

int key_press(int key, t_bigstruct *mr_struct)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window (mr_struct->mlx, mr_struct->window);
		exit(0);
	}
	if (key == I_KEY)
	{
		mr_struct->proj = 'i';
		mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == O_KEY)
	{
		mr_struct->proj = 'o';
		mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == P_KEY)
	{
		mr_struct->proj = 'p';
		mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == A_KEY)
	{
		mr_struct->origin.x -= 10;
		mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == D_KEY)
	{
		mr_struct->origin.x += 10;
		mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == J_KEY)
	{
		mr_struct->z_mod--;
		mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == K_KEY)
	{
		mr_struct->z_mod++;
		mlx_clear_window (mr_struct->mlx, mr_struct->window);
		create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
	}
	if (key == H_KEY)
		help(mr_struct);
	return (key);
}