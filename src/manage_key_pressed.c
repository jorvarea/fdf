/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key_pressed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:47:08 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/11 01:24:51 by jorvarea         ###   ########.fr       */
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
		manage_key_up(state);
	else if (mlx_is_key_down(state->mlx, MLX_KEY_DOWN))
		manage_key_down(state);
	else if (mlx_is_key_down(state->mlx, MLX_KEY_LEFT))
		manage_key_left(state);
	else if (mlx_is_key_down(state->mlx, MLX_KEY_RIGHT))
		manage_key_right(state);
	else if (mlx_is_key_down(state->mlx, MLX_KEY_Z))
		manage_rot_1(state);
	else if (mlx_is_key_down(state->mlx, MLX_KEY_A))
		manage_rot_1_rev(state);
	else if (mlx_is_key_down(state->mlx, MLX_KEY_X))
		manage_rot_2(state);
	else if (mlx_is_key_down(state->mlx, MLX_KEY_S))
		manage_rot_2_rev(state);
	else if (mlx_is_key_down(state->mlx, MLX_KEY_C))
		manage_rot_3(state);
	else if (mlx_is_key_down(state->mlx, MLX_KEY_D))
		manage_rot_3_rev(state);
	else if (mlx_is_key_down(state->mlx, MLX_KEY_R))
		manage_reset(state);
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
