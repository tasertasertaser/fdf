/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gttdl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:00:45 by cschulle          #+#    #+#             */
/*   Updated: 2019/07/09 15:00:47 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*getthedamnline(int fd)
{
	static char		bigbuf[(unsigned short)-1] = {0};
	char			smolbuf;
	unsigned long	k;

	smolbuf = 0;
	k = 0;
	while ((read(fd, &smolbuf, 1) > 0) && k < sizeof(bigbuf)
		/ sizeof(bigbuf[0]))
	{
		if (smolbuf == '\n')
			break ;
		bigbuf[k++] = smolbuf;
	}
	bigbuf[k] = 0;
	if (k == 0)
		return (NULL);
	return (ft_strdup(bigbuf));
}
