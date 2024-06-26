/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:00:02 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/13 20:11:37 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	copy_data(t_map *map, int **new_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->allocated_rows)
	{
		j = 0;
		while (j < map->allocated_cols)
		{
			new_data[i][j] = map->data[i][j];
			j++;
		}
		i++;
	}
}

void	realloc_map_rows(t_map *map)
{
	int	new_allocated_rows;
	int	**new_data;
	int	i;

	new_allocated_rows = map->allocated_rows * 2;
	new_data = malloc(new_allocated_rows * sizeof(int *));
	check_memory_allocation_error(new_data);
	i = 0;
	while (i < new_allocated_rows)
	{
		new_data[i] = malloc(map->allocated_cols * sizeof(int));
		check_memory_allocation_error(new_data[i]);
		i++;
	}
	copy_data(map, new_data);
	free_data_memory(map);
	map->allocated_rows = new_allocated_rows;
	map->data = new_data;
}

void	realloc_map_cols(t_map *map)
{
	int	new_allocated_cols;
	int	**new_data;
	int	i;

	new_allocated_cols = map->allocated_cols * 2;
	new_data = malloc(map->allocated_rows * sizeof(int *));
	check_memory_allocation_error(new_data);
	i = 0;
	while (i < map->allocated_rows)
	{
		new_data[i] = malloc(new_allocated_cols * sizeof(int));
		check_memory_allocation_error(new_data[i]);
		i++;
	}
	copy_data(map, new_data);
	free_data_memory(map);
	map->allocated_cols = new_allocated_cols;
	map->data = new_data;
}

void	copy_colors(t_map *map, t_color_entry *new_colors)
{
	int	i;

	i = 0;
	while (i < map->ncolors)
	{
		new_colors[i].z = map->color[i].z;
		new_colors[i].color = map->color[i].color;
		i++;
	}
}

void	realloc_map_colors(t_map *map)
{
	int				new_allocated_colors;
	t_color_entry	*new_colors;

	new_allocated_colors = map->allocated_colors * 2;
	new_colors = malloc(new_allocated_colors * sizeof(t_color_entry));
	check_memory_allocation_error(new_colors);
	ft_memset(new_colors, 0, new_allocated_colors * sizeof(t_color_entry));
	copy_colors(map, new_colors);
	free_color_memory(map);
	map->allocated_colors = new_allocated_colors;
	map->color = new_colors;
}
