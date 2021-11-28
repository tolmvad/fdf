/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:52:41 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/26 17:20:32 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move(int key, t_map *map)
{
	if (key == KEY_DOWN)
		map->shift_y += 10;
	else if (key == KEY_UP)
		map->shift_y -= 10;
	else if (key == KEY_LEFT)
		map->shift_x -= 10;
	else if (key == KEY_RIGHT)
		map->shift_x += 10;
	draw_map(map);
}

void	zoom(int key, t_map *map)
{
	if (key == KEY_PLUS && map->zoom < __INT_MAX__)
		(map->zoom)++;
	else if (key == KEY_MINUS && map->zoom > 2)
		(map->zoom)--;
	draw_map(map);
}

void	rotate(int key, t_map *map)
{
	if (key == KEY_Q)
		map->alpha -= ANGLE;
	else if (key == KEY_W)
		map->alpha += ANGLE;
	else if (key == KEY_A)
		map->beta -= ANGLE;
	else if (key == KEY_S)
		map->beta += ANGLE;
	else if (key == KEY_Z)
		map->gamma -= ANGLE;
	else if (key == KEY_X)
		map->gamma += ANGLE;
	draw_map(map);
}

void	iso(t_map *map)
{
	map->iso = 1;
	map->alpha = 0;
	map->beta = 0;
	map->gamma = 0;
	draw_map(map);
}

void	paral(t_map *map)
{
	map->iso = 0;
	map->alpha = 0;
	map->beta = 0;
	map->gamma = 0;
	draw_map(map);
}
