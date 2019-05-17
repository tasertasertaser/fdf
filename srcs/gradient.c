/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 21:35:29 by cschulle          #+#    #+#             */
/*   Updated: 2019/05/16 21:35:31 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double increment[3];
	int new[3];
	int newcolor;

	increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
	increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
	increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;

	new[0] = (R(startcolor)) + ft_round(pix * increment[0]);
	new[1] = (G(startcolor)) + ft_round(pix * increment[1]);
	new[2] = (B(startcolor)) + ft_round(pix * increment[2]);

	newcolor = RGB(new[0], new[1], new[2]);

	return (newcolor);
}