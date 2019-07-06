/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:55:49 by cschulle          #+#    #+#             */
/*   Updated: 2019/07/05 16:55:51 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Draws a line down the center axis of the window, useful for testing.
**	axis: 'x' = vertical center, 'y' = horizontal center, 'b' = both.
*/

void	draw_centerline(t_bigstruct mr_struct, char axis)
{
	t_line xcenterline;
	t_line ycenterline;

	if (axis == 'x' || axis == 'b')
	{
		xcenterline = (t_line){(t_coord){mr_struct.center_x, 0, GRY},
			(t_coord){mr_struct.center_x, WND_H, GRY}};
		draw_line(xcenterline, mr_struct);
	}
	if (axis == 'y' || axis == 'b')
	{
		ycenterline = (t_line){(t_coord){0, mr_struct.center_y, GRY},
			{WND_W, mr_struct.center_y, GRY}};
		draw_line(ycenterline, mr_struct);
	}
}
