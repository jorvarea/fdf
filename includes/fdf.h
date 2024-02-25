/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:33:48 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/25 02:45:28 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include <math.h>
# include <fcntl.h>

# define INITIAL_MAP_DIMENSION 10

typedef struct s_map {
    int nrows;
    int ncols;
    int **data;
    int allocated_rows;
    int allocated_cols;
}   t_map;

// check_errors.c
void check_extension_error(char *filename);
void check_open_error(int fd);
void check_memory_allocation_error(void *ptr);

// manage_map_memory.c
void allocate_initial_map_memory(t_map *map);
void free_map_memory(t_map *map);
void copy_data(t_map *map, int **new_data);
void realloc_map_rows(t_map *map);
void realloc_map_cols(t_map *map);

// parse_map.c
void parse_map(char *filename, t_map *map);

// helper_functions.c
void print_map_array(t_map *map);

#endif