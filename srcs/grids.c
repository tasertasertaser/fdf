#include "../includes/fdf.h"

double	get_unit(t_bigstruct mr_struct)
{
	double print_width = (double)WINDOW_W * 0.45;
	double unit = print_width / (double)mr_struct.map->columns;
	return (unit);
}

t_coord	get_origin(t_bigstruct mr_struct, double unit)
{
	int y;
	int x;
	if (mr_struct.proj == O_KEY)
	{
		x = ft_round(mr_struct.center_x - unit * (mr_struct.map->columns / 2));
	}
	else if (mr_struct.proj == I_KEY)
	{
		x = mr_struct.center_x - ((mr_struct.map->rows * (mr_struct.unit * .35)));
	}
	else
	{
		x = mr_struct.center_x - (get_xunit(mr_struct, 0) * (mr_struct.map->columns / 2));
	}
	y = ft_round(mr_struct.center_y - unit * (mr_struct.map->rows / 2));
	return ((t_coord){x, y, 0});
}

double get_xunit(t_bigstruct mr_struct, int y)
{
	double xunit;
	double slope;

	slope = (PRSP_FRONTEDGE - PRSP_BACKEDGE) / (mr_struct.map->rows - 1);
	xunit = (slope * (double)y) + PRSP_BACKEDGE;
	xunit *= mr_struct.unit;
	return (xunit * 2);
}
void	make_prsp(t_bigstruct mr_struct, t_coord **grid, t_map *map)
{
	int x;
	int y;
	double x_unit;
	double y_unit;
	double x_shift;
	double owidth;
	double nwidth;

	y = 0;
	x_unit = get_xunit(mr_struct, y);
	owidth = x_unit * (map->columns - 1);
	y_unit = (map->columns / map->rows) * (mr_struct.unit);
	// printf(P_PR"y_unit: %f\n"P_X, y_unit);
	while(y < map->rows)
	{
		x = 0;
		x_unit = get_xunit(mr_struct, y);
		nwidth = x_unit * (map->columns - 1);
		x_shift = (y == 0) ? 0 : (nwidth - owidth) / 2;
		while(x < map->columns)
		{
			grid[y][x].x = (mr_struct.origin.x + (x * x_unit)) - x_shift;
			grid[y][x].y = ((y * y_unit) + mr_struct.origin.y) - (map->points[y][x].z * mr_struct.z_mod);
			grid[y][x].color = map->points[y][x].color;
			//mlx_pixel_put(mr_struct.mlx, mr_struct.window, grid[y][x].x, grid[y][x].y, map->points[y][x].color);
			x++;
		}
		y++;
	}
}

void	make_iso(t_bigstruct mr_struct, t_coord **grid, t_map *map)
{
	int x;
	int y;

	y = 0;
	
	while(y < map->rows)
	{
		x = 0;
		while(x < map->columns)
		{
			grid[y][x].x = (((x - y) * cos(0.523599)) * mr_struct.unit) + mr_struct.origin.x;
			grid[y][x].y = (((x + y) * sin(0.523599)) * mr_struct.unit) + mr_struct.origin.y - (map->points[y][x].z) * mr_struct.z_mod;
			grid[y][x].color = map->points[y][x].color;
			x++;
		}
		y++;
	}
}

void	make_orth(t_bigstruct mr_struct, t_coord **grid, t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			grid[y][x].x = (x * mr_struct.unit) + mr_struct.origin.x;
			grid[y][x].y = (y * mr_struct.unit) + mr_struct.origin.y;
			grid[y][x].color = map->points[y][x].color;
			x++;
		}
		y++;
	}
}

t_coord **malloc_grid(t_map *map)
{
	t_coord	**grid;
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!(grid = malloc(sizeof(t_coord *) * map->rows)))
		error("not enough memory.");
	while (y != map->rows)
	{
		if (!(grid[y] = malloc(sizeof(t_coord) * map->columns)))
			error("not enough memory.");
		y++;
	}
	return(grid);
}

void	create_grid(t_bigstruct mr_struct, t_map *map, char projection)
{
	int		i;

	i = 0;
	clear_image(mr_struct.img);
	// grid = malloc_grid(map);
	
	if (projection == O_KEY)
		make_orth(mr_struct, mr_struct.grid, map);
	else if (projection == I_KEY)
		make_iso(mr_struct, mr_struct.grid, map);
	else if (projection == P_KEY)
		make_prsp(mr_struct, mr_struct.grid, map);
	else
		error("something's wrong in create_grid - invalid grid type");

	// printf(P_GR"origin: %d, %d\n"P_X, mr_struct.origin.x, mr_struct.origin.y);
	connect(mr_struct.grid, mr_struct);

	mlx_put_image_to_window(mr_struct.mlx, mr_struct.window, mr_struct.img->imptr, 0, 0);
	// mlx_string_put(mr_struct.mlx, mr_struct.window, WINDOW_W - 230, WINDOW_H + 40, GRY, "Press \"H\" for help");
	// mlx_string_put(mr_struct.mlx, mr_struct.window, 40, WINDOW_H + 40, GRY, mr_struct.file);
	// free_grid(grid, mr_struct);
}

