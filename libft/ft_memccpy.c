/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:08:55 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/22 20:01:23 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*fsrc;
	unsigned char	*fdst;

	fsrc = (unsigned char *)src;
	fdst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*(fdst + i) = *(fsrc + i);
		if (*(fsrc + i) == (unsigned char)c)
			return (dst + i + 1);
		else
			i++;
	}
	return (NULL);
}
