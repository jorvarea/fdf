/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:10:52 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/06 16:10:43 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_coord_matrix(t_coord_matrix *coord_matrix, int nrows,
		int ncols)
{
	int	i;

	coord_matrix->m = malloc(nrows * sizeof(t_point *));
	check_memory_allocation_error(coord_matrix->m);
	i = 0;
	while (i < nrows)
	{
		coord_matrix->m[i] = malloc(ncols * sizeof(t_point));
		check_memory_allocation_error(coord_matrix->m[i]);
		i++;
	}
	coord_matrix->nrows = nrows;
	coord_matrix->ncols = ncols;
}

void	free_coord_matrix_memory(t_coord_matrix *coord_matrix)
{
	int	i;

	i = 0;
	while (i < coord_matrix->nrows)
		free(coord_matrix->m[i++]);
	free(coord_matrix->m);
	coord_matrix->m = NULL;
}

void	calculate_coord_matrix(mlx_t *mlx, t_map *map,
		t_coord_matrix *coord_matrix)
{
	int		row;
	int		col;
	float	spacing;

	initialize_coord_matrix(coord_matrix, map->nrows, map->ncols);
	spacing = INITIAL_ZOOM * ft_min_float(mlx->width / map->ncols, 
			mlx->height / map->nrows);
	row = 0;
	while (row < map->nrows)
	{
		col = 0;
		while (col < map->ncols)
		{
			coord_matrix->m[row][col].xyz[0] = spacing * col;
			coord_matrix->m[row][col].xyz[1] = spacing * row;
			coord_matrix->m[row][col].xyz[2] = Z_SPACING_RATIO * spacing * map->data[row][col];
			coord_matrix->m[row][col].color = map->color[map->data[row][col]];
			col++;
		}
		row++;
	}
}
