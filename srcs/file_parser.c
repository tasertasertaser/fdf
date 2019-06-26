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

t_pt	*fill_point(char *str, t_pt *point)
{
	char	*color;

	point->z = ft_atoi(str);
	if ((color = ft_strchr(str, ',')))
		point->color = (ft_atoibase(color, 16));
	else point->color = 0xFFFFFF; // TODO: write a function that assigns color based on z value
	return (point);
}

void	process_filestring(char *filestring, t_map *map)
{
	int y;
	int x;
	int i;
	char *pt;

	y = 0;
	i = 0;

	printf("processing "P_YW"%s\n"P_X, filestring);
	//pt = ft_strsplit(filestring, ' '); // TODO: fix this; make it process the chunks of string instead of splitting the string
	pt = filestring;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			fill_point(pt, &map->points[y][x]);
			printf(P_GY"%d "P_X, map->points[y][x].z);
			pt = scoot(pt, ' ');
			x++;
		}		
		y++;
		printf("\n");
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
		error("failed parse: not enough memory.");
	while (y != map->rows)
	{
		while (x != map->columns)
		{
			if (!(map->points[y] = malloc(sizeof(t_pt) * map->columns)))
				error("failed parse: not enough memory.");
			x++;
		}
		x = 0;
		y++;
	}
}

/*
**	Reads the entire file into a single string with get_next_line.
**	Calls valid_check on each row as it goes to verify the file.
**	Declares a new t_map struct and stores map information.
**	Calls process_filestring to turn the file string into a 2D t_pt array.
*/
t_map	*new_map(char *filename)
{
	t_map	*map;
	int		fd;
	char	*line;
	char	*filestring;

	if(!(map = malloc(sizeof(t_map))))
		error("failed parse: not enough memory.");
	map->rows = 0;
	map->points = NULL;
	filestring = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0)
		error("couldn't open file.");
	while ((get_next_line(fd, &line)) == 1)
	{
		if (map->rows == 0)
			map->columns = ft_wordcount(line, ' ');
		valid_check(line, map->columns);
		filestring = add_row(filestring, line);
		//printf(P_BL"%s•\n", filestring);
		map->rows++;
	}
	close(fd);
	malloc_map(map);
	process_filestring(filestring, map);
	return(map);
}

/*
**	Control center for parsing functions.
*/
t_map	*parse(char *filename)
{
	t_map	*map;

	map = new_map(filename);
	// get_pts(map, filename, rows);


	/* ••••••• TESTS ••••••• */
	// printf("rows: "P_PR"%d\n"P_X, map.rows);
	// printf("columns: "P_YW"%d\n", map.columns);
	
	/*
	printf("grid[0][0]: "P_PR"%d, %d\n"P_X,\
		map.grid[0][0].x,\
		map.grid[0][0].y);
	*/
	/* ••••••• ----- ••••••• */

	return (map);
}
