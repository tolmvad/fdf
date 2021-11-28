/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:20:43 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/26 17:10:42 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	zoom_point(t_point *p, int zoom)
{
	p->x *= zoom;
	p->y *= zoom;
	p->z *= zoom;
}

static void	shift_point(t_point *p, t_map *map)
{
	p->x = p->x + map->offset_x + map->shift_x + MENU;
	p->y = p->y + map->offset_y + map->shift_y;
}

t_point	give_point(t_point p, t_map *map)
{
	zoom_point(&p, map->zoom);
	p.x -= (map->width * map->zoom) / 2;
	p.y -= (map->height * map->zoom) / 2;
	x_rotate(&p.y, &p.z, map->alpha);
	y_rotate(&p.x, &p.z, map->beta);
	z_rotate(&p.x, &p.y, map->gamma);
	if (map->iso)
		iso_proj(&p.x, &p.y, p.z);
	shift_point(&p, map);
	return (p);
}
