/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movekeys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:22:17 by cschulle          #+#    #+#             */
/*   Updated: 2019/07/05 16:22:20 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move(int key, t_bigstruct *mr_struct)
{
	if (key == W_KEY)
		mr_struct->origin.y -= 10;
	if (key == A_KEY)
		mr_struct->origin.x -= 10;
	if (key == S_KEY)
		mr_struct->origin.y += 10;
	if (key == D_KEY)
		mr_struct->origin.x += 10;
}

void	elevate(int key, t_bigstruct *mr_struct)
{
	if (key == J_KEY)
		mr_struct->z_mod--;
	if (key == K_KEY)
		mr_struct->z_mod++;
}

void	zoom(int key, t_bigstruct *mr_struct)
{
	if (key == Z_KEY && mr_struct->unit < ZOOM_MAX)
	{
		mr_struct->unit++;
		mr_struct->z_mod *= 1.05;
	}
	if (key == X_KEY && mr_struct->unit > ZOOM_MIN)
	{
		mr_struct->unit--;
		mr_struct->z_mod *= 0.95;
	}
}

void	plot(int key, t_bigstruct *mr_struct)
{
	mr_struct->proj = key;
	mr_struct->origin = get_origin(*mr_struct, mr_struct->unit);
}

void	reset(t_bigstruct *mr_struct)
{
	mr_struct->unit = get_unit(*mr_struct);
	mr_struct->origin = get_origin(*mr_struct, mr_struct->unit);
	mr_struct->z_mod = 3;
	create_grid(*mr_struct, mr_struct->map, mr_struct->proj);
}
