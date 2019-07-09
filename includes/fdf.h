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

/*
**	======== inclyoooods ========
*/

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

/*
**	======== testing ========
*/

# define TESTFILE "maps/10-2.fdf"

/*
**	======== strooocts ========
*/

typedef struct		s_pt
{
	int				z;
	int				color;
}					t_pt;

typedef struct		s_coord
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
	int				intr;
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

typedef struct		s_im
{
	void			*imptr;
	int				*pixels;
}					t_im;

typedef struct		s_bigstruct
{
	char			*file;
	int				center_x;
	int				center_y;
	void			*wn;
	void			*mlx;
	t_im			*img;
	int				rows;
	int				columns;
	int				max_z;
	int				min_z;
	t_pt			**points;
	t_coord			**grid;
	char			proj;
	t_coord			origin;
	double			unit;
	float			z_mod;
	int				clr;
	int				color1;
	int				color2;
	int				helptoggle;
}					t_bigstruct;

/*
**	======== colorstuff ========
*/

# define R(a) (a) >> 16
# define G(a) ((a) >> 8) & 0xFF
# define B(a) (a) & 0xFF
# define RGB(a, b, c) ((a) << 16) + ((b) << 8) + (c)

# define PNK 0xFF57A4
# define ORN 0xF99C4F
# define YLW 0xFCD14F
# define GRN 0x97F53B
# define AQU 0x43FFB5
# define BLU 0x53ADFC
# define PRP 0x9F29FF
# define GRY 0x404040
# define BLK 0x000000
# define WHT 0xFFFFFF

/*
**	======== keys ========
*/

# define I_KEY 34
# define O_KEY 31
# define P_KEY 35

# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2

# define Z_KEY 6
# define X_KEY 7

# define J_KEY 38
# define K_KEY 40

# define C_KEY 8

# define SPACE_KEY 49

# define H_KEY 4
# define ESC_KEY 53

/*
**	======== display ========
*/

# define WND_W 1280
# define WND_H 720
# define PRSP_BACKEDGE .3
# define PRSP_FRONTEDGE .9
# define ZOOM_MAX 100
# define ZOOM_MIN 2

/*
**	======== fn declarations ========
*/

/*
**	...parsing & allocation...
*/
void				parse(char *filename, t_bigstruct *mr_struct);
void				valid_check(char *row, int columns);
t_coord				**malloc_grid(t_bigstruct mr_struct);
char				*getthedamnline(int fd);

/*
**	...ui...
*/
int					key_press(int key, t_bigstruct *mr_struct);
void				coloroptions(t_bigstruct *mr_struct);
void				give_usage(void);
void				help(t_bigstruct *mr_struct);
void				bottomline(t_bigstruct mr_struct);

/*
**	...moving the map...
*/
void				plot(int key, t_bigstruct *mr_struct);
void				move(int key, t_bigstruct *mr_struct);
void				zoom(int key, t_bigstruct *mr_struct);
void				elevate(int key, t_bigstruct *mr_struct);
void				reset(t_bigstruct *mr_struct);

/*
**	...drawing & projections...
*/
void				create_grid(t_bigstruct mr_struct, char projection);
double				get_unit(t_bigstruct mr_struct);
t_coord				get_origin(t_bigstruct mr_struct, double unit);
void				draw_line(t_line line, t_bigstruct mr_struct);
void				connect(t_coord **grid, t_bigstruct mr_struct);
void				make_orth(t_bigstruct mr_struct, t_coord **grid);
void				make_iso(t_bigstruct mr_struct, t_coord **grid);
void				make_prsp(t_bigstruct mr_struct, t_coord **grid);
double				get_xunit(t_bigstruct mr_struct, int y);

/*
**	...colors...
*/
int					zcolor(t_bigstruct mr_struct, int x, int y);
int					gradient(int startcolor, int endcolor, int len, int pos);
void				color_select(int key, t_bigstruct *mr_struct);
void				color_cycle(t_bigstruct *mr_struct);

/*
**	...images...
*/
t_im				*img_factory(void *mlx);
void				drawpixel(t_im *img, int x, int y, int color);
void				clear_image(t_im *image);

/*
**	...frees...
*/
void				ft_strcjoinfree(char **old, char *new, char c);
void				free_grid(t_coord **grid, t_bigstruct mr_struct);

/*
**	...testing...
*/
void				draw_centerline(t_bigstruct mr_struct, char axis);

/*
**	...error...
*/
void				error(char *description);
void				nullcheck(char *string);

#endif
