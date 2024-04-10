/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key_rotations2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:26:00 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/10 23:26:08 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void manage_rot_3(t_state *state)
{
	t_point center;
	
	change_to_body_coord_system(state->coord_matrix, &center);
	perform_rotation(state->coord_matrix, 0, 0, ROT_UNIT);
	change_back_coord_system(state->coord_matrix, &center);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}

void manage_rot_3_rev(t_state *state)
{
	t_point center;
	
	change_to_body_coord_system(state->coord_matrix, &center);
	perform_rotation(state->coord_matrix, 0, 0, -ROT_UNIT);
	change_back_coord_system(state->coord_matrix, &center);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}
