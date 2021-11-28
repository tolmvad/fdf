/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:18:22 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/26 17:15:29 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;

	if (x >= MENU && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = map->addr + (y * map->size_line + x * (map->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
