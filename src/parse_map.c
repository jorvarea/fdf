/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:02:05 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/25 16:09:19 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void store_color(char *element, t_map *map, int data_value)
{
    char *color;
    int i;

    color = NULL;
    i = 0;
    while (element[i] && !color)
    {
        if (element[i] == ',')
            color = &element[i + 1];
        i++;
    }
    if (color)
    {
        if (data_value > map->allocated_colors - 1)
            realloc_map_colors(map);
        map->color[data_value] = ft_atoi_hex(color);
    }
}

static void store_elements(char *line, t_map *map)
{
    char **elements;
    int column;

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

void parse_map(char *filename, t_map *map)
{
    int fd;
    char *line;
    
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
