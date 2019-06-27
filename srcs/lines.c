/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 21:24:56 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/08 20:47:36 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	connect(t_coord **grid, t_bigstruct mr_struct)
{
	int x;
	int y;
	t_line	line;

	line.mlx = mr_struct.mlx;
	line.window = mr_struct.window;
	x = 0;
	y = 0;

	line.x[0] = grid[y][x].x;
	line.x[1] = grid[y][x + 1].x;
	line.y[0] = grid[y][x].y;
	line.y[1] = grid[y][x + 1].y;
	draw_line(line);

	// y = 0;
	// while(y < mr_struct.map->rows)
	// {
	// 	x = 0;
	// 	while(x < mr_struct.map->columns)
	// 	{
	// 		if(x + 1 <= mr_struct.map->columns)
	// 		{
	// 			line.x[0] = grid[y][x].x;
	// 			line.x[1] = grid[y][x + 1].x;
	// 			line.y[0] = grid[y][x].y;
	// 			line.y[1] = grid[y][x + 1].y;
	// 			draw_line(line);
	// 		}
	// 		if(y + 1 <= mr_struct.map->rows)
	// 		{
	// 			line.x[0] = grid[y][x].x;
	// 			line.x[1] = grid[y + 1][x].x;
	// 			line.y[0] = grid[y][x].y;
	// 			line.y[1] = grid[y + 1][x].y;
	// 			draw_line(line);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
}

void	draw_line(t_line line)
{
	int		x;
	int		y;
	double	slope;
	int		intercept;
	int		sign;

	slope = (double)(line.y[1] - line.y[0]) / (double)(line.x[1] - line.x[0]);
	sign = (line.x[1] - line.x[0]) < 0 ? -1 : 1;

	intercept = ft_round((double)line.y[1] - (slope * (double)line.x[1]));
	if(slope <= 1 && slope >= -1)
	{
		x = line.x[0];
		while(x != line.x[1])
		{
			y = (slope * x) + intercept;
			mlx_pixel_put(line.mlx, line.window, x, y, 0xFFFFFF);
			x += sign;
		}
	}
	else
	{
		slope = (double)(line.x[1] - line.x[0]) / (double)(line.y[1] - line.y[0]);
		intercept = ft_round((double)line.x[1] - (slope * (double)line.y[1]));
		y = line.y[0];
		sign = (line.y[1] - line.y[0]) < 0 ? -1 : 1;
		while(y != line.y[1])
		{
			x = (slope * y) + intercept;
			mlx_pixel_put(line.mlx, line.window, x, y, 0xFFFFFF);
			y += sign;
		}
	}
	mlx_pixel_put(line.mlx, line.window, line.x[0], line.y[0], 0xFFFFFF);
}
