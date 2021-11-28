/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:04:41 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/27 15:21:43 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_points(char *str, t_map *map, int j)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (*str)
	{
		if (*str != ' ' && flag)
		{
			map->p[j * map->width + i].x = i;
			map->p[j * map->width + i].y = j;
			map->p[j * map->width + i].z = ft_atoi(str);
			i++;
			flag = 0;
		}
		else if (*str == ' ')
			flag = 1;
		str++;
	}
}

void	pars_map(char *file, t_map *map)
{
	int		fd;
	int		j;
	char	*line;

	fd = open(file, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		get_points(line, map, j);
		free(line);
		j++;
	}
	if (line)
		free(line);
	close(fd);
}
