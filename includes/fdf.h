/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:08:41 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/01 19:36:46 by cschulle         ###   ########.fr       */
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

/*======== testing ========*/

# define TESTFILE "maps/10-2.fdf"

/*======== strooocts ========*/

struct	s_pt
{
	int				z;
	int				color;
};					t_pt;

// typedef struct	s_pt	t_pt;
// struct	s_pt
// {
// 	t_pt			*previous;
// 	int				x;
// 	int				y;
// 	int				z;
// 	int				color;
// 	t_pt			*next;
// };

typedef struct		s_map
{
	int				rows;
	int				columns;
	t_pt			**points;
}					t_map;

/*======== colorstuff ========*/

# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(a, b, c) ((a) << 16) + ((b) << 8) + (c)

# define P(a) \e[38;R(a);G(a);B(a)m

# define P_RD "\e[38;5;203m"
# define P_YW "\e[38;5;220m"
# define P_GR "\e[38;5;112m"
# define P_BL "\e[38;5;39m"
# define P_PR "\e[38;5;141m"
# define P_GY "\e[38;5;240m"
# define P_X "\e[0m"

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
# define FT_INTMAX 2147483647

/*======== fn declarations ========*/

int		linelen(t_pt start, t_pt end);
void	draw_line(t_pt start, t_pt end, void *mlx, void *window);
void	draw_gradient_line(t_pt start, t_pt end, void *mlx, void *window);
int		gradient(int startcolor, int endcolor, int len, int pix);
t_map	parse(char *filename);
void	valid_check(char *row, int columns);
void	error(char *description);

#endif
