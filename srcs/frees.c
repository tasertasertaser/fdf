/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:33:58 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/06 16:01:24 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Functions to free allocated stuff.
*/

#include "../includes/fdf.h"

void	free_grid(t_coord **grid, t_bigstruct mr_struct)
{
	int y;

	y = 0;
	while (y < mr_struct.rows)
	{
		free(grid[y]);
		y++;
	}
	free(grid);
}
