/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:02:05 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/19 23:50:56 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void check_valid_extension(char *filename)
{
    char *extension;
    int i;

    i = 0;
    extension = NULL;
    while(filename[i] != '\0')
    {
        if (filename[i] == '.')
            extension = &filename[i + 1];
        i++;
    }
    if (extension == NULL || ft_strncmp(extension, "fdf", 3) != 0)
    {
        ft_printf("Error: Invalid file extension\n");
        exit(1);
    }
}

void check_valid_file(int fd)
{
    if (fd == -1)
    {
        ft_printf("Error: Couldn't open file\n");
        exit(1);
    }
}

void store_elements(char *line, t_map *map)
{
    char **elements;
    int column;

    elements = ft_split(line, ' ');
    column = 0;
    while (elements[column] != NULL)
    {
        // need to allocate memory to map->data before doing this
        map->data[map->nrows][column] = ft_atoi(elements[column]);
        free(elements[column]);
        column++;
    }
    map->nrows++;
    free(elements);
}

void parse_map(char *filename, t_map *map)
{
    int fd;
    char *line;
    
    check_valid_extension(filename);
    fd = open(filename, O_RDONLY);
    check_valid_file(fd);
    line = get_next_line(fd);
    while (line != NULL)
    {
        store_elements(line, map);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}
