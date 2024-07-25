/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:06 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/24 20:26:27 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	move_vertical(t_data *data)
{
	double	dx;
	double	dy;

	dx = data->dir_x * MOVE_SPEED;
	dy = data->dir_y * MOVE_SPEED;
	if (data->move_forward)
	{
		if (!cub_atoi(data->map[(int)(data->pos_x + dx)][(int)data->pos_y]))
			data->pos_x += dx;
		if (!cub_atoi(data->map[(int)data->pos_x][(int)(data->pos_y + dy)]))
			data->pos_y += dy;
		data->move_forward = 0;
	}
	if (data->move_backward)
	{
		if (!cub_atoi(data->map[(int)(data->pos_x - dx)][(int)data->pos_y]))
			data->pos_x -= dx;
		if (!cub_atoi(data->map[(int)data->pos_x][(int)(data->pos_y - dy)]))
			data->pos_y -= dy;
		data->move_backward = 0;
	}
}

void	move_horizontal(t_data *data)
{
	double	move_x;
	double	move_y;

	if (data->move_left)
	{
		move_x = -data->dir_y * MOVE_SPEED;
		move_y = data->dir_x * MOVE_SPEED;
		if (!cub_atoi(data->map[(int)(data->pos_x + move_x)][(int)data->pos_y]))
			data->pos_x += move_x;
		if (!cub_atoi(data->map[(int)data->pos_x][(int)(data->pos_y + move_y)]))
			data->pos_y += move_y;
		data->move_left = 0;
	}
	if (data->move_right)
	{
			move_x = data->dir_y * MOVE_SPEED;
		move_y = -data->dir_x * MOVE_SPEED;
		if (!cub_atoi(data->map[(int)(data->pos_x + move_x)][(int)data->pos_y]))
			data->pos_x += move_x;
		if (!cub_atoi(data->map[(int)data->pos_x][(int)(data->pos_y + move_y)]))
			data->pos_y += move_y;
		data->move_right = 0;
	}
}

void	rotate(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	if (data->rotate_right)
	{
		data->dir_x = data->dir_x * cos(-ROTATE) - data->dir_y * sin(-ROTATE);
		data->dir_y = old_dir_x * sin(-ROTATE) + data->dir_y * cos(-ROTATE);
		data->plane_x = data->plane_x * cos(-ROTATE) - \
		data->plane_y * sin(-ROTATE);
		data->plane_y = old_plane_x * sin(-ROTATE) + \
		data->plane_y * cos(-ROTATE);
		data->rotate_right = 0;
	}
	if (data->rotate_left)
	{
		data->dir_x = data->dir_x * cos(ROTATE) - data->dir_y * sin(ROTATE);
		data->dir_y = old_dir_x * sin(ROTATE) + data->dir_y * cos(ROTATE);
		data->plane_x = data->plane_x * cos(ROTATE) - \
		data->plane_y * sin(ROTATE);
		data->plane_y = old_plane_x * sin(ROTATE) + data->plane_y * cos(ROTATE);
		data->rotate_left = 0;
	}
}

void	move(t_data *data)
{
	if (data->move_forward || data->move_backward)
		move_vertical(data);
	if (data->move_left || data->move_right)
		move_horizontal(data);
	if (data->rotate_left || data->rotate_right)
		rotate(data);
}
