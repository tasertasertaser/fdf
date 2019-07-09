/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:33:31 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/08 20:46:17 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_point(char *str, t_pt *point)
{
	char	*color;

	point->z = ft_atoi(str);
	if ((color = ft_strchr(str, 'x')))
		point->color = (ft_atoibase(color, 16));
	else
		point->color = 0xFFFFFF;
}

void	process_filestring(char *filestring, t_bigstruct *mr_struct)
{
	int		y;
	int		x;
	int		i;
	char	*pt;

	y = 0;
	i = 0;
	pt = filestring;
	nullcheck(filestring);
	while (y < mr_struct->rows)
	{
		x = 0;
		while (x < mr_struct->columns)
		{
			fill_point(pt, &mr_struct->points[y][x]);
			if (mr_struct->max_z < mr_struct->points[y][x].z)
				mr_struct->max_z = mr_struct->points[y][x].z;
			if (mr_struct->min_z > mr_struct->points[y][x].z)
				mr_struct->min_z = mr_struct->points[y][x].z;
			pt = scoot(pt, ' ');
			x++;
		}
		y++;
	}
}

/*
**	Combines current file row and filestring, adding separating space.
*/

char	*add_row(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoinfree(s2, " ");
	s1 = ft_strjoinfree(s1, tmp);
	free(tmp);
	return (s1);
}

/*
**	Allocates sufficient memory for map's 2-D array of points.
*/

void	malloc_map(t_bigstruct *mr_struct)
{
	int	y;

	y = 0;
	if (!(mr_struct->points = malloc(sizeof(t_pt) * mr_struct->rows)))
		error("failed to parse. not enough memory.");
	while (y != mr_struct->rows)
	{
		if (!(mr_struct->points[y] = malloc(sizeof(t_pt) * mr_struct->columns)))
			error("failed to parse. not enough memory.");
		y++;
	}
}

void	parse(char *filename, t_bigstruct *mr_struct)
{
	int		fd;
	char	*line;
	char	*oldfs;
	char	*filestring;

	filestring = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0)
		error("couldn't open file.");
	while ((line = getthedamnline(fd)))
	{
		if (mr_struct->rows == 0)
			mr_struct->columns = ft_wordcount(line, ' ');
		valid_check(line, mr_struct->columns);
		oldfs = filestring;
		filestring = add_row(oldfs, line);
		mr_struct->rows++;
		free(line);
		free(oldfs);
		line = NULL;
	}
	free(line);
	close(fd);
	malloc_map(mr_struct);
	process_filestring(filestring, mr_struct);
	free(filestring);
}
