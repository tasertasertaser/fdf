/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:18:30 by cschulle          #+#    #+#             */
/*   Updated: 2019/05/30 18:32:20 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Prints description of program error in red.
**	Exits the program.
*/

#include "../includes/fdf.h"

void	error(char *description)
{
	ft_putstr(P_RD);
	ft_putendl(description);
	ft_putstr(P_X);
	exit(1);
}

void	nullcheck(char *string)
{
	if (string == NULL)
		error("could not read file.");
}
