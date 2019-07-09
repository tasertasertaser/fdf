/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:00:55 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/08 23:20:29 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*char_dst;
	unsigned char	*char_src;

	i = 0;
	char_dst = (unsigned char *)dst;
	char_src = (unsigned char *)src;
	if (char_src < char_dst)
	{
		while (len > 0)
		{
			*(char_dst + len - 1) = *(char_src + len - 1);
			len--;
		}
	}
	else
		while (i < len)
		{
			*(char_dst + i) = *(char_src + i);
			i++;
		}
	return (dst);
}
