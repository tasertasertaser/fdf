/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:53:04 by cschulle          #+#    #+#             */
/*   Updated: 2019/01/13 18:53:10 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** searches n bytes of given string for given char
** returns pointer to first occurence if found
** returns NULL pointer if not found
*/

#include <unistd.h>

char	*ft_strnchr(const char *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (i + 1 == n || s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char*)s + i);
}
