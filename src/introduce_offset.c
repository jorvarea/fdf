/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduce_offset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:51:43 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/07 03:41:34 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	calculate_x_offset(mlx_image_t *img,
		t_coord_matrix *coord_matrix)
{
	float	offset_x;
	float	min_x;
	float	max_x;
	int		i;
	int		j;

	max_x = coord_matrix->m[0][0].xyz[0];
	min_x = coord_matrix->m[0][0].xyz[0];
	i = 0;
	while (i < coord_matrix->nrows)
	{
		j = 0;
		while (j < coord_matrix->ncols)
		{
			if (coord_matrix->m[i][j].xyz[0] < min_x)
				min_x = coord_matrix->m[i][j].xyz[0];
			if (coord_matrix->m[i][j].xyz[0] > max_x)
				max_x = coord_matrix->m[i][j].xyz[0];
			j++;
		}
		i++;
	}
	offset_x = (img->width - (max_x - min_x)) / 2 - min_x;
	return (offset_x);
}

static float	calculate_y_offset(mlx_image_t *img,
		t_coord_matrix *coord_matrix)
{
	float	offset_y;
	float	min_y;
	float	max_y;
	int		i;
	int		j;

	max_y = coord_matrix->m[0][0].xyz[1];
	min_y = coord_matrix->m[0][0].xyz[1];
	i = 0;
	while (i < coord_matrix->nrows)
	{
		j = 0;
		while (j < coord_matrix->ncols)
		{
			if (coord_matrix->m[i][j].xyz[1] < min_y)
				min_y = coord_matrix->m[i][j].xyz[1];
			if (coord_matrix->m[i][j].xyz[1] > max_y)
				max_y = coord_matrix->m[i][j].xyz[1];
			j++;
		}
		i++;
	}
	offset_y = (img->height - (max_y - min_y)) / 2;
	return (offset_y);
}

void	introduce_offset(mlx_image_t *img, t_coord_matrix *coord_matrix)
{
	float	offset_x;
	float	offset_y;
	int		i;
	int		j;

	offset_x = calculate_x_offset(img, coord_matrix);
	offset_y = calculate_y_offset(img, coord_matrix);
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
