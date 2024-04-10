/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key_rotations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:25:02 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/10 23:25:46 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_rot_1(t_state *state)
{
	t_point	center;

	change_to_body_coord_system(state->coord_matrix, &center);
	perform_rotation(state->coord_matrix, ROT_UNIT, 0, 0);
	change_back_coord_system(state->coord_matrix, &center);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}

void	manage_rot_1_rev(t_state *state)
{
	t_point	center;

	change_to_body_coord_system(state->coord_matrix, &center);
	perform_rotation(state->coord_matrix, -ROT_UNIT, 0, 0);
	change_back_coord_system(state->coord_matrix, &center);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}

void	manage_rot_2(t_state *state)
{
	t_point	center;

	change_to_body_coord_system(state->coord_matrix, &center);
	perform_rotation(state->coord_matrix, 0, ROT_UNIT, 0);
	change_back_coord_system(state->coord_matrix, &center);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}

void	manage_rot_2_rev(t_state *state)
{
	t_point	center;

	change_to_body_coord_system(state->coord_matrix, &center);
	perform_rotation(state->coord_matrix, 0, -ROT_UNIT, 0);
	change_back_coord_system(state->coord_matrix, &center);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}
