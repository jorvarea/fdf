/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_coord_matrix_memory.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:10:52 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/06 03:25:31 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_coord_matrix(t_coord_matrix *coord_matrix, int nrows,
		int ncols)
{
	int	i;

	coord_matrix->coord = malloc(nrows * sizeof(t_point *));
	check_memory_allocation_error(coord_matrix->coord);
	i = 0;
	while (i < nrows)
	{
		coord_matrix->coord[i] = malloc(ncols * sizeof(t_point));
		check_memory_allocation_error(coord_matrix->coord[i]);
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
		free(coord_matrix->coord[i++]);
	free(coord_matrix->coord);
	coord_matrix->coord = NULL;
}
