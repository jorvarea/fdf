/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:53:57 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/27 00:48:23 by jorvarea         ###   ########.fr       */
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

	img = mlx_new_image(mlx, mlx->width, mlx->height);
	check_mlx_image_error(img);
	spacing = zoom * ft_min_float(img->width / map->ncols, img->height / map->nrows);
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
	mlx_image_to_window(mlx, img, (mlx->width / 2) - (spacing * map->ncols / 2),
		(mlx->height / 2) - (spacing * map->nrows / 2));
	return (img);
}

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_map	map;
	mlx_image_t *img;
	t_manage_key_param param;

	initialization(argc, argv, &mlx, &map);
	img = top_view(mlx, &map, 1.0);
	initialize_param(mlx, &map, img, &param);
	mlx_loop_hook(mlx, manage_key_pressed, &param);
	mlx_loop(mlx);
	termination(mlx, &map);
	return (0);
}
