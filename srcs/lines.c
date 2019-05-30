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

int linelen(t_pt start, t_pt end)
{
	return (MAX(ABSOLUTE(end.y - start.y), ABSOLUTE(end.x - start.x)));
}

/*t_line *make_line(t_pt start, t_pt end)
{
	t_line *line;
	if((line = malloc(sizeof(t_line))))
	{
		char slope_type;
		double slope;
		int intercept;

		if(ABSOLUTE(end.x - start.x) >= ABSOLUTE(end.y - start.y))
		{
			slope = (double)(end.y - start.y) / (double)(end.x - start.x);
			intercept = end.y + ((slope * -1) * end.x);
			slope_type = 'x';
		}
		else
		{
			slope = (double)(end.x - start.x) / (double)(end.y - start.y);
			intercept = end.x + ((slope * -1) * end.y);
			slope_type = 'y';
		}
		*line = (t_line){start, end, slope_type, slope, intercept};

		printf(P_RED"line made\n"P_XCOLOR);												//tests
		printf(P_YELLOW"startpoint:"P_XCOLOR" %d, %d\n", line->start.x, line->start.y); //
		printf(P_YELLOW"endpoint:"P_XCOLOR" %d, %d\n", line->end.x, line->end.y);		//
		printf(P_YELLOW"type:"P_XCOLOR" %c\n", line->slope_type);						//
		printf(P_YELLOW"slope:"P_XCOLOR" %f\n", line->slope);							//
		printf(P_YELLOW"intercept:"P_XCOLOR" %d\n", line->intercept);					//
		printf(P_YELLOW"color:"P_XCOLOR" %x\n", line->start.color);						//

		return (line);
	}
	else
		return (NULL);
}
*/

// void	backcheck(t_pt start, t_pt end)
// {
// 	t_pt tmp;
// 	if()
// }

void	draw_line(t_pt start, t_pt end, void *mlx, void *window)
{
	int		x;
	int		y;
	double	slope;
	int		intercept;
	int		sign;

	slope = (double)(end.y - start.y) / (double)(end.x - start.x);
	sign = (end.x - start.x) < 0 ? -1 : 1;

	intercept = ft_round((double)end.y - (slope * (double)end.x));
	if(slope <= 1 && slope >= -1)
	{
		x = start.x;
		while(x != end.x)
		{
			y = (slope * x) + intercept;
			mlx_pixel_put(mlx, window, x, y, start.color);
			x += sign;
		}
	}
	else
	{
		slope = (double)(end.x - start.x) / (double)(end.y - start.y);
		intercept = ft_round((double)end.x - (slope * (double)end.y));
		y = start.y;
		sign = (end.y - start.y) < 0 ? -1 : 1;
		while(y != end.y)
		{
			x = (slope * y) + intercept;
			mlx_pixel_put(mlx, window, x, y, start.color);
			y += sign;
		}
	}
	mlx_pixel_put(mlx, window, start.x, start.y, start.color);
}
/*
void	draw_gradient_line(t_line* line, void *mlx, void *window)
{
	int x;
	int y;
	int color;

	if(line->slope_type == 'x')
	{
		x = line->start.x;
		while(x < line->end.x)
		{
			color = gradient(line->start.color, line->end.color, linelen(line), ABSOLUTE(x - line->start.x));
			y = (line->slope * x) + line->intercept;
			mlx_pixel_put(mlx, window, x, y, color);
			x++;
		}
	}
	if(line->slope_type == 'y')
	{
		y = line->start.y;
		while(y < line->end.y)
		{
			x = (line->slope * y) + line->intercept;
			mlx_pixel_put(mlx, window, x, y, line->start.color);
			y++;
		}
	}
	mlx_pixel_put(mlx, window, line->start.x, line->start.y, line->start.color);
	mlx_pixel_put(mlx, window, line->end.x, line->end.y, line->end.color);
}
*/