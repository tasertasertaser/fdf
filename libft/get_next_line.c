/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:50:02 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/01 11:53:48 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** WHAT THIS DOES
** -
** 1. takes pointer-to-pointer (**line) and file descriptor (fd) as argument
** 2. reads BUFF_SIZE characters into a buffer
** 3. adds contents of buf to string (**line), continuing until '\n' is found
** 		• **line now points at 1 line of the file (to be printed by main())
** 4. stores remaining buf chars in a static array (extra[fd]) for next fn call
** 5. return value (int) is just a flag for whether op was successful
**		•  1 = line was read
**		•  0 = file has been completely read
**		• -1 = an error occurred
** -
*/

#include "libft.h"

void	ft_strcjoinfree(char **old, char *new, char c)
{
	char	*tmp;

	tmp = *old;
	*old = ft_strcjoin(*old, new, c);
	free(tmp);
}

int		bufreader(const int fd, char **extra, char **line)
{
	char			buf[BUFF_SIZE + 1];
	size_t			i;

	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		buf[i] = '\0';
		if (!(ft_strchr(buf, '\n')))
			if (!*line)
				*line = ft_strdup(buf);
			else
				ft_strcjoinfree(line, buf, '\0');
		else
		{
			(!*line) ? *line = ft_strdup("\0") : 0;
			ft_strcjoinfree(line, buf, '\n');
			(extra[fd]) ? free(extra[fd]) : 0;
			extra[fd] = ft_strdup((ft_strchr(buf, '\n')) + 1);
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*extra[FD_MAX + 1];

	if (!line || fd < 0 || fd > FD_MAX ||
			read(fd, extra[fd], 0) < 0 || !(*line = ft_strnew(1)))
		return (-1);
	if (extra[fd])
	{
		if ((extra[FD_MAX] = ft_strchr(extra[fd], '\n')))
		{
			extra[FD_MAX][0] = '\0';
			*line = ft_strdup(extra[fd]);
			extra[fd] = ft_strdup(extra[FD_MAX] + 1);
			return (1);
		}
		(*line) ? free(*line) : 0;
		*line = ft_strdup(extra[fd]);
		(extra[fd]) ? free(extra[fd]) : 0;
		extra[fd] = ft_strdup("\0");
	}
	if (bufreader(fd, extra, line) == 1)
		return (1);
	else if (*line == NULL || **line == '\0')
		return (0);
	else
		return (1);
}
