/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:43:21 by cschulle          #+#    #+#             */
/*   Updated: 2019/05/30 17:47:33 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Checks if given character is one of the 16 hexadecimal digts.
**	Not case sensitive.
*/

#include "libft.h"

int	ft_ishexdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'A' && c <= 'F')
		return (1);
	if (c >= 'a' && c <= 'f')
		return (1);
	else
		return (0);
}
