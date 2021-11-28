/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:13:33 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/26 21:32:33 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_controls(t_map *map)
{
	int	y;

	y = 0;
	mlx_string_put(map->mlx, map->mlx_win, 55, y += 20, C_TEXT, T_CNTRLS);
	mlx_string_put(map->mlx, map->mlx_win, 20, y += 30, C_TEXT, T_ZOOM_P);
	mlx_string_put(map->mlx, map->mlx_win, 20, y += 20, C_TEXT, T_ZOOM_M);
	mlx_string_put(map->mlx, map->mlx_win, 20, y += 30, C_TEXT, T_MOVES);
	mlx_string_put(map->mlx, map->mlx_win, 60, y += 30, C_TEXT, T_ROTATE);
	mlx_string_put(map->mlx, map->mlx_win, 20, y += 20, C_TEXT, T_X);
	mlx_string_put(map->mlx, map->mlx_win, 20, y += 20, C_TEXT, T_Y);
	mlx_string_put(map->mlx, map->mlx_win, 20, y += 20, C_TEXT, T_Z);
	mlx_string_put(map->mlx, map->mlx_win, 45, y += 30, C_TEXT, T_PROJ);
	mlx_string_put(map->mlx, map->mlx_win, 20, y += 20, C_TEXT, T_PARAL);
	mlx_string_put(map->mlx, map->mlx_win, 20, y += 20, C_TEXT, T_ISO);
}

static void	draw_background(t_map *map)
{
	int	*img;
	int	i;

	img = (int *)map->addr;
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		if (i % WIDTH < MENU)
			img[i] = C_MENU;
		else
			img[i] = C_BACKGROUND;
		i++;
	}
}

static void	draw_line(t_point p1, t_point p2, t_map *map)
{
	t_point	d;
	t_point	s;
	t_point	tmp;

	d.x = abs(p2.x - p1.x);
	d.y = abs(p2.y - p1.y);
	s.x = sign(p1.x, p2.x);
	s.y = sign(p1.y, p2.y);
	d.z = d.x - d.y;
	tmp = p1;
	while (tmp.x != p2.x || tmp.y != p2.y)
	{
		my_mlx_pixel_put(map, tmp.x, tmp.y, coloring(tmp, p1, p2, d));
		s.z = d.z * 2;
		if (s.z > -d.y)
		{
			d.z -= d.y;
			tmp.x += s.x;
		}
		if (s.z < d.x)
		{
			d.z += d.x;
			tmp.y += s.y;
		}
	}
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	draw_background(map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(give_point(map->p[x + y * map->width], map),
					give_point(map->p[x + 1 + y * map->width], map), map);
			if (y < map->height - 1)
				draw_line(give_point(map->p[x + y * map->width], map),
					give_point(map->p[x + (y + 1) * map->width], map), map);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, 0, 0);
	draw_controls(map);
}
