/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:27:24 by cschulle          #+#    #+#             */
/*   Updated: 2019/07/05 15:27:39 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	get_xunit(t_bigstruct mr_struct, int y)
{
	double	xunit;
	double	slope;

	slope = (PRSP_FRONTEDGE - PRSP_BACKEDGE) / (mr_struct.rows - 1);
	xunit = (slope * (double)y) + PRSP_BACKEDGE;
	xunit *= mr_struct.unit;
	return (xunit * 2);
}

void	make_prsp(t_bigstruct mr_struct, t_coord **grid)
{
	int		x;
	int		y;
	double	y_unit;
	double	x_shift;
	double	owidth;

	y = 0;
	owidth = get_xunit(mr_struct, y) * (mr_struct.columns - 1);
	y_unit = (mr_struct.columns / mr_struct.rows) * (mr_struct.unit);
	while (y < mr_struct.rows)
	{
		x = 0;
		x_shift = (y == 0) ? 0 : ((get_xunit(mr_struct, y)
			* (mr_struct.columns - 1)) - owidth) / 2;
		while (x < mr_struct.columns)
		{
			grid[y][x].x = (mr_struct.origin.x + (x * get_xunit(mr_struct, y)))
				- x_shift;
			grid[y][x].y = ((y * y_unit) + mr_struct.origin.y)
				- (mr_struct.points[y][x].z * mr_struct.z_mod);
			grid[y][x].color = mr_struct.points[y][x].color;
			x++;
		}
		y++;
	}
}

void	make_iso(t_bigstruct mr_struct, t_coord **grid)
{
	int		x;
	int		y;

	y = 0;
	while (y < mr_struct.rows)
	{
		x = 0;
		while (x < mr_struct.columns)
		{
			grid[y][x].x = (((x - y) * cos(0.523599)) * mr_struct.unit)
				+ mr_struct.origin.x;
			grid[y][x].y = (((x + y) * sin(0.523599)) * mr_struct.unit)
				+ mr_struct.origin.y - (mr_struct.points[y][x].z)
				* mr_struct.z_mod;
			grid[y][x].color = mr_struct.points[y][x].color;
			x++;
		}
		y++;
	}
}

void	make_orth(t_bigstruct mr_struct, t_coord **grid)
{
	int		x;
	int		y;

	y = 0;
	while (y < mr_struct.rows)
	{
		x = 0;
		while (x < mr_struct.columns)
		{
			grid[y][x].x = (x * mr_struct.unit) + mr_struct.origin.x;
			grid[y][x].y = (y * mr_struct.unit) + mr_struct.origin.y;
			grid[y][x].color = mr_struct.points[y][x].color;
			x++;
		}
		y++;
	}
}
