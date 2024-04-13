/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_neighbours.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:14:11 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/13 20:23:25 by jorvarea         ###   ########.fr       */
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

static void	draw_inverse_slope_line(mlx_image_t *img, t_point *a, t_point *b,
		int total_steps)
{
	t_point	current;
	float	slope;
	float	step;
	int		i;

	slope = (b->xyz[0] - a->xyz[0]) / (b->xyz[1] - a->xyz[1]);
	current.xyz[1] = a->xyz[1];
	i = 0;
	while (i < total_steps)
	{
		step = (b->xyz[1] - a->xyz[1]) / total_steps;
		current.xyz[0] = a->xyz[0] + slope * (current.xyz[1] - a->xyz[1]);
		current.color = color_gradient(a->color, b->color,
				1.0 * i / total_steps);
		if (point_inside_img(img, current.xyz[0], current.xyz[1]))
			mlx_put_pixel(img, ft_round(current.xyz[0]),
				ft_round(current.xyz[1]), current.color);
		current.xyz[1] += step;
		i++;
	}
}

static void	draw_line_between_points(mlx_image_t *img, t_point *a, t_point *b,
		int total_steps)
{
	t_point	current;
	float	slope;
	float	step;
	int		i;

	slope = (b->xyz[1] - a->xyz[1]) / (b->xyz[0] - a->xyz[0]);
	if (ft_abs_float(slope) <= 1)
	{
		current.xyz[0] = a->xyz[0];
		step = (b->xyz[0] - a->xyz[0]) / total_steps;
		i = 0;
		while (i < total_steps)
		{
			current.xyz[1] = a->xyz[1] + slope * (current.xyz[0] - a->xyz[0]);
			current.color = color_gradient(a->color, b->color,
					1.0 * i / total_steps);
			if (point_inside_img(img, current.xyz[0], current.xyz[1]))
				mlx_put_pixel(img, ft_round(current.xyz[0]),
					ft_round(current.xyz[1]), current.color);
			current.xyz[0] += step;
			i++;
		}
	}
	else
		draw_inverse_slope_line(img, a, b, total_steps);
}

void	connect_neighbours(mlx_image_t *img, t_coord_matrix *coord_matrix,
		int row, int col)
{
	int	total_steps;

	total_steps = STEPS_CONST / (coord_matrix->nrows * coord_matrix->ncols);
	if (row > 0)
		draw_line_between_points(img, &coord_matrix->m[row - 1][col],
			&coord_matrix->m[row][col], total_steps);
	if (col > 0)
		draw_line_between_points(img, &coord_matrix->m[row][col - 1],
			&coord_matrix->m[row][col], total_steps);
}
