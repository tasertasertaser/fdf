/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:17:48 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/22 18:18:56 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	if (!s)
		return (NULL);
	j = (int)(ft_strlen(s) - 1);
	while (ft_iswhitespace(s[i]))
		i++;
	if (s[i] == '\0')
	{
		trimmed = ft_strnew(0);
		return (trimmed);
	}
	while (ft_iswhitespace(s[j]))
		j--;
	j++;
	trimmed = ft_strsub(s, i, ((size_t)(j - i)));
	return (trimmed);
}
