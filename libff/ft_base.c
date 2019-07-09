/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 15:15:51 by cschulle          #+#    #+#             */
/*   Updated: 2019/05/11 17:08:59 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	How Hexadecimal Works
**      0 1 2 3 4 5 6 7 8 9  A  B  C  D  E  F
**                          10 11 12 13 14 15
**
**	Converting 348 to Hexadecimal
**                  remainder
**                  ▾   symbol (reverse these!)
**                  ▾   ▾
**	348 / 16 = 21 | 12  C
**	 21 / 16 =  1 | 5   5
**	  1 / 16 =  0 | 1   1
**
** 	348 base 10 = 15C base 16
**
**	note: intmax in base 2 is 32 digits,
**		so max string length is 33 chars when null term'd.
**	This function WILL BREAK when passed an int greater than 32-bit intmax.
*/

#include "libft.h"

char	*ft_base(int num, int base)
{
	size_t	i;
	char	*tmp;
	char	*converted;

	if (!(tmp = (char *)malloc(sizeof(char) * 33)))
		return (NULL);
	tmp[32] = '\0';
	i = 31;
	while (num > 0)
	{
		if (num % base <= 9)
			tmp[i] = (num % base) + '0';
		else
			tmp[i] = (num % base) + 'W';
		num /= base;
		i--;
	}
	converted = ft_strcpy(ft_strnew(16 - i), tmp + i + 1);
	free(tmp);
	return (converted);
}
