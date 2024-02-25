/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:24:00 by jorvarea          #+#    #+#             */
/*   Updated: 2024/02/25 00:24:29 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void check_extension_error(char *filename)
{
    char *extension;
    int i;

    i = 0;
    extension = NULL;
    while(filename[i] != '\0')
    {
        if (filename[i] == '.')
            extension = &filename[i + 1];
        i++;
    }
    if (extension == NULL || ft_strncmp(extension, "fdf", 3) != 0)
    {
        ft_printf("Error: Invalid file extension\n");
        exit(1);
    }
}

void check_open_error(int fd)
{
    if (fd == -1)
    {
        ft_printf("Error: Couldn't open file\n");
        exit(1);
    }
}

void check_memory_allocation_error(void *ptr)
{
    if (ptr == NULL)
    {
        ft_printf("Error: Memory allocation failed\n");
        exit(1);
    }
}
