/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:21:56 by jorvarea          #+#    #+#             */
/*   Updated: 2024/03/27 18:12:15 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	background_image(mlx_t *mlx)
{
	unsigned int	x;
	unsigned int	y;
	mlx_image_t		*img;

	img = mlx_new_image(mlx, mlx->width, mlx->height);
	check_mlx_image_error(img);
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			mlx_put_pixel(img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	check_mlx_image_to_window_error(mlx, img, 0, 0);
}
