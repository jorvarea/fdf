/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:53:57 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/27 00:42:49 by jorvarea         ###   ########.fr       */
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

void	manage_key_pressed(void *ptr)
{
	t_manage_key_param *param;
	
	param = (t_manage_key_param *)ptr;
	if (mlx_is_key_down(param->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(param->mlx);
	if (mlx_is_key_down(param->mlx, MLX_KEY_P))
	{
		param->zoom += ZOOM_UNIT;
		mlx_delete_image(param->mlx, param->current_img);
		param->current_img = top_view(param->mlx, param->map, param->zoom);
	}
	else if (mlx_is_key_down(param->mlx, MLX_KEY_O))
	{
		if (param->zoom >= ZOOM_UNIT)
			param->zoom -= ZOOM_UNIT;
		else
			param->zoom = 0;
		mlx_delete_image(param->mlx, param->current_img);
		param->current_img = top_view(param->mlx, param->map, param->zoom);
	}
}

void initialization(int argc, char **argv, mlx_t **mlx, t_map *map)
{
	check_argument_count_error(argc);
	ft_memset(map, 0, sizeof(t_map));
	parse_map(argv[1], map);
	check_valid_map_dimensions(map);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	*mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Fil de fer", true);
	check_mlx_error(*mlx);
	background_image(*mlx);
}

void initialize_param(mlx_t *mlx, t_map *map, mlx_image_t *img, t_manage_key_param *param)
{
	param->mlx = mlx;
	param->map = map;
	param->current_img = img;
	param->zoom = 1.0;
}

void termination(mlx_t *mlx, t_map *map)
{
	mlx_terminate(mlx);
	free_map_memory(map);
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
