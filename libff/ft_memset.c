/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:24:14 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/08 23:16:31 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*cc;

	cc = str;
	i = 0;
	while (i < n)
	{
		*cc = c;
		i++;
		cc++;
	}
	return (str);
}
