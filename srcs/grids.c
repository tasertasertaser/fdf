#include "../includes/fdf.h"

// t_coord get_origin(t_map *map, char projection)
// {

// }

// double	get_unit(t_map *map, char projection)
// {

// }
// http://faculty.cs.tamu.edu/jchai/cpsc641_spring10/PerspectiveProjection.pdf
void	make_prsp(t_bigstruct mr_struct, t_coord **grid, t_map *map)
{
	int x;
	int y;
	double unit;
	double x_unit;
	int y_unit;

	unit = 30;
	if (mr_struct.origin.x == 0 && mr_struct.origin.y == 0)
		mr_struct.origin.x = (mr_struct.center_x - (unit * (map->columns/2)));
	mr_struct.origin.y = 200;
	y = 0;

	// draw_centerline(mr_struct, 'b');

	while(y < map->rows)
	{
		x = 0;
		y_unit = (unit/2) + y;
		while(x < map->columns)
		{
			x_unit = unit + ((y * y_unit)/5);
			grid[y][x].x = ((x * unit) + mr_struct.origin.x) < mr_struct.center_x ? ((mr_struct.center_x - ((x + 1) * x_unit))) : ((mr_struct.center_x + ((x - (map->columns / 2)) * x_unit)));
			grid[y][x].y = (y * y_unit) + mr_struct.origin.y;
			mlx_pixel_put(mr_struct.mlx, mr_struct.window, grid[y][x].x, grid[y][x].y, BLU);
			x++;
		}
		y++;
	}
}

void	make_iso(t_bigstruct mr_struct, t_coord **grid, t_map *map)
{
	int x;
	int y;
	double unit;

	unit = 40;
	y = 0;
	
	while(y < map->rows)
	{
		x = 0;
		while(x < map->columns)
		{
			grid[y][x].x = (((x - y) * cos(0.523599)) * unit) + mr_struct.origin.x;
			grid[y][x].y = (((x + y) * sin(0.523599)) * unit) + mr_struct.origin.y;
			mlx_pixel_put(mr_struct.mlx, mr_struct.window, grid[y][x].x, grid[y][x].y, PNK);
			x++;
		}
		y++;
	}
}

void	make_orth(t_bigstruct mr_struct, t_coord **grid, t_map *map)
{
	int x;
	int y;
	double unit;

	unit = 40;
	y = 0;

	while(y < map->rows)
	{
		x = 0;
		while(x < map->columns)
		{
			grid[y][x].x = (x * unit) + mr_struct.origin.x;
			grid[y][x].y = (y * unit) + mr_struct.origin.y;
			mlx_pixel_put(mr_struct.mlx, mr_struct.window, grid[y][x].x, grid[y][x].y, 0xFFFFFF);
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
	while (y != map->columns)
	{
		if (!(grid[y] = malloc(sizeof(t_coord) * map->columns)))
			error("not enough memory.");
		y++;
	}
	return(grid);
}

t_coord	**create_grid(t_bigstruct mr_struct, t_map *map, char projection)
{
	t_coord	**grid;
	int		i;

	i = 0;

	grid = malloc_grid(map);
	
	if (projection == 'o')
		make_orth(mr_struct, grid, map);
	else if (projection == 'i')
		make_iso(mr_struct, grid, map);
	else if (projection == 'p')
		make_prsp(mr_struct, grid, map);
	else
		error("something's wrong in create_grid - invalid grid type\n");

	return(grid);
}

