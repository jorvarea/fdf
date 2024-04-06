/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:53:57 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/06 03:59:14 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

mlx_image_t	*top_view(mlx_t *mlx, t_map *map, float zoom)
{
	int				i;
	int				j;
	float			spacing;
	t_coordinates	coord;
	mlx_image_t		*img;

	spacing = zoom * ft_min_float(mlx->width / map->ncols, mlx->height
		/ map->nrows);
	img = mlx_new_image(mlx, spacing * map->ncols, spacing * map->nrows);
	check_mlx_image_error(img);
	draw_image_border(img);
	i = 0;
	while (i < map->nrows)
	{
		j = 0;
		while (j < map->ncols)
		{
			coord.row = i;
			coord.col = j;
			connect_neighbours(img, map, &coord, spacing);
			j++;
		}
		i++;
	}
	check_mlx_image_to_window_error(mlx, img, (mlx->width / 2) - (spacing
			* map->ncols / 2), (mlx->height / 2) - (spacing * map->nrows / 2));
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
	img = top_view(mlx, &map, INITIAL_ZOOM);
	initialize_param(mlx, &map, img, &param);
	mlx_loop_hook(mlx, manage_key_pressed, &param);
	mlx_loop(mlx);
	termination(mlx, &map, &coord_matrix);
	return (0);
}
