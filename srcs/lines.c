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

	y = 0;

	while(y < mr_struct.map->rows)
	{
		x = 0;
		
		while(x < mr_struct.map->columns)
		{
			if ((x + 1) < mr_struct.map->columns)
			{
				line.a.x = grid[y][x].x;
				line.a.y = grid[y][x].y;
				line.a.color = mr_struct.map->points[y][x].color;
				line.b.x = grid[y][x + 1].x;
				line.b.y = grid[y][x + 1].y;
				line.b.color = mr_struct.map->points[y][x + 1].color;
				draw_line(line, mr_struct);
			}
				
			if ((y + 1) < mr_struct.map->rows)
			{
				line.a.x = grid[y][x].x;
				line.a.y = grid[y][x].y;
				line.a.color = mr_struct.map->points[y][x].color;
				line.b.x = grid[y + 1][x].x;
				line.b.y = grid[y + 1][x].y;
				line.b.color = mr_struct.map->points[y + 1][x].color;
				draw_line(line, mr_struct);
			}
			x++;
		}
		y++;
	}

	// y = 0;
	// while(y < mr_struct.map->rows)
	// {
	// 	x = 0;
	// 	while(x < mr_struct.map->columns)
	// 	{
	// 		if(x + 1 <= mr_struct.map->columns)
	// 		{
	// 			line.a.x = grid[y][x].x;
	// 			line.b.x = grid[y][x + 1].x;
	// 			line.a.y = grid[y][x].y;
	// 			line.b.y = grid[y][x + 1].y;
	// 			draw_line(line);
	// 		}
	// 		if(y + 1 <= mr_struct.map->rows)
	// 		{
	// 			line.a.x = grid[y][x].x;
	// 			line.b.x = grid[y + 1][x].x;
	// 			line.a.y = grid[y][x].y;
	// 			line.b.y = grid[y + 1][x].y;
	// 			draw_line(line);
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
}

void	draw_xline(t_line line, t_lineshit lineshit, t_bigstruct mr_struct)
{	
	int x;
	int y;
	int color;
	
	lineshit.len = line.b.x - line.a.x;
	x = line.a.x;
	while(x != line.b.x)
	{
		y = (lineshit.slope * x) + lineshit.intercept;
		color = gradient(line.a.color, line.b.color, lineshit.len, x - line.a.x);
		mlx_pixel_put(mr_struct.mlx, mr_struct.window, x, y, color);
		x += lineshit.sign;
	}
}

void	draw_yline(t_line line, t_lineshit lineshit, t_bigstruct mr_struct)
{
	int x;
	int y;
	int color;

	lineshit.len = line.b.y - line.a.y;
	lineshit.slope = (double)(line.b.x - line.a.x) / (double)(line.b.y - line.a.y);
	lineshit.intercept = ft_round((double)line.b.x - (lineshit.slope * (double)line.b.y));
	y = line.a.y;
	lineshit.sign = (line.b.y - line.a.y) < 0 ? -1 : 1;
	while(y != line.b.y)
	{
		x = (lineshit.slope * y) + lineshit.intercept;
		color = gradient(line.a.color, line.b.color, lineshit.len, y - line.a.y);
		mlx_pixel_put(mr_struct.mlx, mr_struct.window, x, y, color);
		y += lineshit.sign;
	}
}

void	draw_line(t_line line, t_bigstruct mr_struct)
{
	t_lineshit lineshit;

	lineshit.slope = (double)(line.b.y - line.a.y) / (double)(line.b.x - line.a.x);
	lineshit.sign = (line.b.x - line.a.x) < 0 ? -1 : 1;

	lineshit.intercept = ft_round((double)line.b.y - (lineshit.slope * (double)line.b.x));
	if(lineshit.slope <= 1 && lineshit.slope >= -1)
		draw_xline(line, lineshit, mr_struct);
	else
		draw_yline(line, lineshit, mr_struct);
	mlx_pixel_put(mr_struct.mlx, mr_struct.window, line.a.x, line.a.y, line.b.color);
}
