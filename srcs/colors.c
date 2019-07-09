/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 21:35:29 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/08 18:57:55 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		gradient(int startcolor, int endcolor, int len, int pos)
{
	float	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (float)((R(endcolor)) - (R(startcolor))) / (float)len;
	increment[1] = (float)((G(endcolor)) - (G(startcolor))) / (float)len;
	increment[2] = (float)((B(endcolor)) - (B(startcolor))) / (float)len;
	new[0] = (R(startcolor)) + ft_round(pos * increment[0]);
	new[1] = (G(startcolor)) + ft_round(pos * increment[1]);
	new[2] = (B(startcolor)) + ft_round(pos * increment[2]);
	newcolor = RGB(new[0], new[1], new[2]);
	return (newcolor);
}

int		zcolor(t_bigstruct mr_struct, int x, int y)
{
	int		len;
	float	mid_z;

	mid_z = AVG((float)mr_struct.max_z, (float)mr_struct.min_z);
	len = mr_struct.max_z - mr_struct.min_z;
	if (mr_struct.clr == 1)
	{
		if (mr_struct.points[y][x].z >= mid_z)
			return (gradient(YLW, PNK, len, mr_struct.points[y][x].z));
		else
			return (gradient(WHT, YLW, len, mr_struct.points[y][x].z));
	}
	else if (mr_struct.clr == 2)
	{
		if (mr_struct.points[y][x].z >= mid_z)
			return (gradient(ORN, YLW, len, mr_struct.points[y][x].z));
		else
			return (gradient(GRY, ORN, len, mr_struct.points[y][x].z));
	}
	else if (mr_struct.clr == 3)
		return (gradient(BLK, AQU, len, mr_struct.points[y][x].z));
	else
		return (gradient(mr_struct.color1, mr_struct.color2,
			len, mr_struct.points[y][x].z));
}

void	coloroptions(t_bigstruct *mr_struct)
{
	void	*win;
	int		cx;
	int		y;

	win = mr_struct->wn;
	cx = mr_struct->center_x;
	y = WND_H + 35;
	mlx_string_put(mr_struct->mlx, win, 330, y - 5, GRY, "color 1 = top 1-0");
	mlx_string_put(mr_struct->mlx, win, cx, y, PNK, "1");
	mlx_string_put(mr_struct->mlx, win, cx + 20, y, ORN, "2");
	mlx_string_put(mr_struct->mlx, win, cx + 40, y, YLW, "3");
	mlx_string_put(mr_struct->mlx, win, cx + 60, y, GRN, "4");
	mlx_string_put(mr_struct->mlx, win, cx + 80, y, AQU, "5");
	mlx_string_put(mr_struct->mlx, win, cx + 100, y, BLU, "6");
	mlx_string_put(mr_struct->mlx, win, cx + 120, y, PRP, "7");
	mlx_string_put(mr_struct->mlx, win, cx + 140, y, GRY, "8");
	mlx_string_put(mr_struct->mlx, win, cx + 160, y, WHT, "9");
	mlx_string_put(mr_struct->mlx, win, cx + 180, y, BLK, "0");
	mlx_string_put(mr_struct->mlx, win,
		330, y + 15, GRY, "color 2 = numpad 1-0");
}

void	color_select(int key, t_bigstruct *mr_struct)
{
	const int topcolors[] = {PNK, ORN, YLW, GRN, BLU, AQU, 0, WHT, PRP, 0, GRY};
	const int btmcolors[] = {BLK, PNK, ORN, YLW,
		GRN, AQU, BLU, PRP, 0, GRY, WHT};

	if (key >= 18 && key <= 29 && key != 24)
		mr_struct->color2 = topcolors[key - 18];
	else if (key >= 82 && key <= 92 && key != 90)
		mr_struct->color1 = btmcolors[key - 82];
}

void	color_cycle(t_bigstruct *mr_struct)
{
	if (mr_struct->clr == 0)
		mr_struct->clr = 1;
	else if (mr_struct->clr == 1)
		mr_struct->clr = 2;
	else if (mr_struct->clr == 2)
		mr_struct->clr = 3;
	else if (mr_struct->clr == 3)
	{
		mr_struct->clr = 4;
		coloroptions(mr_struct);
	}
	else
	{
		mlx_clear_window(mr_struct->mlx, mr_struct->wn);
		mlx_string_put(mr_struct->mlx, mr_struct->wn, 40, WND_H
			+ 40, GRY, mr_struct->file);
		mlx_string_put(mr_struct->mlx, mr_struct->wn, WND_W
			- 230, WND_H + 40, GRY, "Press \"H\" for help");
		mr_struct->clr = 0;
	}
}
