/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grids.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:57:26 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/27 16:00:38 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->p = NULL;
	map->mlx = NULL;
	map->mlx_win = NULL;
	map->img = NULL;
	map->addr = NULL;
	map->bits_per_pixel = 0;
	map->size_line = 0;
	map->endian = 0;
	map->offset_x = (WIDTH - MENU) / 2;
	map->offset_y = HEIGHT / 2;
	map->shift_x = 0;
	map->shift_y = 0;
	map->zoom = 1;
	map->alpha = 0;
	map->beta = 0;
	map->gamma = 0;
	map->iso = 1;
}

static int	count_axes(char *line)
{
	int		num;
	int		i;

	num = 0;
	i = 0;
	while (*line)
	{
		if (*line != ' ')
			i++;
		else if (i)
		{
			i = 0;
			num++;
		}
		line++;
	}
	if (i)
		num++;
	return (num);
}

void	count_grids(char *file, t_map *map)
{
	int		fd;
	int		tmp;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		terminate(file);
	tmp = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map->width = count_axes(line);
		free(line);
		if (!tmp)
			tmp = map->width;
		if (map->width != tmp)
			msg_map_err(ERR_AXES, 3);
		(map->height)++;
	}
	if (line)
		free(line);
	if (map->width == 0)
		msg_map_err(ERR_EMP, 2);
	close(fd);
}
