/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:43:14 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/22 19:47:03 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t l;

	if (dstsize == 0 || dstsize - ft_strlen(dst) - 1 <= 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	l = ft_strlen(dst);
	while (src[j] && i + j < dstsize - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	if (dstsize > l)
		return (ft_strlen(src) + l);
	else
		return (ft_strlen(src) + dstsize);
}
