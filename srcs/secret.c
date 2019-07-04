#include "../includes/fdf.h"

void	coloroptions(t_bigstruct *mr_struct)
{
	mlx_string_put(mr_struct->mlx, mr_struct->window, 330, WINDOW_H + 30, GRY, "color 1 = top 1-0");
	mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x, WINDOW_H + 35, PNK, "1");
	mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x + 20, WINDOW_H + 35, ORN, "2");
	mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x + 40, WINDOW_H + 35, YLW, "3");
	mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x + 60, WINDOW_H + 35, GRN, "4");
	mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x + 80, WINDOW_H + 35, AQU, "5");
	mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x + 100, WINDOW_H + 35, BLU, "6");
	mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x + 120, WINDOW_H + 35, PRP, "7");
	mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x + 140, WINDOW_H + 35, GRY, "8");
	mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x + 160, WINDOW_H + 35, WHT, "9");
	mlx_string_put(mr_struct->mlx, mr_struct->window, mr_struct->center_x + 180, WINDOW_H + 35, BLK, "0");
	mlx_string_put(mr_struct->mlx, mr_struct->window, 330, WINDOW_H + 50, GRY, "color 2 = numpad 1-0");
}