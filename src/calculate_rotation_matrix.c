/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotation_matrix.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:03:29 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/06 14:23:22 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_x_rot_matrix(t_rot_matrix *rot_matrix, float theta_x)
{
	rot_matrix->m[0][0] = 1;
	rot_matrix->m[0][1] = 0;
	rot_matrix->m[0][2] = 0;
	rot_matrix->m[1][0] = 0;
	rot_matrix->m[1][1] = cos(theta_x);
	rot_matrix->m[1][2] = -sin(theta_x);
	rot_matrix->m[2][0] = 0;
	rot_matrix->m[2][1] = sin(theta_x);
	rot_matrix->m[2][2] = cos(theta_x);
}

void	calculate_y_rot_matrix(t_rot_matrix *rot_matrix, float theta_y)
{
	rot_matrix->m[0][0] = cos(theta_y);
	rot_matrix->m[0][1] = 0;
	rot_matrix->m[0][2] = sin(theta_y);
	rot_matrix->m[1][0] = 0;
	rot_matrix->m[1][1] = 1;
	rot_matrix->m[1][2] = 0;
	rot_matrix->m[2][0] = -sin(theta_y);
	rot_matrix->m[2][1] = 0;
	rot_matrix->m[2][2] = cos(theta_y);
}

void	calculate_z_rot_matrix(t_rot_matrix *rot_matrix, float theta_z)
{
	rot_matrix->m[0][0] = cos(theta_z);
	rot_matrix->m[0][1] = -sin(theta_z);
	rot_matrix->m[0][2] = 0;
	rot_matrix->m[1][0] = sin(theta_z);
	rot_matrix->m[1][1] = cos(theta_z);
	rot_matrix->m[1][2] = 0;
	rot_matrix->m[2][0] = 0;
	rot_matrix->m[2][1] = 0;
	rot_matrix->m[2][2] = 1;
}
