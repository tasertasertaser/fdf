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

int zcolor(int z, int highest, int lowest)
{
	int	color;
	int len;

	len = highest - lowest;
	if(!COLORS_ON)
		color = 0xFFFFFF;
	else
		color = gradient(MINCOLOR, MAXCOLOR, len, z);
	return (color);
}
