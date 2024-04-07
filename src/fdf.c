/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:53:57 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/07 20:12:22 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	t_map			map;
	mlx_image_t		*img;
	t_state			state;
	t_coord_matrix	coord_matrix;

	initialization(argc, argv, &mlx, &map);
	calculate_coord_matrix(mlx, &map, &coord_matrix);
	perform_rotation(&coord_matrix, atan(sqrt(2)), 0, M_PI / 4);
	// fix the random peaks and the color problems
	img = projection_2d(mlx, &coord_matrix);
	initialize_state(mlx, img, &coord_matrix, &state);
	mlx_loop_hook(mlx, manage_key_pressed, &state);
	mlx_loop(mlx);
	termination(mlx, &map, &coord_matrix);
	return (0);
}
