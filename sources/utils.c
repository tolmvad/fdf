/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 21:03:09 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/26 21:32:01 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	percent(int cur, int min, int max)
{
	double	range;
	double	delta;

	range = max - min;
	delta = cur - min;
	if (range == 0)
		return (1.0);
	else
		return (delta / range);
}

int	sign(int x, int y)
{
	if (x < y)
		return (1);
	else
		return (-1);
}

void	re_zoom(t_map *map)
{
	if ((WIDTH - MENU) / map->width / 4 > HEIGHT / map->height / 4)
		map->zoom = HEIGHT / map->height / 4;
	else
		map->zoom = (WIDTH - MENU) / map->width / 4;
	if (map->zoom < 1)
		map->zoom = 2;
}
