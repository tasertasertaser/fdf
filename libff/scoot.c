/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:40:40 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/26 16:41:26 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*scoot(char *string, char delimiter)
{
	char	*scooted;

	scooted = string;
	while (scooted[0] && scooted[0] != delimiter)
		scooted++;
	while (scooted[0] && scooted[0] == delimiter)
		scooted++;
	return (scooted);
}
