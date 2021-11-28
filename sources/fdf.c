/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:39:10 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/26 22:29:02 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	make_window(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		terminate("mlx");
	map->mlx_win = mlx_new_window(map->mlx, WIDTH, HEIGHT, TITLE);
	if (!map->mlx_win)
		terminate("mlx_win");
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->img)
		terminate("img");
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel,
			&map->size_line, &map->endian);
	if (!map->addr)
		terminate("addr");
	draw_map(map);
	hooks_handler(map);
	mlx_loop(map->mlx);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc == 2)
	{
		init_map(&map);
		count_grids(argv[1], &map);
		allocate_memory(&map);
		pars_map(argv[1], &map);
		add_map_colors(&map);
		re_zoom(&map);
		make_window(&map);
	}
	msg_map_err(ERR_INP, 1);
	return (0);
}
