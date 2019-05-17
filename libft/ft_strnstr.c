/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:03:23 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/24 19:10:15 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!*needle || haystack == needle)
		return (char *)(haystack);
	while (haystack[i] && len > i)
	{
		j = 0;
		while (haystack[i] == needle[j] && haystack[i] && len > i)
		{
			i++;
			j++;
		}
		if (!needle[j])
			return (char *)(haystack + i - j);
		i = (i - j) + 1;
	}
	return (NULL);
}
