/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_and_termination.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:48:24 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/27 00:48:31 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialization(int argc, char **argv, mlx_t **mlx, t_map *map)
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

void	initialize_param(mlx_t *mlx, t_map *map, mlx_image_t *img,
		t_manage_key_param *param)
{
	param->mlx = mlx;
	param->map = map;
	param->current_img = img;
	param->zoom = 1.0;
}

void	termination(mlx_t *mlx, t_map *map)
{
	mlx_terminate(mlx);
	free_map_memory(map);
}
