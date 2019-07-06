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

void	draw_xline(t_line line, t_lineshit lineshit, t_bigstruct mr_struct)
{
	int	x;
	int	y;
	int	color;

	lineshit.len = line.b.x - line.a.x;
	x = line.a.x;
	while (x != line.b.x)
	{
		y = (lineshit.slope * x) + lineshit.intr;
		color = gradient(line.a.color, line.b.color,
			lineshit.len, x - line.a.x);
		drawpixel(mr_struct.img, x, y, color);
		x += lineshit.sign;
	}
}

void	draw_yline(t_line line, t_lineshit lineshit, t_bigstruct mr_struct)
{
	int x;
	int y;
	int color;

	lineshit.len = line.b.y - line.a.y;
	lineshit.slope = (double)(line.b.x - line.a.x)
		/ (double)(line.b.y - line.a.y);
	lineshit.intr = ft_round((double)line.b.x
		- (lineshit.slope * (double)line.b.y));
	y = line.a.y;
	lineshit.sign = (line.b.y - line.a.y) < 0 ? -1 : 1;
	while (y != line.b.y)
	{
		x = (lineshit.slope * y) + lineshit.intr;
		color = gradient(line.a.color, line.b.color,
		lineshit.len, y - line.a.y);
		drawpixel(mr_struct.img, x, y, color);
		y += lineshit.sign;
	}
}

void	draw_line(t_line line, t_bigstruct mr_struct)
{
	t_lineshit lineshit;

	lineshit.slope = (double)(line.b.y - line.a.y)
		/ (double)(line.b.x - line.a.x);
	lineshit.sign = (line.b.x - line.a.x) < 0 ? -1 : 1;
	lineshit.intr = ft_round((double)line.b.y
		- (lineshit.slope * (double)line.b.x));
	if (lineshit.slope <= 1 && lineshit.slope >= -1)
		draw_xline(line, lineshit, mr_struct);
	else
		draw_yline(line, lineshit, mr_struct);
	drawpixel(mr_struct.img, line.b.x, line.b.y, line.b.color);
}
