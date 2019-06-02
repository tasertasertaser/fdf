#include "../includes/fdf.h"


t_pt	*make_point(char *str, int x, int y)
{
	t_pt	*point;

	if (!(point = malloc(sizeof(t_pt))))
		error("insufficient memory.");
	point->z = ft_atoi(str);
	point->x = x;
	point->y = y;
	char	*color;
	if ((color = ft_strchr(str, ',')))
		point->color = (ft_atoibase(color, 16));
	point->previous = NULL;
	point->next = NULL;

	return (point);
}

void	double_list_add(t_pt *point, t_pt *list)
{
	t_pt	*start;

	start = list;
	while (list->next != NULL)
		list = list->next;
	list->next = point;
	point->previous = list;
	point->next = NULL;
	list = start;
}

t_pt	*add_row(char *row, t_pt *pointlist, int y)
{
	char	**points;
	int		x;

	x = 0;
	if ((points = ft_strsplit(row, ' ')) == NULL)
		error("failed ft_strsplit in add_row().");
	while (points[x])
	{
		if (!pointlist)
			pointlist = make_point(points[x], x, y);
		else
			double_list_add(make_point(points[x], x, y), pointlist);
		x++;
	}
	return (pointlist);
}

void	print_points(t_pt *pointlist)
{
	t_pt	*cursor;

	cursor = pointlist;
	while (cursor != NULL)
	{
		if (cursor->previous && cursor->y != cursor->previous->y)
			printf("\n");
		printf(" %d", cursor->z);
		cursor = cursor->next;
	}
	printf("\n");
}

t_map	new_map(char *filename)
{
	int		fd;
	char	*line;
	t_map	map;

	if ((fd = open(filename, O_RDONLY)) < 0)
		error("couldn't open file.");
	map.rows = 0;
	map.points = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (map.rows == 0)
			map.columns = ft_wordcount(line, ' ');
		valid_check(line, map.columns);
		map.points = add_row(line, map.points, map.rows);
		map.rows++;
	}
	free(line);
	close(fd);
	return(map);
}

t_map	parse(char *filename)
{
	t_map	map;

	map = new_map(filename);

	print_points(map.points);
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
