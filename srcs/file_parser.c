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

void	process_filestring(char *filestring, t_map *map)
{
	int		y;
	int		x;
	int		i;
	char	*pt;

	y = 0;
	i = 0;
	pt = filestring;
	nullcheck(filestring);
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			fill_point(pt, &map->points[y][x]);
			if (map->max_z < map->points[y][x].z)
				map->max_z = map->points[y][x].z;
			if (map->min_z > map->points[y][x].z)
				map->min_z = map->points[y][x].z;
			pt = scoot(pt, ' ');
			x++;
		}
		y++;
	}
	free(filestring);
}

/*
**	Combines current file row and filestring, adding separating space.
*/

char	*add_row(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strdup(s2);
	tmp = ft_strjoinfree(tmp, " ");
	s1 = ft_strjoinfree(s1, tmp);
	free(s2);
	return (s1);
}

/*
**	Allocates sufficient memory for map's 2-D array of points.
*/

void	malloc_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!(map->points = malloc(sizeof(t_pt *) * map->rows)))
		error("failed to parse. not enough memory.");
	while (y != map->rows)
	{
		while (x != map->columns)
		{
			if (!(map->points[y] = malloc(sizeof(t_pt) * map->columns)))
				error("failed to parse. not enough memory.");
			x++;
		}
		x = 0;
		y++;
	}
	map->max_z = 0;
	map->min_z = 0;
}

/*
**	Reads the entire file into a single string with get_next_line.
**	Calls valid_check on each row as it goes to verify the file.
**	Declares a new t_map struct and stores map information.
**	Calls process_filestring to turn the file string into a 2D t_pt array.
*/

t_map	*parse(char *filename)
{
	t_map	*map;
	int		fd;
	char	*line;
	char	*filestring;

	if (!(map = malloc(sizeof(t_map))))
		error("failed to parse. not enough memory.");
	map->points = NULL;
	map->rows = 0;
	filestring = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0)
		error("couldn't open file.");
	while ((get_next_line(fd, &line)) == 1)
	{
		if (map->rows == 0)
			map->columns = ft_wordcount(line, ' ');
		valid_check(line, map->columns);
		filestring = add_row(filestring, line);
		map->rows++;
	}
	close(fd);
	malloc_map(map);
	process_filestring(filestring, map);
	return (map);
}
