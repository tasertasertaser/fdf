/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:53:32 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/29 18:50:55 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	splits string into substrings as delimited by 'c'
**	returns char ** to array of separated strings
**	the array of strings is null-terminated, as well as each individual string
*/

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;
	char	**rtrn;

	i = 0;
	j = 0;
	k = 0;
	if (!s || !(rtrn = malloc((ft_wordcount(s, c) + 1) * sizeof(char *))))
		return (NULL);
	while (ft_wordcount(s, c) > k && ft_wordcount(s, c) > 0)
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			rtrn[k++] = ft_strsub(s, i, j);
			i = i + j;
		}
	}
	rtrn[ft_wordcount(s, c)] = NULL;
	return (rtrn);
}
