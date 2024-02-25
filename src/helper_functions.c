/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 02:43:03 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/25 18:04:13 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map_array(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->nrows)
	{
		j = 0;
		while (j < map->ncols)
		{
			ft_printf("%d ", map->data[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_colors(t_map *map)
{
	int	i;
	int	red;
	int	green;
	int	blue;

	i = 0;
	while (i < map->allocated_colors)
	{
		red = (map->color[i] >> 16) & 0xFF;
		green = (map->color[i] >> 8) & 0xFF;
		blue = map->color[i] & 0xFF;
		printf("\033[38;2;%d;%d;%dm%d: 0x%X\033[0m\n", red, green, blue, i,
			map->color[i]);
		i++;
	}
}
