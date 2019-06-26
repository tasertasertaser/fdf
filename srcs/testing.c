#include "../includes/fdf.h"

/*
**	Draws a line down the center axis of the window, useful for testing.
**	Pass 'x' as axis for vertical center, 'y' for horizontal center, 'b' for both.
*/

void	draw_centerline(t_window mr_struct, char axis)
{
	if (axis == 'x' || axis == 'b')
	{	
		t_line centerline = (t_line){{0, WINDOW_H}, {mr_struct.center_x, mr_struct.center_x}, mr_struct.mlx, mr_struct.window};
		draw_line(centerline);
	}
	if (axis == 'y' || axis == 'b')
	{	
		t_line centerline = (t_line){{mr_struct.center_y, mr_struct.center_y}, {0, WINDOW_W}, mr_struct.mlx, mr_struct.window};
		draw_line(centerline);
	}
}