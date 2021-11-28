/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:42:41 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/26 17:19:21 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	allocate_memory(t_map *map)
{
	map->p = (t_point *)malloc(sizeof(t_point) * map->width * map->height);
	if (!map->p)
		terminate("malloc points");
}
