#include "includes/fdf.h"

typedef struct		s_info
{
	int				color;
	int				x;
	int				y;
	void			*window;
	void			*mlx;
}					t_info;

void	draw_2D_gridtest(t_pt **map, void *mlx, void *window)
{
	int i = 0;
	int j;

	while(i < 11)
	{
		j = 0;
		while(j < 19)
		{
			mlx_pixel_put(mlx, window, (map[i][j].x * UNIT) + (2*UNIT), (map[i][j].y * UNIT) + (2 * UNIT), map[i][j].color);
			j++;
		}
		i++;
	}
}

void	draw_linetest(void *mlx, void *window)
{
	t_pt center = {NULL, 250, 250, 0, WHT, NULL};

	draw_line(center, (t_pt){NULL, 150, 150, 0, WHT, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 200, 150, 0, WHT, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 250, 150, 0, 0xFF57A4, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 300, 150, 0, WHT, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 350, 150, 0, WHT, NULL}, mlx, window);

	draw_line(center, (t_pt){NULL, 350, 200, 0, WHT, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 350, 250, 0, WHT, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 350, 300, 0, WHT, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 350, 350, 0, WHT, NULL}, mlx, window);

	draw_line(center, (t_pt){NULL, 300, 350, 0, WHT, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 250, 350, 0, WHT, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 200, 350, 0, WHT, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 150, 350, 0, WHT, NULL}, mlx, window);

	draw_line(center, (t_pt){NULL, 150, 300, 0, WHT, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 150, 250, 0, WHT, NULL}, mlx, window);
	draw_line(center, (t_pt){NULL, 150, 200, 0, WHT, NULL}, mlx, window);
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
		line->color = YLW;
		draw_line(line, mr_struct->mlx, mr_struct->window);
	}
	else
		return(button);
	return(0);
}
*/

void	play_sound(int key, t_info *mr_struct)
{
	switch (key)
	{

		case 86: //Numpad 4
			system("play -n synth .1 square 261.626"); //C4
			mlx_string_put(mr_struct->mlx, mr_struct->window, 200, 235, PNK, "C");
			break;
		case 87: //Numpad 5
			system("play -n synth .1 square 293.665"); //D
			mlx_string_put(mr_struct->mlx, mr_struct->window, 215, 235, PRP, "D");
			break;
		case 88: //Numpad 6
			system("play -n synth .1 square 329.628"); //E
			mlx_string_put(mr_struct->mlx, mr_struct->window, 230, 235, BLU, "E");
			break;
		case 69: //Numpad +
			system("play -n synth .1 square 349.228"); //F
			mlx_string_put(mr_struct->mlx, mr_struct->window, 245, 235, AQU, "F");
			break;
		case 83: //Numpad 1
			system("play -n synth .1 square 391.995"); //G
			mlx_string_put(mr_struct->mlx, mr_struct->window, 260, 235, GRN, "G");
			break;
		case 84: //Numpad 2
			system("play -n synth .1 square 440"); //A
			mlx_string_put(mr_struct->mlx, mr_struct->window, 275, 235, YLW, "A");
			break;
		case 85: //Numpad 3
			system("play -n synth .1 square 493.883"); //B
			mlx_string_put(mr_struct->mlx, mr_struct->window, 290, 235, ORN, "B");
			break;
		case 76: //Numpad Enter
			system("play -n synth .1 square 523.251"); //C
			mlx_string_put(mr_struct->mlx, mr_struct->window, 305, 235, PNK, "C");
			break;
		case 81: //Numpad =
			system("play -n synth .1 sin 329.628"); //E
			system("play -n synth .1 sin 293.665"); //D
			system("play -n synth .1 sin 440"); //A
			system("play -n synth .1 sin 493.883"); //B
			system("play -n synth .1 sin 523.251"); //C
			mlx_string_put(mr_struct->mlx, mr_struct->window, 180, 235, PRP, "BONUS SOUND");
			break;
	}
}

int key_press(int key, t_info *mr_struct)
{
	mlx_clear_window (mr_struct->mlx, mr_struct->window);
	
	if (key == J_KEY)
	{
		parse(TESTFILE);
	}
	if (key == ESC_KEY)
	{
		mlx_destroy_window (mr_struct->mlx, mr_struct->window);
		exit(0);
	}
	if (key == F_KEY)
	{
		draw_linetest(mr_struct->mlx, mr_struct->window);
	}
	if (key == K_KEY)
	{
		// char const str1 = "0  0  0";
		// char const str2 = " 0  0  0\0";
		// char c = '\0';
		printf("K\n"); //, ft_strcjoin(str1, str2, c));
	}
	else
	{
		char *string = ft_itoa(key);
		mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->x, mr_struct->y, mr_struct->color, string);
		play_sound(key, mr_struct);
		free(string);
	}
	return(key);
}

int key_release(int key, t_info *mr_struct)
{
	if(key == ESC_KEY)
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

int	main(int ac, char **av)
{
	if(ac == 1)
	{
		/* ••••• WINDOW TESTS ••••• */
		void *mlx_ptr = mlx_init();
		void *window = mlx_new_window(mlx_ptr, 500, 500, "new window who dis");	
		t_info mr_struct = { .color = WHT, .x = 20, .y = 30, .window = window, .mlx = mlx_ptr};
		mlx_hook(window, 2, (1L<<0), key_press, &mr_struct);
		mlx_loop(mlx_ptr);
	}

	else if (ac == 2)
	{
		/* ••••• PARSER TESTS ••••• */
		parse(av[1]);
	}

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
