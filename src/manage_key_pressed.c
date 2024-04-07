/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:47:08 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/07 20:03:52 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_key_pressed(void *ptr)
{
	t_state	*state;

	state = (t_state *)ptr;
	if (mlx_is_key_down(state->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(state->mlx);
	// if (mlx_is_key_down(param->mlx, MLX_KEY_P))
	// {
	// 	if (param->zoom < ZOOM_LIMIT)
	// 		param->zoom += ZOOM_UNIT;
	// 	mlx_delete_image(param->mlx, param->current_img);
	// 	param->current_img = top_view(param->mlx, param->map, param->zoom);
	// }
	// else if (mlx_is_key_down(param->mlx, MLX_KEY_O))
	// {
	// 	if (param->zoom > 2 * ZOOM_UNIT)
	// 		param->zoom -= ZOOM_UNIT;
	// 	mlx_delete_image(param->mlx, param->current_img);
	// 	param->current_img = top_view(param->mlx, param->map, param->zoom);
	// }
}
