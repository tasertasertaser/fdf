/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 19:32:33 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/01 12:03:32 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Takes a string representing an int value, and an int representing
**		the base of the input string.
**	Iterates through spaces and signal characters to the beginning of
**		the numeric string.
**	Accounts for negative (-) value.
**	Returns the int value of the numeric string (defaults to base 10).
*/

#include "libft.h"

int	numstart(char *str)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
	{
		i++;
		if (str[i] == '-')
			return (0);
	}
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (ft_strncmp(str, "0x", 2) == 0)
		i += 2;
	if (!(ft_isalpha(str[i]) || ft_isdigit(str[i])))
		return (0);
	return (i * sign);
}

int	digitconvert(char c)
{
	if (ft_isupper(c))
		return (10 + (c - 'A'));
	else if (ft_islower(c))
		return (10 + (c - 'a'));
	else
		return (c - 48);
}

int	ft_atoibase(char *str, int base)
{
	int				i;
	int				j;
	int				sign;
	int				place;
	unsigned long	num;

	i = numstart(str);
	sign = (i < 0) ? -1 : 1;
	i = (sign == -1) ? (i * sign) : i;
	j = i;
	while (str[j] && (ft_isalpha(str[j]) || ft_isdigit(str[j])))
		j++;
	j--;
	place = 1;
	num = 0;
	while (j >= i)
	{
		num += digitconvert(str[j]) * place;
		place *= base;
		j--;
	}
	return ((int)num * sign);
}
