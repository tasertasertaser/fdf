/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 14:54:18 by cschulle          #+#    #+#             */
/*   Updated: 2019/07/05 14:54:20 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_bigstruct mr_struct;

	if (ac == 2)
	{
		mr_struct = (t_bigstruct){av[1], WND_W / 2, WND_H / 2,
			NULL, mlx_init(), NULL, parse(av[1]), NULL, I_KEY,
			(t_coord){0, 0, BLK}, 1, 3, 0, WHT, GRY, 0};
		mr_struct.wn = mlx_new_window(mr_struct.mlx, WND_W, WND_H + 100, "fdf");
		mr_struct.img = img_factory(mr_struct.mlx);
		mr_struct.grid = malloc_grid(mr_struct.map);
		mr_struct.unit = get_unit(mr_struct);
		mr_struct.origin = get_origin(mr_struct, mr_struct.unit);
		create_grid(mr_struct, mr_struct.map, mr_struct.proj);
		bottomline(mr_struct);
		mlx_hook(mr_struct.wn, 2, (1L << 0), key_press, &mr_struct);
		mlx_loop(mr_struct.mlx);
	}
	else
		give_usage();
	return (0);
}
