/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <cschulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:08:41 by cschulle          #+#    #+#             */
/*   Updated: 2019/06/08 20:52:27 by cschulle         ###   ########.fr       */
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
#include <math.h>
#include <stdio.h>			// TODO: delete later

/*======== testing ========*/

# define TESTFILE "maps/10-2.fdf"

/*======== strooocts ========*/

typedef	struct		s_pt
{
	int				z;
	int				color;
}					t_pt;

typedef	struct		s_coord
{
	int				x;
	int				y;
	int				color;
}					t_coord;

typedef struct		s_line
{
	t_coord			a;
	t_coord			b;
}					t_line;

typedef struct		s_lineshit
{
	double			slope;
	int				intercept;
	int				sign;
	int				len;
}					t_lineshit;

typedef struct		s_map
{
	int				rows;
	int				columns;
	int				max_z;
	int				min_z;
	t_pt			**points;
}					t_map;

typedef struct		s_bigstruct
{
	int				center_x;
	int				center_y;
	void			*window;
	void			*mlx;
	t_map			*map;
	char			proj;
	int				reset;
	t_coord			origin;
	int				z_mod;
	int				color_on;

}					t_bigstruct;

/*======== MLX things ========*/

# define WINDOW_W 1280
# define WINDOW_H 720

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
# define GRY 0x404040
# define WHT 0xFFFFFF

# define MAXCOLOR PNK
# define MINCOLOR YLW

/*======== special keys ========*/

# define I_KEY 34
# define O_KEY 31
# define P_KEY 35

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

# define H_KEY 4
# define J_KEY 38
# define K_KEY 40
# define ESC_KEY 53

/*======== other ========*/

# define PRSP_BACKEDGE .3
# define PRSP_FRONTEDGE .9
# define FT_INTMAX 2147483647
# define UNIT 30

/*======== fn declarations ========*/

//int		int linelen(t_line *line);
void	draw_line(t_line line, t_bigstruct mr_struct);
//void	draw_gradient_line(t_pt start, t_pt end, void *mlx, void *window);
//int		gradient(int startcolor, int endcolor, int len, int pix);
t_map	*parse(char *filename);
void	valid_check(char *row, int columns);
void	error(char *description);
void	ft_strcjoinfree(char **old, char *new, char c);
void	free_2D(char **array);
void	print_flat_map(t_bigstruct wnd, t_map *map);
void	print_iso_map(t_bigstruct wnd, t_map *map);
void	create_grid(t_bigstruct wnd, t_map *map, char projection);
void	draw_centerline(t_bigstruct mr_struct, char axis);
int		key_press(int key, t_bigstruct *mr_struct);
void	give_usage(void);
void	connect(t_coord **grid, t_bigstruct mr_struct);
void	draw_linestar(t_bigstruct mr_struct);
int		gradient(int startcolor, int endcolor, int len, int pos);
void	free_grid(t_coord **grid, t_bigstruct mr_struct);
#endif
