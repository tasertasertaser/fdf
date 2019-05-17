/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:08:44 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/29 18:46:39 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*numstr;
	size_t	i;

	i = ft_numlen(n);
	if (!(numstr = (char *)malloc(i + 1)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	numstr[i] = '\0';
	i--;
	if (n < 0)
	{
		numstr[0] = '-';
		n = n * -1;
	}
	while (n)
	{
		numstr[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (numstr);
}
