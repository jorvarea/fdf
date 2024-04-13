/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transformation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:59:18 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/13 21:50:33 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	perform_zoom(t_coord_matrix *coord_matrix, float scale_factor,
		t_point *focus)
{
	int	i;
	int	j;

	i = 0;
	while (i < coord_matrix->nrows)
	{
		j = 0;
		while (j < coord_matrix->ncols)
		{
			coord_matrix->m[i][j].xyz[0] = scale_factor
				* (coord_matrix->m[i][j].xyz[0] - focus->xyz[0])
				+ focus->xyz[0];
			coord_matrix->m[i][j].xyz[1] = scale_factor
				* (coord_matrix->m[i][j].xyz[1] - focus->xyz[1])
				+ focus->xyz[1];
			j++;
		}
		i++;
	}
}

void	perform_point_rot(t_coord_matrix *coord_matrix,
		t_rot_matrix *rot_matrix, int row, int col)
{
	t_point	temp;
	int		i;
	int		j;
	float	suma;

	i = 0;
	while (i < rot_matrix->nrows)
	{
		suma = 0;
		j = 0;
		while (j < rot_matrix->ncols)
		{
			suma += rot_matrix->m[i][j] * coord_matrix->m[row][col].xyz[j];
			j++;
		}
		temp.xyz[i] = suma;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		coord_matrix->m[row][col].xyz[i] = temp.xyz[i];
		i++;
	}
}

void	perform_rotation(t_coord_matrix *coord_matrix, float theta_x,
		float theta_y, float theta_z)
{
	t_rot_matrix	rot_matrix_x;
	t_rot_matrix	rot_matrix_y;
	t_rot_matrix	rot_matrix_z;
	int				i;
	int				j;

	allocate_all_rot_matrix_memory(&rot_matrix_x, &rot_matrix_y, &rot_matrix_z);
	calculate_x_rot_matrix(&rot_matrix_x, theta_x);
	calculate_y_rot_matrix(&rot_matrix_y, theta_y);
	calculate_z_rot_matrix(&rot_matrix_z, theta_z);
	i = 0;
	while (i < coord_matrix->nrows)
	{
		j = 0;
		while (j < coord_matrix->ncols)
		{
			perform_point_rot(coord_matrix, &rot_matrix_z, i, j);
			perform_point_rot(coord_matrix, &rot_matrix_y, i, j);
			perform_point_rot(coord_matrix, &rot_matrix_x, i, j);
			j++;
		}
		i++;
	}
	free_all_rot_matrix_memory(&rot_matrix_x, &rot_matrix_y, &rot_matrix_z);
}

void	perform_translation(t_coord_matrix *coord_matrix, int offset_x,
		int offset_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < coord_matrix->nrows)
	{
		j = 0;
		while (j < coord_matrix->ncols)
		{
			coord_matrix->m[i][j].xyz[0] += offset_x;
			coord_matrix->m[i][j].xyz[1] += offset_y;
			j++;
		}
		i++;
	}
}
