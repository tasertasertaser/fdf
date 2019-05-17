/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:56:36 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/29 18:45:14 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	i = (ft_strlen(s1));
	len = i + (ft_strlen(s2)) + 1;
	if (!(fresh = (char *)malloc(len + 1)))
		return (NULL);
	ft_strcpy(fresh, s1);
	ft_strcpy(&fresh[i], s2);
	fresh[len] = '\0';
	return (fresh);
}
