/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:58:13 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/07 21:58:59 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*fresh;
	size_t	i;
	size_t	len;

	if (!s1 || !s1[0])
		i = 0;
	else
		i = (ft_strlen(s1));
	len = i + (ft_strlen(s2)) + 1;
	if (!(fresh = (char *)malloc(len + 1)))
		return (NULL);
	if (s1)
		ft_strcpy(fresh, s1);
	ft_strcpy(&fresh[i], s2);
	fresh[len] = '\0';
	return (fresh);
}
