/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:45:28 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/08 23:33:47 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	reads the given string to find the first occurence of char c
**	returns a pointer to the position after that
*/

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char*)s + i);
}
