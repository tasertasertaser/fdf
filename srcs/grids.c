#include "../includes/fdf.h"

double	get_unit(t_bigstruct mr_struct)
{
	double print_width = (double)WINDOW_W * 0.45;
	double unit = print_width / (double)mr_struct.map->columns;
	return (unit);
}

t_coord	get_origin(t_bigstruct mr_struct, double unit)
{
	int x = ft_round(mr_struct.center_x - unit * (mr_struct.map->columns / 2));
	int y = ft_round(mr_struct.center_y - unit * (mr_struct.map->rows / 2));

	printf(P_GR"origin: %d, %d\n"P_X, x, y);
	return ((t_coord){x, y, WHT});
}

double get_xunit(t_bigstruct mr_struct, int y, double unit)
{
	double xunit;
	double slope;

	slope = (PRSP_FRONTEDGE - PRSP_BACKEDGE) / (mr_struct.map->rows - 1);
	xunit = (slope * (double)y) + PRSP_BACKEDGE;
	xunit *= unit;
	return (xunit);
}
// http://faculty.cs.tamu.edu/jchai/cpsc641_spring10/PerspectiveProjection.pdf
void	make_prsp(t_bigstruct mr_struct, t_coord **grid, t_map *map)
{
	int x;
	int y;
	double unit;
	double x_unit;
	double y_unit;
	double x_shift;
	double totalwidth;

	unit = get_unit(mr_struct);
	y = 0;

		x_shift = unit;
	while(y < map->rows)
	{
		x = 0;
		y_unit = (unit/2) + y;
		x_unit = get_xunit(mr_struct, y, unit);
		x_shift = (y == 0) ? 0 : totalwidth/2;
		while(x < map->columns)
		{
			//grid[y][x].x = ((x * unit) + mr_struct.origin.x) < mr_struct.center_x ? ((mr_struct.center_x - ((x + 1) * x_unit))) : ((mr_struct.center_x + ((x - (map->columns / 2)) * x_unit)));
			grid[y][x].x = (mr_struct.origin.x + (x * x_unit)) - x_shift;
			grid[y][x].y = ((y * y_unit) + mr_struct.origin.y); // - (map->points[y][x].z * y_unit);
			grid[y][x].color = map->points[y][x].color;
			mlx_pixel_put(mr_struct.mlx, mr_struct.window, grid[y][x].x, grid[y][x].y, BLU);
			x++;
			totalwidth = x_unit * (map->columns - 1);
		}
		y++;
	}	
}

void	make_iso(t_bigstruct mr_struct, t_coord **grid, t_map *map)
{
	int x;
	int y;
	double unit;

	unit = get_unit(mr_struct);
	y = 0;
	
	while(y < map->rows)
	{
		x = 0;
		while(x < map->columns)
		{
			grid[y][x].x = (((x - y) * cos(0.523599)) * unit) + mr_struct.origin.x;
			grid[y][x].y = (((x + y) * sin(0.523599)) * unit) + mr_struct.origin.y - (map->points[y][x].z) * mr_struct.z_mod;
			grid[y][x].color = map->points[y][x].color;
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

	unit = get_unit(mr_struct);
	y = 0;

	while(y < map->rows)
	{
		x = 0;
		while(x < map->columns)
		{
			grid[y][x].x = (x * unit) + mr_struct.origin.x;
			grid[y][x].y = (y * unit) + mr_struct.origin.y;
			grid[y][x].color = map->points[y][x].color;
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
	t_coord	**grid;
	int		i;

	i = 0;

	grid = malloc_grid(map);
	
	draw_centerline(mr_struct, 'b');

	if (mr_struct.reset == 0)
		mr_struct.origin = get_origin(mr_struct, get_unit(mr_struct));
	if (projection == 'o')
		make_orth(mr_struct, grid, map);
	else if (projection == 'i')
		make_iso(mr_struct, grid, map);
	else if (projection == 'p')
		make_prsp(mr_struct, grid, map);
	else
		error("something's wrong in create_grid - invalid grid type\n");

	connect(grid, mr_struct);
	free_grid(grid, mr_struct);
}

