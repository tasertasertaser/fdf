/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:54:08 by cschulle          #+#    #+#             */
/*   Updated: 2019/07/05 14:54:10 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	exit_fdf(t_bigstruct *mr_struct)
{
	free_grid(mr_struct->grid, *mr_struct);
	mlx_destroy_image(mr_struct->mlx, mr_struct->img);
	mlx_destroy_window(mr_struct->mlx, mr_struct->wn);
	exit(0);
}

void	helpmenu(t_bigstruct *mr_struct)
{
	if (!mr_struct->helptoggle)
	{
		help(mr_struct);
		mr_struct->helptoggle = 1;
		mlx_string_put(mr_struct->mlx, mr_struct->wn, WND_W
			- 230, WND_H + 40, GRY, "Press \"H\" to exit");
	}
	else
	{
		mlx_clear_window(mr_struct->mlx, mr_struct->wn);
		mr_struct->helptoggle = 0;
		mlx_string_put(mr_struct->mlx, mr_struct->wn, WND_W
			- 230, WND_H + 40, GRY, "Press \"H\" for help");
		mlx_string_put(mr_struct->mlx, mr_struct->wn, 40,
		WND_H + 40, GRY, mr_struct->file);
		create_grid(*mr_struct, mr_struct->proj);
	}
}

int		key_press(int key, t_bigstruct *mr_struct)
{
	if (key == ESC_KEY)
		exit_fdf(mr_struct);
	else if (key == H_KEY)
		helpmenu(mr_struct);
	else
	{
		if (key == SPACE_KEY)
			reset(mr_struct);
		if (key == I_KEY || key == O_KEY || key == P_KEY)
			plot(key, mr_struct);
		if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
			move(key, mr_struct);
		if (key == J_KEY || key == K_KEY)
			elevate(key, mr_struct);
		if (key == Z_KEY || key == X_KEY)
			zoom(key, mr_struct);
		if (key == C_KEY)
			color_cycle(mr_struct);
		if ((key >= 82 && key <= 92 && key != 90) ||
			(key >= 18 && key <= 29 && key != 24))
			color_select(key, mr_struct);
		create_grid(*mr_struct, mr_struct->proj);
	}
	return (key);
}
