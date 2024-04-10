/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 01:24:40 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/11 01:24:53 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_reset(t_state *state)
{
	calculate_coord_matrix(state->mlx, state->map, state->coord_matrix);
	perform_rotation(state->coord_matrix, atan(sqrt(2)), 0, M_PI / 4);
	mlx_delete_image(state->mlx, state->img);
	state->img = centered_image(state->mlx, state->coord_matrix);
}
