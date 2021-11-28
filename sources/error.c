/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcaffere <bcaffere@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:34:33 by bcaffere          #+#    #+#             */
/*   Updated: 2021/11/26 16:33:38 by bcaffere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	msg_map_err(char *msg, int count)
{
	write(2, ERR_MAP, ft_strlen(ERR_MAP));
	write(2, msg, ft_strlen(msg));
	exit(count);
}

void	terminate(char *str)
{
	perror(str);
	exit(1);
}
