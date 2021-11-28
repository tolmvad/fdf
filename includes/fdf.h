/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:39:04 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/27 16:00:34 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>

/* to open */
# include <fcntl.h>

/* to read, write, close */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* to malloc, free, exit */
# include <stdlib.h>

/* to perror, strerror */
# include <stdio.h>

/* to get_next_line */
# include "../gnl/get_next_line.h"

# include "color.h"
# include "menu.h"
# include "settings.h"
# include "keys.h"
# include "error.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	*p;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		iso;
	int		zoom;
	int		offset_x;
	int		offset_y;
	int		shift_y;
	int		shift_x;
	float	alpha;
	float	beta;
	float	gamma;
}t_map;

/* memory.c */
void	allocate_memory(t_map *map);
void	free_map(t_map *map, int f);

/* pars.c */
void	pars_map(char *file, t_map *map);

/* color.c */
void	add_map_colors(t_map *map);
int		coloring(t_point cur, t_point p1, t_point p2, t_point d);

/* grids.c */
void	init_map(t_map *map);
void	count_grids(char *file, t_map *map);

/* error.c */
void	msg_map_err(char *msg, int count);
void	terminate(char *str);

/* hooks_handler.c */
int		key_hook(int key, t_map *map);
void	hooks_handler(t_map *map);

/* do_hooks.c */
void	move(int key, t_map *map);
void	zoom(int key, t_map *map);
void	rotate(int key, t_map *map);
void	iso(t_map *map);
void	paral(t_map *map);

/* point.c */
t_point	give_point(t_point p, t_map *map);

/* pixel_put.c */
void	my_mlx_pixel_put(t_map *map, int x, int y, int color);

/* draw.c */
void	draw_map(t_map *map);

/* utils.c */
double	percent(int cur, int min, int max);
int		sign(int x, int y);
void	re_zoom(t_map *map);

/* axes.c */
void	x_rotate(int *y, int *z, float alpha);
void	y_rotate(int *x, int *z, float beta);
void	z_rotate(int *x, int *y, float gamma);
void	iso_proj(int *x, int *y, int z);

/* functions */
int		ft_atoi(const char *s);
int		ft_isdigit(int c);

#endif
