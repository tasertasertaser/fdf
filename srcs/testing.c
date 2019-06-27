#include "../includes/fdf.h"

/*
**	Draws a line down the center axis of the window, useful for testing.
**	Pass 'x' as axis for vertical center, 'y' for horizontal center, 'b' for both.
*/

void	draw_centerline(t_bigstruct mr_struct, char axis)
{
	if (axis == 'x' || axis == 'b')
	{	
		t_line centerline = (t_line){(t_coord){mr_struct.center_x, 0, GRY}, (t_coord){mr_struct.center_x, WINDOW_H, GRY}};
		draw_line(centerline, mr_struct);
	}
	if (axis == 'y' || axis == 'b')
	{	
		t_line centerline = (t_line){(t_coord){0, mr_struct.center_y, GRY}, {WINDOW_W, mr_struct.center_y, GRY}};
		draw_line(centerline, mr_struct);
	}
}

void	draw_linestar(t_bigstruct mr_struct)
{
	int cx = mr_struct.center_x;
	int cy = mr_struct.center_y;
	t_coord center = {cx, cy, WHT};
	int TLcolor = PNK;
	int	TRcolor = YLW;
	//int BRcolor = GRN;
	//int BLcolor = BLU;
	int endcolor = WHT;

	t_coord end[] = {{cx - 200, cy - 200, TLcolor},
					{cx - 150, cy - 200, gradient(TLcolor, TRcolor, 9, 2)},
					{cx - 100, cy - 200, gradient(TLcolor, TRcolor, 9, 3)},
					{cx - 50, cy - 200, gradient(TLcolor, TRcolor, 9, 4)},
					{cx, cy - 200, gradient(TLcolor, TRcolor, 9, 5)},
					{cx + 50, cy - 200, gradient(TLcolor, TRcolor, 9, 6)},
					{cx + 100, cy - 200, gradient(TLcolor, TRcolor, 9, 7)},
					{cx + 150, cy - 200, gradient(TLcolor, TRcolor, 9, 8)},

					{cx + 200, cy - 200, TRcolor},
					{cx + 200, cy - 150, endcolor},
					{cx + 200, cy - 100, endcolor},
					{cx + 200, cy - 50, endcolor},
					{cx + 200, cy, endcolor},
					{cx + 200, cy + 50, endcolor},
					{cx + 200, cy + 100, endcolor},
					{cx + 200, cy + 150, endcolor},

					{cx + 200, cy + 200, endcolor},
					{cx + 150, cy + 200, endcolor},
					{cx + 100, cy + 200, endcolor},
					{cx + 50, cy + 200, endcolor},
					{cx, cy + 200, endcolor},
					{cx - 50, cy + 200, endcolor},
					{cx - 100, cy + 200, endcolor},
					{cx - 150, cy + 200, endcolor},

					{cx - 200, cy + 200, endcolor},
					{cx - 200, cy + 150, endcolor},
					{cx - 200, cy + 100, endcolor},
					{cx - 200, cy + 50, endcolor},
					{cx - 200, cy, endcolor},
					{cx - 200, cy - 50, endcolor},
					{cx - 200, cy - 100, endcolor},
					{cx - 200, cy - 150, endcolor}};


	size_t counter = 0;
	while(counter < sizeof(end)/sizeof(end[0]))
	{
		draw_line((t_line){center, end[counter]}, mr_struct);
		counter++;
	}
}