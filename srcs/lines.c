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
