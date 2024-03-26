/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:33:48 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/27 00:36:46 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define INITIAL_MAP_DIMENSION 10
# define INITIAL_COLORS_DIMENSION 20
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 700
# define ZOOM_UNIT 0.01

typedef struct s_map
{
	int				nrows;
	int				ncols;
	int				**data;
	unsigned int	*color;
	int				allocated_rows;
	int				allocated_cols;
	int				allocated_colors;
}					t_map;

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	color;
}					t_point;

typedef struct s_coordinates
{
	int				row;
	int				col;
}					t_coordinates;

typedef struct s_manage_key_param
{
	mlx_t *mlx;
	t_map *map;
	mlx_image_t *current_img;
	float zoom;
}					t_manage_key_param;

// check_errors.c
void				check_argument_count_error(int argc);
void				check_extension_error(char *filename);
void				check_open_error(int fd);
void				check_memory_allocation_error(void *ptr);
void				check_mlx_error(mlx_t *mlx);

// check_errors2.c
void				check_valid_map_dimensions(t_map *map);
void				check_mlx_image_error(mlx_image_t *img);

// manage_map_memory.c
void				allocate_initial_map_memory(t_map *map);
void				free_data_memory(t_map *map);
void				free_color_memory(t_map *map);
void				free_map_memory(t_map *map);

// realloc_memory.c
void				copy_data(t_map *map, int **new_data);
void				realloc_map_rows(t_map *map);
void				realloc_map_cols(t_map *map);
void				copy_colors(t_map *map, unsigned int *new_colors);
void				realloc_map_colors(t_map *map);

// parse_map.c
void				parse_map(char *filename, t_map *map);

// helper_functions.c
void				print_map_array(t_map *map);
void				print_colors(t_map *map);

// connect_neighbours.c
void				connect_neighbours(mlx_image_t *img, t_map *map,
						t_coordinates *coord, float spacing);

// background_image.c
void				background_image(mlx_t *mlx);

#endif