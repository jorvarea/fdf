/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:27:23 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/25 14:26:30 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	allocate_initial_map_memory(t_map *map)
{
	int	i;

	map->color = malloc(INITIAL_COLORS_DIMENSION * sizeof(int));
	check_memory_allocation_error(map->color);
	map->data = malloc(INITIAL_MAP_DIMENSION * sizeof(int *));
	check_memory_allocation_error(map->data);
	i = 0;
	while (i < INITIAL_MAP_DIMENSION)
	{
		map->data[i] = malloc(INITIAL_MAP_DIMENSION * sizeof(int));
		check_memory_allocation_error(map->data[i]);
		i++;
	}
	map->allocated_rows = INITIAL_MAP_DIMENSION;
	map->allocated_cols = INITIAL_MAP_DIMENSION;
	map->allocated_colors = INITIAL_COLORS_DIMENSION;
}

void	free_data_memory(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->allocated_rows)
		free(map->data[i++]);
	free(map->data);
	map->data = NULL;
}

void	free_color_memory(t_map *map)
{
	free(map->color);
	map->color = NULL;
}

void	free_map_memory(t_map *map)
{
	free_data_memory(map);
	free_color_memory(map);
}
