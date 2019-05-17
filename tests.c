#include "includes/fdf.h"
#include <stdio.h>


typedef struct		s_info
{
	int				color;
	int				x;
	int				y;
	void			*window;
	void			*mlx;
}					t_info;

void	draw_testline(void *mlx, void *window)
{
	int x1 = 250;
	int y1 = 250;


	mlx_pixel_put(mlx, window, x1, y1, 0xFFFFFF); // center
	mlx_pixel_put(mlx, window, 150, 150, 0xFF0783); // top right
	mlx_pixel_put(mlx, window, 350, 350, 0x2FA8F9); // bottom right
	mlx_pixel_put(mlx, window, 150, 350, 0xFFDC19); // bottom left
	mlx_pixel_put(mlx, window, 350, 150, 0x62E077); // top right

	t_line *blueline = make_line(250, 250, 350, 350);
	draw_gradient_line(blueline, mlx, window, 0x2FA8F9);
	// while(x1 != 350)
	// {
	// 	x1++;
	// 	y1++;
	// 	mlx_pixel_put(mlx, window, x1, y1, gradient(0xFFFFFF, 0x2Fa8F9, 100, x1-250));
	// }
}
/*
int	mouse_press(int button, int x, int y, t_info *mr_struct)
{
	t_line *line;
	if(button == 1 && ((line = malloc(sizeof(t_line)))))
	{
		line->x0 = 250;
		line->y0 = 250;
		line->x1 = x;
		line->y1 = y;
		line->slope = (x-250) / (y-250);
		line->color = 0xFFAA00;
		draw_line(line, mr_struct->mlx, mr_struct->window);
	}
	else
		return(button);
	return(0);
}
*/
int key_press(int key, t_info *mr_struct)
{
	if(key == 53)
	{
		mlx_destroy_window (mr_struct->mlx, mr_struct->window);
		exit(0);
	}
	else if(key == 3)
	{
		draw_testline(mr_struct->mlx, mr_struct->window);
	}
	else
	{
		char *string = ft_itoa(key);
		mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->x, mr_struct->y, mr_struct->color, string);
		free(string);
	}
	return(key);
}

int key_release(int key, t_info *mr_struct)
{
	if(key == 53)
	{
		mlx_destroy_window (mr_struct->mlx, mr_struct->window);
		exit(0);
	}
	else
	{
		mlx_clear_window (mr_struct->mlx, mr_struct->window);
		return(0);
	}
}

int	main(void)
{

	void *mlx_ptr = mlx_init();
	void *window = mlx_new_window(mlx_ptr, 500, 500, "new window who dis");	

	mlx_string_put(mlx_ptr, window, 20, 60, 0xffffef, "press a key");
	
	t_info mr_struct = { .color = 0xFFFFFF, .x = 20, .y = 30, .window = window, .mlx = mlx_ptr};
	mlx_hook(window, 2, (1L<<0), key_press, &mr_struct); //wtf are these (1L<<0) masks for? Apparently required? why required in addition to button #?
	//mlx_hook(window, 3, (1L<<1), key_release, &mr_struct);
	//mlx_hook(window, 4, (1L<<11), mouse_press, &mr_struct);
	mlx_loop(mlx_ptr);

/*	color printing experiment
	int x = 0;
	int y = 0;
	int color = 0;

	while(y < 500)
	{
		if(x > 499)
			y++;
		mlx_pixel_put(mlx_ptr, window, x, y, color);
		x++;
		color++;
	}
*/
	return(0);
}
