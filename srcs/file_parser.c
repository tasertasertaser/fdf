#include "../includes/fdf.h"

int	valid_chars(char *row)
{
	int		i;
	int		colors;

	colors = 0;
	i = 0;
	while (row[i])
	{
		if (row[i] == ' ' || !(ft_isdigit(row[i])) || row[i] == ',' || row[i] == 'x')
			if (row[i] == ',')
				colors = 1;
		else
			ERRORBADTHINGS;
		i++;
	}
	return (colors);
}

// t_pt	**make_map(t_pt **map, int rows, int columns)
// {
// 	int		i;

// 	i = 0;
// 	if (!(map = malloc(sizeof(t_pt *) * rows + 1)))
// 		ERRORBADTHINGS;
// 	while (i < rows)
// 	{
// 		if (!(map[i] = malloc(sizeof(t_pt) * columns)))
// 			ERRORBADTHINGS;
// 		i++;
// 	}
// }

// int		valid_number(char *string)
// {
// 	int		num;

// 	num = ft_atoi(string);
// 	if (num >= 0 && num <= FT_INTMAX)
// 		return (num);
// 	else
// 		ERRORBADTHINGS;
// }

// void	read_map(char *filename, t_pt **map, int rows)
// {
// 	int		fd;
// 	char	*row;
// 	int		y;

// 	y = 0;
// 	if ((fd = open(filename, O_RDONLY)) < 0)
// 		ERRORBADTHINGS;
// 	while (y < rows)
// 	{
// 		get_next_line(fd, &row);
// 		read_row(row, y, map[y]);
// 		y++;
// 	}
// }

int		get_rows(char *filename)
{
	int		fd;
	t_map	map_info;
	int		colors;
	char	*line;

	if ((fd = open(filename, O_RDONLY)) < 0)
		ERRORBADTHINGS;
	get_next_line(fd, &line);
	pts = ft_wordcount(line, ' ');
	rows = 1;
	while ((get_next_line(fd, &line)) == 1)
	{
		colors = valid_chars(line);
		rows++;
	}
	free(line);
	close(fd);
	map_info = (t_map){rows, pts, colors};
	return(map_info);
}

// void	get_pts(t_pt **map, char *filename, int rows)
// {
// 	int		fd;
// 	char	*line;
// 	int		pts;

// 	if ((fd = open(filename, O_RDONLY)) < 0)
// 		ERRORBADTHINGS;
// 	get_next_line(fd, &line);
// 	pts = ft_wordcount(line, ' ');

// 	while (rows >= 0)
// 	{

// 	}

// }

t_pt	**parse(char *filename)
{
	int		rows;
	t_pt	**map;

	i = 0;
	map = NULL;

	rows = get_rows(filename);
	if (!(map = malloc(sizeof(t_pt *) * rows)))
		ERRORBADTHINGS;
	get_pts(map, filename, rows);

	return (map);
}
