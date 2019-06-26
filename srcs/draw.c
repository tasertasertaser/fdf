/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:30:44 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/08 20:57:25 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Draws an orthographic (top-down) projection of the map
*/

void	print_flat_map(t_window wnd, t_map *map)
{
	int x;
	int y;
	t_line	line;

	line.mlx = wnd.mlx;
	line.window = wnd.window;
	y = 0;
	while(y < map->rows)
	{
		x = 0;
		while(x < map->columns)
		{
			if(x+1 <= map->columns)
			{
				line.x[0] = x * UNIT;
				line.x[1] = (x + 1) * UNIT;
				line.y[0] = y * UNIT;
				line.y[1] = y * UNIT;
				draw_line(line);
			}
			if(y+1 <= map->rows)
			{
				line.x[0] = x * UNIT;
				line.x[1] = x * UNIT;
				line.y[0] = y * UNIT;
				line.y[1] = (y+1) * UNIT;
				draw_line(line);
			}
			x++;
		}
		y++;
	}
}

/*
**	Performs an isometric transformation on each point before it is drawn.
**	http://clintbellanger.net/articles/isometric_math/
**
**		One option: create a grid[][] of points, and map each point onto that grid
**		that seems like it's way too many operations & will make the program too slow to run?
*/

void	print_iso_map(t_window wnd, t_map *map)
{
	int x;
	int ix;
	int y;
	int iy;
	t_line	line;

	line.mlx = wnd.mlx;
	line.window = wnd.window;
	y = 0;
	while(y < map->rows)
	{
		x = 0;
		while(x < map->columns)
		{
			ix = (x + y) * cos(0.523599);
			iy = (x - y) * sin(0.523599);
			if(x+1 <= map->columns)
			{
				line.x[0] = ix * UNIT;
				line.x[1] = (ix + 1) * UNIT;
				line.y[0] = iy * UNIT;
				line.y[1] = iy * UNIT;
				draw_line(line);
			}
			if(y+1 <= map->rows)
			{
				line.x[0] = ix * UNIT;
				line.x[1] = ix * UNIT;
				line.y[0] = iy * UNIT;
				line.y[1] = (iy+1) * UNIT;
				draw_line(line);
			}
			x++;
		}
		y++;
	}
}
