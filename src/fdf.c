/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:53:57 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/07 19:04:12 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

mlx_image_t	*projection_2d(mlx_t *mlx, t_coord_matrix *coord_matrix)
{
	int			i;
	int			j;
	mlx_image_t	*img;

	img = mlx_new_image(mlx, mlx->width, mlx->height);
	check_mlx_image_error(img);
	introduce_offset(img, coord_matrix);
	i = 0;
	while (i < coord_matrix->nrows)
	{
		j = 0;
		while (j < coord_matrix->ncols)
		{
			connect_neighbours(img, coord_matrix, i, j);
			j++;
		}
		i++;
	}
	check_mlx_image_to_window_error(mlx, img, 0, 0);
	return (img);
}

int	main(int argc, char **argv)
{
	mlx_t				*mlx;
	t_map				map;
	mlx_image_t			*img;
	t_manage_key_param	param;
	t_coord_matrix		coord_matrix;

	initialization(argc, argv, &mlx, &map);
	calculate_coord_matrix(mlx, &map, &coord_matrix);
	perform_rotation(&coord_matrix, atan(sqrt(2)), 0, M_PI / 4);
	// fix the random peaks and the color problems
	img = projection_2d(mlx, &coord_matrix);
	// review the param initialization and zoom calculations
	initialize_param(mlx, &map, img, &param);
	mlx_loop_hook(mlx, manage_key_pressed, &param);
	mlx_loop(mlx);
	termination(mlx, &map, &coord_matrix);
	return (0);
}
