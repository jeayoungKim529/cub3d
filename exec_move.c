/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:06 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/22 11:29:16 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	move(t_data *data)
{
	if (data->move_forward || data->move_backward)
		move_vertical(data);
	if (data->move_left || data->move_right)
		move_horizontal(data);
	if (data->rotate_left || data->rotate_right)
		rotate(data);
}

void	move_vertical(t_data *data)
{
	if (!cub_atoi(data->world_map[(int)(data->pos_x + data->dir_x * MOVE_SPEED)][(int)data->pos_y]))
		data->pos_x += data->dir_x * MOVE_SPEED;
	if (!cub_atoi(data->world_map[(int)data->pos_x][(int)(data->pos_y + data->dir_y * MOVE_SPEED)]))
		data->pos_y += data->dir_y * MOVE_SPEED;

	if (!cub_atoi(data->world_map[(int)(data->pos_x - data->dir_x * MOVE_SPEED)][(int)data->pos_y]))
		data->pos_x -= data->dir_x * MOVE_SPEED;
	if (!cub_atoi(data->world_map[(int)data->pos_x][(int)(data->pos_y - data->dir_y * MOVE_SPEED)]))
		data->pos_y -= data->dir_y * MOVE_SPEED;
}

void	move_horizontal(t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = -data->dir_y * MOVE_SPEED;
	move_y = data->dir_x * MOVE_SPEED;
	if (!cub_atoi(data->world_map[(int)(data->pos_x + move_x)][(int)data->pos_y]))
		data->pos_x += move_x;
	if (!cub_atoi(data->world_map[(int)data->pos_x][(int)(data->pos_y + move_y)]))
		data->pos_y += move_y;

		move_x = data->dir_y * MOVE_SPEED;
	move_y = -data->dir_x * MOVE_SPEED;
	if (!cub_atoi(data->world_map[(int)(data->pos_x + move_x)][(int)data->pos_y]))
		data->pos_x += move_x;
	if (!cub_atoi(data->world_map[(int)data->pos_x][(int)(data->pos_y + move_y)]))
		data->pos_y += move_y;
}

void rotate(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	old_plane_x = data->plane_x;
	if (data->rotate_left)
	{
		data->dir_x = data->dir_x * cos(-ROTATE_SPEED) - data->dir_y * sin(-ROTATE_SPEED);
		data->dir_y = old_dir_x * sin(-ROTATE_SPEED) + data->dir_y * cos(-ROTATE_SPEED);
		data->plane_x = data->plane_x * cos(-ROTATE_SPEED) - data->plane_y * sin(-ROTATE_SPEED);
		data->plane_y = old_plane_x * sin(-ROTATE_SPEED) + data->plane_y * cos(-ROTATE_SPEED);
	}
	if (data->rotate_left)
	{
		data->dir_x = data->dir_x * cos(ROTATE_SPEED) - data->dir_y * sin(ROTATE_SPEED);
		data->dir_y = old_dir_x * sin(ROTATE_SPEED) + data->dir_y * cos(ROTATE_SPEED);
		data->plane_x = data->plane_x * cos(ROTATE_SPEED) - data->plane_y * sin(ROTATE_SPEED);
		data->plane_y = old_plane_x * sin(ROTATE_SPEED) + data->plane_y * cos(ROTATE_SPEED);
	}
}

