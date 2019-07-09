/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:36:34 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/08 23:35:44 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Takes two strings and compares each character in turn.
**	If the strings are identical, returns 0.
**	If a difference is found, ft_strcmp returns the value of the the first
**	string's character minus the second string's character.
*/

#include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return (0);
	while (s1[i] == s2[i] && (s1[i] && s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
