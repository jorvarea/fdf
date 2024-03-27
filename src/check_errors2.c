/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:38:30 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/27 18:15:08 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_valid_map_dimensions(t_map *map)
{
	if (map->nrows == 0 || map->ncols == 0)
	{
		ft_printf("Error: Map is empty\n");
		exit(EXIT_FAILURE);
	}
}

void	check_mlx_image_error(mlx_image_t *img)
{
	if (img == NULL)
	{
		ft_printf("Error: Image buffer allocation failed\n");
		exit(EXIT_FAILURE);
	}
}

void check_mlx_image_to_window_error(mlx_t *mlx, mlx_image_t *img, int32_t x, int32_t y)
{
	bool ok;
	ok = mlx_image_to_window(mlx, img, x, y) != -1;
	if (!ok)
	{
		ft_printf("Error: Image to window operation failed\n");
		exit(EXIT_FAILURE);
	}
}
