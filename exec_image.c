/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:13 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/19 17:48:03 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
    // *(unsigned int*)dst = data->texture.data[y % data->texture.height * data->texture.width + (x % 64)];
}

void clear_screen(t_data *data)
{
	for (int x = 0; x < SCREEN_WIDTH; x++)
    {
		for (int y = 0; y < SCREEN_HEIGHT / 2; y++)
        {
            my_mlx_pixel_put(data, x, y, create_rgb(data->ceiling[0], data->ceiling[1],data->ceiling[2]));  // 0x000000은 검은색
        }
    }
	for (int x = 0; x < SCREEN_WIDTH; x++)
    {
		for (int y = SCREEN_HEIGHT / 2; y < SCREEN_HEIGHT; y++)
        {
            my_mlx_pixel_put(data, x, y, create_rgb(data->floor[0], data->floor[1],data->floor[2]));  // 0x000000은 검은색
        }
    }
}