/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_rotation_matrix_memory.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:11:39 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/06 14:29:47 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	allocate_rot_matrix_memory(t_rot_matrix *rot_matrix,
		int nrows, int ncols)
{
	int	i;

	rot_matrix->m = malloc(nrows * sizeof(float *));
	check_memory_allocation_error(rot_matrix->m);
	i = 0;
	while (i < nrows)
	{
		rot_matrix->m[i] = malloc(ncols * sizeof(float));
		check_memory_allocation_error(rot_matrix->m[i]);
		i++;
	}
	rot_matrix->nrows = nrows;
	rot_matrix->ncols = ncols;
}

void	allocate_all_rot_matrix_memory(t_rot_matrix *rot_matrix_x,
		t_rot_matrix *rot_matrix_y, t_rot_matrix *rot_matrix_z)
{
	allocate_rot_matrix_memory(rot_matrix_x, 3, 3);
	allocate_rot_matrix_memory(rot_matrix_y, 3, 3);
	allocate_rot_matrix_memory(rot_matrix_z, 3, 3);
}

void	free_rot_matrix_memory(t_rot_matrix *rot_matrix)
{
	int	i;

	i = 0;
	while (i < rot_matrix->nrows)
	{
		free(rot_matrix->m[i]);
		i++;
	}
	free(rot_matrix->m);
	rot_matrix->m = NULL;
}

void	free_all_rot_matrix_memory(t_rot_matrix *rot_matrix_x,
		t_rot_matrix *rot_matrix_y, t_rot_matrix *rot_matrix_z)
{
	free_rot_matrix_memory(rot_matrix_x);
	free_rot_matrix_memory(rot_matrix_y);
	free_rot_matrix_memory(rot_matrix_z);
}
