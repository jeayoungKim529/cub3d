/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:13 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/24 19:18:40 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clear_screen(t_data *data)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	color = create_rgb(data->ceiling[0], data->ceiling[1], data->ceiling[2]);
	while (++x < SCREEN_WIDTH)
	{
		y = -1;
		while (++y < SCREEN_HEIGHT)
			my_mlx_pixel_put(data, x, y, color);
	}
	x = -1;
	color = create_rgb(data->floor[0], data->floor[1], data->floor[2]);
	while (++x < SCREEN_WIDTH)
	{
		y = (SCREEN_WIDTH / 2) - 1;
		while (++y < SCREEN_HEIGHT)
			my_mlx_pixel_put(data, x, y, color);
	}
}
