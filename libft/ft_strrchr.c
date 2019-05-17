/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:09:37 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/08 23:47:13 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	r;

	r = ((int)ft_strlen(s));
	while (s[r] != (char)c && r >= -1)
	{
		r--;
		if (r < 0)
			return (NULL);
	}
	return ((char*)s + r);
}
