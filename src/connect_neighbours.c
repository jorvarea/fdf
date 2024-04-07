/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_neighbours.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:14:11 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/07 19:00:16 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static bool	point_inside_img(mlx_image_t *img, float x, float y)
{
	unsigned int	actual_x;
	unsigned int	actual_y;

	actual_x = ft_round(x);
	actual_y = ft_round(y);
	return (actual_x >= 0 && actual_y >= 0 && actual_x < img->width
		&& actual_y < img->height);
}

static void	draw_inverse_slope_line(mlx_image_t *img, t_point *a, t_point *b)
{
	t_point 		current;
	float			slope;
	float 			step;
	int 			i;
	

	slope = (b->xyz[0] - a->xyz[0]) / (b->xyz[1] - a->xyz[1]);
	current.xyz[1] = a->xyz[1];
	i = 0;
	while (i < STEPS)
	{
		step = (b->xyz[1] - a->xyz[1]) / STEPS;
		current.xyz[0] = a->xyz[0] + slope * (current.xyz[1] - a->xyz[1]);
		if (a->color != b->color)
			current.color = color_gradient(a->color, b->color, 1.0 * i / STEPS);
		else
			current.color = a->color;
		if (point_inside_img(img, current.xyz[0], current.xyz[1]))
			mlx_put_pixel(img, ft_round(current.xyz[0]), ft_round(current.xyz[1]), current.color);
		current.xyz[1] += step;
		i++;
	}
}

static void	draw_line_between_points(mlx_image_t *img, t_point *a, t_point *b)
{
	t_point			current;
	float			slope;
	float 			step;
	int 			i;

	slope = (b->xyz[1] - a->xyz[1]) / (b->xyz[0] - a->xyz[0]);
	if (ft_abs_float(slope) <= 1)
	{
		current.xyz[0] = a->xyz[0];
		step = (b->xyz[0] - a->xyz[0]) / STEPS;
		i = 0;
		while (i < STEPS)
		{
			current.xyz[1] = a->xyz[1] + slope * (current.xyz[0] - a->xyz[0]);
			if (a->color != b->color)
				current.color = color_gradient(a->color, b->color, 1.0 * i / STEPS);
			else
				current.color = a->color;
			if (point_inside_img(img, current.xyz[0], current.xyz[1]))
				mlx_put_pixel(img, ft_round(current.xyz[0]), ft_round(current.xyz[1]), current.color);
			current.xyz[0] += step;
			i++;
		}
	}
	else
		draw_inverse_slope_line(img, a, b);
}

void	connect_neighbours(mlx_image_t *img, t_coord_matrix *coord_matrix,
		int row, int col)
{
	if (row > 0)
		draw_line_between_points(img, &coord_matrix->m[row - 1][col],
			&coord_matrix->m[row][col]);
	if (col > 0)
		draw_line_between_points(img, &coord_matrix->m[row][col - 1],
			&coord_matrix->m[row][col]);
}
