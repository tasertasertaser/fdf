/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grids.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:55:42 by cschulle          #+#    #+#             */
/*   Updated: 2019/07/05 14:55:44 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	get_unit(t_bigstruct mr_struct)
{
	double	print_width;
	double	unit;

	print_width = (double)WND_W * 0.45;
	unit = print_width / (double)mr_struct.columns;
	return (unit);
}

t_coord	get_origin(t_bigstruct mr_struct, double unit)
{
	int		y;
	int		x;

	if (mr_struct.proj == O_KEY)
		x = ft_round(mr_struct.center_x - unit * (mr_struct.columns / 2));
	else if (mr_struct.proj == I_KEY)
		x = mr_struct.center_x - ((mr_struct.rows
			* (mr_struct.unit * .35)));
	else
	{
		x = mr_struct.center_x - (get_xunit(mr_struct, 0)
			* (mr_struct.columns / 2));
	}
	y = ft_round(mr_struct.center_y - unit * (mr_struct.rows / 2));
	return ((t_coord){x, y, 0});
}

t_coord	**malloc_grid(t_bigstruct mr_struct)
{
	t_coord	**grid;
	int		y;
	int		x;

	y = 0;
	x = 0;
	if (!(grid = malloc(sizeof(t_coord *) * mr_struct.rows)))
		error("not enough memory.");
	while (y != mr_struct.rows)
	{
		if (!(grid[y] = malloc(sizeof(t_coord) * mr_struct.columns)))
			error("not enough memory.");
		y++;
	}
	return (grid);
}

void	create_grid(t_bigstruct mr_struct, char projection)
{
	int		i;

	i = 0;
	clear_image(mr_struct.img);
	if (projection == O_KEY)
		make_orth(mr_struct, mr_struct.grid);
	else if (projection == I_KEY)
		make_iso(mr_struct, mr_struct.grid);
	else if (projection == P_KEY)
		make_prsp(mr_struct, mr_struct.grid);
	else
		error("something's wrong in create_grid - invalid grid type");
	connect(mr_struct.grid, mr_struct);
	mlx_put_image_to_window(mr_struct.mlx, mr_struct.wn,
		mr_struct.img->imptr, 0, 0);
}
