/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_and_termination.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:48:24 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/11 01:20:54 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialization(int argc, char **argv, mlx_t **mlx, t_map *map)
{
	check_argument_count_error(argc);
	ft_memset(map, 0, sizeof(t_map));
	parse_map(argv[1], map);
	check_valid_map_dimensions(map);
	add_alpha_channel(map);
	*mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Fil de fer", true);
	check_mlx_error(*mlx);
	background_image(*mlx);
	print_menu(*mlx);
}

void	initialize_state(mlx_t *mlx, mlx_image_t *img,
		t_coord_matrix *coord_matrix, t_state *state)
{
	state->mlx = mlx;
	state->img = img;
	state->coord_matrix = coord_matrix;
	state->zoom = INITIAL_ZOOM;
	state->z_spacing_ratio = Z_SPACING_RATIO;
	state->translated_x = 0;
	state->translated_y = 0;
}

void	initialize_state_continuation(t_map *map, t_state *state)
{
	state->map = map;
}

void	termination(mlx_t *mlx, t_map *map, t_coord_matrix *coord_matrix)
{
	mlx_terminate(mlx);
	free_map_memory(map);
	free_coord_matrix_memory(coord_matrix);
}
