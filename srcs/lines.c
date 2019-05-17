/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 21:24:56 by cschulle          #+#    #+#             */
/*   Updated: 2019/05/16 21:24:59 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int linelen(t_line *line)
{
	int points[4];
	int delta_Y;
	int delta_X;
	int len;

	points[0] = line->x0;
	points[1] = line->y0;
	points[2] = line->x1;
	points[3] = line->y1;

	delta_Y = points[3] - points[1];
	delta_X = points[2] - points[0];

	len = MAX(ABSOLUTE(delta_Y), ABSOLUTE(delta_X));

	return (len);
}

t_line *make_line(int x0, int y0, int x1, int y1)
{
	t_line *line;
	if((line = malloc(sizeof(t_line))))
	{
		char slope_type;
		double slope;
		int intercept;

		if(ABSOLUTE(x1 - x0) > ABSOLUTE(y1 - y0))
		{
			slope = (y1 - y0) / (x1 - x0);
			intercept = y1 + ((slope * -1) * x1);
			slope_type = 'x';
		}
		else
		{
			slope = (x1 - x0) / (y1 - y0);
			intercept = x1 + ((slope * -1) * y1);
			slope_type = 'y';
		}
		*line = (t_line){x0, y0, x1, y1, slope_type, slope, intercept, 0xFFFFFF};
		return (line);
	}
	else
		return (NULL);
}

void	draw_line(t_line* line, void *mlx, void *window)
{
	int x;
	int y;

	if(line->slope_type == 'x')
	{
		x = line->x0;
		while(x < line->x1)
		{
			y = (line->slope * x) + line->intercept;
			mlx_pixel_put(mlx, window, x, y, line->color);
			x++;
		}
	}
	if(line->slope_type == 'y')
	{
		y = line->y0;
		while(y < line->y1)
		{
			x = (line->slope * x) + line->intercept;
			mlx_pixel_put(mlx, window, x, y, line->color);
			y++;
		}
	}
	mlx_pixel_put(mlx, window, line->x0, line->y0, line->color);
	mlx_pixel_put(mlx, window, line->x1, line->y1, line->color);
}

void	draw_gradient_line(t_line* line, void *mlx, void *window, int endcolor)
{
	int x;
	int y;

	if(line->slope_type == 'x')
	{
		x = line->x0;
		while(x < line->x1)
		{
			y = (line->slope * x) + line->intercept;
			line->color = gradient(line->color, endcolor, linelen(line), ABSOLUTE(x - line->x0));
			mlx_pixel_put(mlx, window, x, y, line->color);
			x++;
		}
	}
	if(line->slope_type == 'y')
	{
		y = line->y0;
		while(y < line->y1)
		{
			x = (line->slope * x) + line->intercept;
			line->color = gradient(line->color, endcolor, linelen(line), ABSOLUTE(y - line->y0));
			mlx_pixel_put(mlx, window, x, y, line->color);
			y++;
		}
	}
	mlx_pixel_put(mlx, window, line->x0, line->y0, line->color);
	mlx_pixel_put(mlx, window, line->x1, line->y1, line->color);
}

