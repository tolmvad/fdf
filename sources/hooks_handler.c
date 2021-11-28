/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:50:22 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/27 15:38:25 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int key, t_map *map)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP)
		move(key, map);
	if (key == KEY_PLUS || key == KEY_MINUS)
		zoom(key, map);
	if (key == KEY_Q || key == KEY_W || key == KEY_A || key == KEY_S
		|| key == KEY_Z || key == KEY_X)
		rotate(key, map);
	if (key == KEY_I)
		iso(map);
	if (key == KEY_P)
		paral(map);
	return (0);
}

static int	close_window(void)
{
	exit(1);
}

void	hooks_handler(t_map *map)
{
	mlx_hook(map->mlx_win, 2, 0, key_hook, map);
	mlx_hook(map->mlx_win, 17, 0, close_window, map);
}
