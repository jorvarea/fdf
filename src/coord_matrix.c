/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:59:18 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/06 03:59:26 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_coord_matrix(mlx_t *mlx, t_map *map,
		t_coord_matrix *coord_matrix)
{
	int		row;
	int		col;
	float	spacing;

	initialize_coord_matrix(coord_matrix, map->nrows, map->nrows);
	spacing = INITIAL_ZOOM * ft_min_float(mlx->width / map->ncols, mlx->height
		/ map->nrows);
	row = 0;
	while (row < map->nrows)
	{
		col = 0;
		while (col < map->ncols)
		{
			coord_matrix->coord[row][col].x = spacing * col;
			coord_matrix->coord[row][col].y = spacing * row;
			coord_matrix->coord[row][col].z = map->data[row][col];
			coord_matrix->coord[row][col].color = map->color[map->data[row][col]];
			col++;
		}
		row++;
	}
}
