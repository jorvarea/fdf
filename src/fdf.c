/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:53:57 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/26 22:35:57 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	top_view(mlx_t *mlx, t_map *map)
{
	int				i;
	int				j;
	int				spacing;
	t_coordinates	coord;
	mlx_image_t		*img;

	img = mlx_new_image(mlx, IMG_TO_WINDOW_RATIO * mlx->width,
			IMG_TO_WINDOW_RATIO * mlx->height);
	check_mlx_image_error(img);
	spacing = ft_min_float(img->width / map->ncols, img->height / map->nrows);
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
	mlx_image_to_window(mlx, img, (mlx->width / 2) - (img->width / 2),
		(mlx->height / 2) - (img->height / 2));
}

void	manage_key_pressed(void *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_map	map;

	check_argument_count_error(argc);
	ft_memset(&map, 0, sizeof(t_map));
	parse_map(argv[1], &map);
	check_valid_map_dimensions(&map);
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Fil de fer", true);
	check_mlx_error(mlx);
	background_image(mlx);
	top_view(mlx, &map);
	mlx_loop_hook(mlx, manage_key_pressed, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_map_memory(&map);
	return (0);
}
