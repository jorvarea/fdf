/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projecttion_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:10:17 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/07 20:10:26 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

mlx_image_t	*projection_2d(mlx_t *mlx, t_coord_matrix *coord_matrix)
{
	int			i;
	int			j;
	mlx_image_t	*img;

	img = mlx_new_image(mlx, mlx->width, mlx->height);
	check_mlx_image_error(img);
	introduce_offset(img, coord_matrix);
	i = 0;
	while (i < coord_matrix->nrows)
	{
		j = 0;
		while (j < coord_matrix->ncols)
		{
			connect_neighbours(img, coord_matrix, i, j);
			j++;
		}
		i++;
	}
	check_mlx_image_to_window_error(mlx, img, 0, 0);
	return (img);
}
