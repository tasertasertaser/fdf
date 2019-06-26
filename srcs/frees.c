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

// TODO: put in Makefile
// TODO: put decs in header
// TODO: write free_map

void	free_2D(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}