/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_system.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:37:39 by jorvarea          #+#    #+#             */
/*   Updated: 2024/04/10 23:17:31 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void change_to_body_coord_system(t_coord_matrix *coord_matrix, t_point *center)
{
    int i;
    int j;
    
    center->xyz[0] = coord_matrix->m[coord_matrix->nrows / 2][coord_matrix->ncols / 2].xyz[0];
    center->xyz[1] = coord_matrix->m[coord_matrix->nrows / 2][coord_matrix->ncols / 2].xyz[1];
    center->xyz[2] = coord_matrix->m[coord_matrix->nrows / 2][coord_matrix->ncols / 2].xyz[2];
    i = 0;
    while (i < coord_matrix->nrows)
    {
        j = 0;
        while (j < coord_matrix->ncols)
        {
            coord_matrix->m[i][j].xyz[0] -= center->xyz[0];
            coord_matrix->m[i][j].xyz[1] -= center->xyz[1];
            coord_matrix->m[i][j].xyz[2] -= center->xyz[2];
            j++;
        }
        i++;
    }
}

void change_back_coord_system(t_coord_matrix *coord_matrix, t_point *center)
{
    int i;
    int j;

    i = 0;
    while (i < coord_matrix->nrows)
    {
        j = 0;
        while (j < coord_matrix->ncols)
        {
            coord_matrix->m[i][j].xyz[0] += center->xyz[0];
            coord_matrix->m[i][j].xyz[1] += center->xyz[1];
            coord_matrix->m[i][j].xyz[2] += center->xyz[2];
            j++;
        }
        i++;
    }
}
