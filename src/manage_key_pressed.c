/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:47:08 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/07 21:03:45 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_key_pressed(void *ptr)
{
	t_state	*state;

	state = (t_state *)ptr;
	if (mlx_is_key_down(state->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(state->mlx);
	else if (mlx_is_key_down(state->mlx, MLX_KEY_UP))
	{
		if (state->translated_y < WINDOW_HEIGHT / 2)
		{
			perform_translation(state->coord_matrix, 0, TRANS_UNIT);
			mlx_delete_image(state->mlx, state->img);
			state->img = redraw_image(state->mlx, state->coord_matrix);
			state->translated_y += TRANS_UNIT;
		}
	}
	else if (mlx_is_key_down(state->mlx, MLX_KEY_DOWN))
	{
		if (state->translated_y > -WINDOW_HEIGHT / 2)
		{
			perform_translation(state->coord_matrix, 0, -TRANS_UNIT);
			mlx_delete_image(state->mlx, state->img);
			state->img = redraw_image(state->mlx, state->coord_matrix);
			state->translated_y += -TRANS_UNIT;
		}
	}
	else if (mlx_is_key_down(state->mlx, MLX_KEY_LEFT))
	{
		if (state->translated_x < WINDOW_WIDTH / 2)
		{
			perform_translation(state->coord_matrix, TRANS_UNIT, 0);
			mlx_delete_image(state->mlx, state->img);
			state->img = redraw_image(state->mlx, state->coord_matrix);
			state->translated_x += TRANS_UNIT;
		}
	}
	else if (mlx_is_key_down(state->mlx, MLX_KEY_RIGHT))
	{
		if (state->translated_x > -WINDOW_WIDTH / 2)
		{
			perform_translation(state->coord_matrix, -TRANS_UNIT, 0);
			mlx_delete_image(state->mlx, state->img);
			state->img = redraw_image(state->mlx, state->coord_matrix);
			state->translated_x += -TRANS_UNIT;
		}
	}
	// if (mlx_is_key_down(state->mlx, MLX_KEY_P))
	// {
	// 	if (state->zoom < ZOOM_LIMIT)
	//  		state->zoom += ZOOM_UNIT;
	//  	mlx_delete_image(state->mlx, state->img);
	//  	state->img = top_view(state);
	// }
	// else if (mlx_is_key_down(state->mlx, MLX_KEY_O))
	// {
	// 	if (state->zoom > 2 * ZOOM_UNIT)
	//  		state->zoom -= ZOOM_UNIT;
	// 	mlx_delete_image(state->mlx, state->img);
	//  state->img = top_view(state);
	// }
}
