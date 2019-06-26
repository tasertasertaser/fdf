/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 19:26:37 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/06 18:04:21 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Checks a row (in string form) for valid characters, and checks column count.
**	If -1 is passed as column count, the column count is not checked. // TODO: delete this
**	This allows the function to be called on the first row, before column
**	count has been established.
*/

#include "../includes/fdf.h"

void	valid_check(char *row, int columns)
{
	int		i;

	i = 0;
	if(columns > -1 && columns != ft_wordcount(row, ' '))	// TODO: -1 flag isn't needed. Fix.
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
