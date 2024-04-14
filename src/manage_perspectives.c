/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_perspectives.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:49:48 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/14 20:04:24 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_top_view(t_state *state)
{
	calculate_coord_matrix(state->mlx, state->map, state->coord_matrix);
	mlx_delete_image(state->mlx, state->img);
	state->img = centered_image(state->mlx, state->coord_matrix);
}

void	manage_elevation(t_state *state)
{
	calculate_coord_matrix(state->mlx, state->map, state->coord_matrix);
	perform_rotation(state->coord_matrix, M_PI / 2, 0, 0);
	mlx_delete_image(state->mlx, state->img);
	state->img = centered_image(state->mlx, state->coord_matrix);
}

void	manage_profile1(t_state *state)
{
	calculate_coord_matrix(state->mlx, state->map, state->coord_matrix);
	perform_rotation(state->coord_matrix, M_PI / 2, 0, -M_PI / 2);
	mlx_delete_image(state->mlx, state->img);
	state->img = centered_image(state->mlx, state->coord_matrix);
}

void	manage_profile2(t_state *state)
{
	calculate_coord_matrix(state->mlx, state->map, state->coord_matrix);
	perform_rotation(state->coord_matrix, M_PI / 2, 0, M_PI / 2);
	mlx_delete_image(state->mlx, state->img);
	state->img = centered_image(state->mlx, state->coord_matrix);
}
