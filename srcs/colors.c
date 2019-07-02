/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 21:35:29 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/08 18:57:55 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	gradient(int startcolor, int endcolor, int len, int pos)
{
	float increment[3];
	int new[3];
	int newcolor;

	increment[0] = (float)((R(endcolor)) - (R(startcolor))) / (float)len;
	increment[1] = (float)((G(endcolor)) - (G(startcolor))) / (float)len;
	increment[2] = (float)((B(endcolor)) - (B(startcolor))) / (float)len;

	new[0] = (R(startcolor)) + ft_round(pos * increment[0]);
	new[1] = (G(startcolor)) + ft_round(pos * increment[1]);
	new[2] = (B(startcolor)) + ft_round(pos * increment[2]);

	newcolor = RGB(new[0], new[1], new[2]);

	return (newcolor);
}

int zcolor(t_bigstruct mr_struct, int x, int y)
{
	int	color;
	int len;
	float mid_z;

	mid_z = AVG((float)mr_struct.map->max_z, (float)mr_struct.map->min_z);
	len = mr_struct.map->max_z - mr_struct.map->min_z;
	if (mr_struct.clr == 1)
	{
		if (mr_struct.map->points[y][x].z >= mid_z)
			color = gradient(YLW, PNK, len, mr_struct.map->points[y][x].z);
		else
			color = gradient(WHT, YLW, len, mr_struct.map->points[y][x].z);
	}
	if (mr_struct.clr == 2)
	{
		if (mr_struct.map->points[y][x].z >= mid_z)
			color = gradient(ORN, YLW, len, mr_struct.map->points[y][x].z);
		else
			color = gradient(GRY, ORN, len, mr_struct.map->points[y][x].z);
	}
	if (mr_struct.clr == 3)
	{
		if (mr_struct.map->points[y][x].z >= mid_z)
			color = gradient(GRY, AQU, len, mr_struct.map->points[y][x].z);
		else
			color = gradient(0x000000, GRY, len, mr_struct.map->points[y][x].z);
	}
	return (color);
}

// int zcolor(t_bigstruct mr_struct, int x, int y)
// {
// 	int	color;
// 	int len;
// 	float mid_z;

// 	mid_z = AVG((float)mr_struct.map->max_z, (float)mr_struct.map->min_z);
// 	len = mr_struct.map->max_z - mr_struct.map->min_z;
// 	if (mr_struct.map->points[y][x].z >= mid_z)
// 		color = gradient(MIDCOLOR, MAXCOLOR, len, mr_struct.map->points[y][x].z);
// 	else
// 		color = gradient(MINCOLOR, MIDCOLOR, len, mr_struct.map->points[y][x].z);
// 	return (color);
// }

// int zcolor(t_bigstruct mr_struct, int x, int y)
// {
// 	int	color;
// 	int len;
// 	float mid_z;

// 	mid_z = AVG((float)mr_struct.map->max_z, (float)mr_struct.map->min_z);
// 	len = mr_struct.map->max_z - mr_struct.map->min_z;
// 	if (mr_struct.map->points[y][x].z >= mid_z)
// 		color = gradient(MIDCOLOR, MAXCOLOR, len, mr_struct.map->points[y][x].z);
// 	else
// 		color = gradient(MINCOLOR, MIDCOLOR, len, mr_struct.map->points[y][x].z);
// 	return (color);
// }