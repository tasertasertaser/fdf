/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 19:26:37 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/01 12:23:06 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

void	valid_check(char *row, int columns)
{
	int		i;

	i = 0;
	if(columns > -1 && columns != ft_wordcount(row, ' '))
		error("bad file: inconsistent column count.");
	while (row[i])
	{
		if (row[i] == ' ' || (ft_ishexdigit(row[i])) || row[i] == '-'\
			|| row[i] == 'x' || row[i] == ',')
			i++;
		else
			error("bad file: forbidden character.");
	}
}
