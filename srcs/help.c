/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:53:02 by cschulle          #+#    #+#             */
/*   Updated: 2019/07/05 14:53:06 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bottomline(t_bigstruct mr_struct)
{
	char *h;

	h = "Press \"H\" for help";
	mlx_string_put(mr_struct.mlx, mr_struct.wn,
		40, WND_H + 40, GRY, mr_struct.file);
	mlx_string_put(mr_struct.mlx, mr_struct.wn,
		WND_W - 230, WND_H + 40, GRY, h);
}

void	give_usage(void)
{
	size_t				i;
	static const char	*helpstring[] = {
		"Controls:\n",
		"[Esc]        -> Exit the program\n",
		"[Space]      -> Reset the map\n",
		"[C]          -> Color toggle\n",
		"[Z][X]       -> Zoom in/out\n",
		"[J][K]       -> Elevation\n",
		"[I][O][P]    -> Projection (Iso <> Ortho <> Perspective)\n",
		"[W][A][S][D] -> Move the map\n",
		"[H]          -> Help\n",
	};

	i = 0;
	ft_putstr(P_BL);
	ft_putstr("\nUsage:\t./fdf \"filename.fdf\"\n\n");
	ft_putstr(P_GY);
	while (i < sizeof(helpstring) / sizeof(helpstring[0]))
	{
		ft_putstr(helpstring[i]);
		i++;
	}
	ft_putstr(P_X);
}

void	help(t_bigstruct *mr_struct)
{
	size_t				i;
	static const char	*helpstring[] = {
		"Controls:\n",
		"[Esc]        -> Exit the program\n",
		"[Space]      -> Reset the map\n",
		"[C]          -> Color toggle\n",
		"[Z][X]       -> Zoom in/out\n",
		"[J][K]       -> Elevation\n",
		"[I][O][P]    -> Projection (Iso <> Ortho <> Perspective)\n",
		"[W][A][S][D] -> Move the map\n",
		"[H]          -> Help\n",
	};

	i = 0;
	mlx_clear_window(mr_struct->mlx, mr_struct->wn);
	while (i < sizeof(helpstring) / sizeof(helpstring[0]))
	{
		mlx_string_put(mr_struct->mlx, mr_struct->wn,
			mr_struct->center_x - 250, 290 + (i * 20),
			GRY, (char *)helpstring[i]);
		i++;
	}
}
