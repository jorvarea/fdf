/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:33:48 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/07 20:10:46 by jorvarea         ###   ########.fr       */
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
# define DEFAULT_COLOR 0xFFA600FF
# define WINDOW_WIDTH 1400
# define WINDOW_HEIGHT 800
# define Z_SPACING_RATIO 0.1
# define STEPS_CONST 2000000
# define INITIAL_ZOOM 0.95
# define ZOOM_UNIT 0.01
# define ZOOM_LIMIT 3

typedef struct s_color_entry
{
	int				z;
	unsigned int	color;
}					t_color_entry;

typedef struct s_map
{
	int				nrows;
	int				ncols;
	int				ncolors;
	int				**data;
	t_color_entry	*color;
	int				allocated_rows;
	int				allocated_cols;
	int				allocated_colors;
}					t_map;

typedef struct s_color
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	unsigned int	alpha;
}					t_color;

typedef struct s_point
{
	float			xyz[3];
	unsigned int	color;
}					t_point;

typedef struct s_coord_matrix
{
	int				nrows;
	int				ncols;
	t_point			**m;
}					t_coord_matrix;

typedef struct s_rot_matrix
{
	int				nrows;
	int				ncols;
	float			**m;
}					t_rot_matrix;

typedef struct s_state
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_coord_matrix	*coord_matrix;
	float			zoom;
	float			z_spacing_ratio;
}					t_state;

// check_errors.c
void				check_argument_count_error(int argc);
void				check_extension_error(char *filename);
void				check_open_error(int fd);
void				check_memory_allocation_error(void *ptr);
void				check_mlx_error(mlx_t *mlx);

// check_errors2.c
void				check_valid_map_dimensions(t_map *map);
void				check_mlx_image_error(mlx_image_t *img);
void				check_mlx_image_to_window_error(mlx_t *mlx,
						mlx_image_t *img, int32_t x, int32_t y);

// manage_map_memory.c
void				allocate_initial_map_memory(t_map *map);
void				free_data_memory(t_map *map);
void				free_color_memory(t_map *map);
void				free_map_memory(t_map *map);

// realloc_memory.c
void				copy_data(t_map *map, int **new_data);
void				realloc_map_rows(t_map *map);
void				realloc_map_cols(t_map *map);
void				copy_colors(t_map *map, t_color_entry *new_colors);
void				realloc_map_colors(t_map *map);

// parse_map.c
void				parse_map(char *filename, t_map *map);

// helper_functions.c
void				print_map_array(t_map *map);
void				print_colors(t_map *map);
void				draw_image_border(mlx_image_t *img);

// connect_neighbours.c
void				connect_neighbours(mlx_image_t *img,
						t_coord_matrix *coord_matrix, int row, int col);

// background_image.c
void				background_image(mlx_t *mlx);

// manage_key_pressed.c
void				manage_key_pressed(void *ptr);

// initialization_and_termination.c
void				initialization(int argc, char **argv, mlx_t **mlx,
						t_map *map);
void				initialize_state(mlx_t *mlx, mlx_image_t *img,
						t_coord_matrix *coord_matrix, t_state *state);
void				termination(mlx_t *mlx, t_map *map,
						t_coord_matrix *coord_matrix);

// color.c
void				add_alpha_channel(t_map *map);
unsigned int		find_color(t_map *map, int z);
unsigned int		color_gradient(unsigned int color_a, unsigned int color_b,
						float coefficient);

// coord_matrix.c
void				initialize_coord_matrix(t_coord_matrix *coord_matrix,
						int nrows, int ncols);
void				free_coord_matrix_memory(t_coord_matrix *coord_matrix);
void				calculate_coord_matrix(mlx_t *mlx, t_map *map,
						t_coord_matrix *coord_matrix);

// introduce_offset.c
void				introduce_offset(mlx_image_t *img,
						t_coord_matrix *coord_matrix);

// manage_rotation_matrix_memory.c
void				allocate_rot_matrix_memory(t_rot_matrix *rot_matrix,
						int nrows, int ncols);
void				allocate_all_rot_matrix_memory(t_rot_matrix *rot_matrix_x,
						t_rot_matrix *rot_matrix_y, t_rot_matrix *rot_matrix_z);
void				free_rot_matrix_memory(t_rot_matrix *rot_matrix);
void				free_all_rot_matrix_memory(t_rot_matrix *rot_matrix_x,
						t_rot_matrix *rot_matrix_y, t_rot_matrix *rot_matrix_z);

// calculate_rotation_matrix.c
void				calculate_x_rot_matrix(t_rot_matrix *rot_matrix,
						float theta_x);
void				calculate_y_rot_matrix(t_rot_matrix *rot_matrix,
						float theta_y);
void				calculate_z_rot_matrix(t_rot_matrix *rot_matrix,
						float theta_z);

// perform_rotation.c
void				perform_point_rot(t_coord_matrix *coord_matrix,
						t_rot_matrix *rot_matrix, int row, int col);
void				perform_rotation(t_coord_matrix *coord_matrix,
						float theta_x, float theta_y, float theta_z);

// projection_2d.c
mlx_image_t			*projection_2d(mlx_t *mlx, t_coord_matrix *coord_matrix);

#endif