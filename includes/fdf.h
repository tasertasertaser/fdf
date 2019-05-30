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

/*======== inclyoooods ========*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>			// TODO: delete later

/*======== strooocts ========*/

typedef struct		s_pt
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_pt;

typedef struct		s_map
{
	int				rows;
	int				pts;
	int				colors;
}

/*======== colorstuff ========*/

# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(a, b, c) ((a) << 16) + ((b) << 8) + (c)

# define P_RED "\e[38;5;203m"
# define P_YELLOW "\e[38;5;220m"
# define P_GREEN "\e[38;5;112m"
# define P_BLUE "\e[38;5;39m"
# define P_PURPLE "\e[38;5;141m"
# define P_GREY "\e[38;5;243m"
# define P_XCOLOR "\e[0m"

# define PNK 0xFF57A4
# define ORN 0xF99C4F
# define YLW 0xFCD14F
# define GRN 0x97F53B
# define AQU 0x43FFB5
# define BLU 0x53ADFC
# define PRP 0x9F29FF
# define WHT 0xFFFFFF

/*======== special keys ========*/

# define F_KEY 3
# define J_KEY 38
# define K_KEY 39
# define ESC_KEY 53

/*======== other ========*/

# define UNIT 30
# define ERRORBADTHINGS exit(1)
# define FT_INTMAX 2147483647

/*======== fn declarations ========*/

int		linelen(t_pt start, t_pt end);
void	draw_line(t_pt start, t_pt end, void *mlx, void *window);
void	draw_gradient_line(t_pt start, t_pt end, void *mlx, void *window);
int		gradient(int startcolor, int endcolor, int len, int pix);
t_pt	**parse(char *filename);

#endif
