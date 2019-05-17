/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:08:41 by cschulle          #+#    #+#             */
/*   Updated: 2019/03/05 15:59:39 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"

typedef struct		s_line
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	char			slope_type;
	double			slope;
	int				intercept;
	int				color;
}					t_line;

# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(a, b, c) ((a) << 16) + ((b) << 8) + (c)

#define P_RED "\e[38;5;203m"
#define P_YELLOW "\e[38;5;220m"
#define P_GREEN "\e[38;5;112m"
#define P_BLUE "\e[38;5;39m"
#define P_PURPLE "\e[38;5;141m"
#define P_GREY "\e[38;5;243m"

#define P_XCOLOR "\e[0m"

int		linelen(t_line *line);
t_line	*make_line(int x0, int y0, int x1, int y1);
void	draw_line(t_line* line, void *mlx, void *window);
void	draw_gradient_line(t_line* line, void *mlx, void *window, int endcolor);
int		gradient(int startcolor, int endcolor, int len, int pix);

#endif
