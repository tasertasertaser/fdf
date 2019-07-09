/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:23:33 by cschulle          #+#    #+#             */
/*   Updated: 2019/07/05 14:23:38 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	x_connect(int x, int y, t_coord **grid, t_bigstruct mr_struct)
{
	t_line	line;

	line.a.x = grid[y][x].x;
	line.a.y = grid[y][x].y;
	if (mr_struct.clr)
		line.a.color = zcolor(mr_struct, x, y);
	else
		line.a.color = mr_struct.points[y][x].color;
	line.b.x = grid[y][x + 1].x;
	line.b.y = grid[y][x + 1].y;
	if (mr_struct.clr)
		line.b.color = zcolor(mr_struct, x + 1, y);
	else
		line.b.color = mr_struct.points[y][x + 1].color;
	draw_line(line, mr_struct);
}

void	y_connect(int x, int y, t_coord **grid, t_bigstruct mr_struct)
{
	t_line	line;

	line.a.x = grid[y][x].x;
	line.a.y = grid[y][x].y;
	if (mr_struct.clr)
		line.a.color = zcolor(mr_struct, x, y);
	else
		line.a.color = mr_struct.points[y][x].color;
	line.b.x = grid[y + 1][x].x;
	line.b.y = grid[y + 1][x].y;
	if (mr_struct.clr)
		line.b.color = zcolor(mr_struct, x, y + 1);
	else
		line.b.color = mr_struct.points[y + 1][x].color;
	draw_line(line, mr_struct);
}

void	connect(t_coord **grid, t_bigstruct mr_struct)
{
	int		x;
	int		y;

	y = 0;
	while (y < mr_struct.rows)
	{
		x = 0;
		while (x < mr_struct.columns)
		{
			if ((x + 1) < mr_struct.columns)
				x_connect(x, y, grid, mr_struct);
			if ((y + 1) < mr_struct.rows)
				y_connect(x, y, grid, mr_struct);
			x++;
		}
		y++;
	}
}
