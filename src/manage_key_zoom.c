/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key_zoom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:51:47 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/13 21:52:04 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	manage_zoom_in(t_state *state)
{
	t_point	focus;

	focus.xyz[0] = 0;
	focus.xyz[1] = 0;
	perform_zoom(state->coord_matrix, ZOOM_FACTOR, &focus);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}

void	manage_zoom_out(t_state *state)
{
	t_point	focus;

	focus.xyz[0] = 0;
	focus.xyz[1] = 0;
	perform_zoom(state->coord_matrix, 1.0 / ZOOM_FACTOR, &focus);
	mlx_delete_image(state->mlx, state->img);
	state->img = redraw_image(state->mlx, state->coord_matrix);
}
