/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:02:05 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/07 19:06:51 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	z_color_defined(t_map *map, int z)
{
	bool	found;
	int		i;

	found = false;
	i = 0;
	while (i < map->ncolors && !found)
	{
		if (map->color[i].z == z)
			found = true;
		i++;
	}
	return (found);
}

static void	store_color(char *element, t_map *map, int data_value)
{
	char	*color_str;
	int		i;

	color_str = NULL;
	i = 0;
	while (element[i] && !color_str)
	{
		if (element[i] == ',')
			color_str = &element[i + 1];
		i++;
	}
	if (color_str && !z_color_defined(map, data_value))
	{
		if (map->ncolors + 1 > map->allocated_colors)
			realloc_map_colors(map);
		map->color[map->ncolors].z = data_value;
		map->color[map->ncolors].color = ft_atoi_hex(color_str);
		map->ncolors++;
	}
}

static void	store_elements(char *line, t_map *map)
{
	char	**elements;
	int		column;

	if (map->nrows + 1 > map->allocated_rows)
		realloc_map_rows(map);
	elements = ft_split(line, ' ');
	column = 0;
	while (elements[column] != NULL)
	{
		if (column + 1 > map->allocated_cols)
			realloc_map_cols(map);
		map->data[map->nrows][column] = ft_atoi(elements[column]);
		store_color(elements[column], map, map->data[map->nrows][column]);
		free(elements[column]);
		column++;
	}
	map->nrows++;
	if (map->ncols == 0)
		map->ncols = column;
	free(elements);
}

void	parse_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	check_extension_error(filename);
	fd = open(filename, O_RDONLY);
	check_open_error(fd);
	allocate_initial_map_memory(map);
	line = get_next_line(fd);
	while (line != NULL)
	{
		store_elements(line, map);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
