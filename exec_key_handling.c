/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_key_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:10 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/26 13:18:55 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	handle_exit(int num)
{
	(void)num;
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == MOVE_FORWARD)
		data->move_forward = 1;
	else if (keycode == MOVE_BACKWARD)
		data->move_backward = 1;
	else if (keycode == MOVE_LEFT)
		data->move_left = 1;
	else if (keycode == MOVE_RIGHT)
		data->move_right = 1;
	else if (keycode == TURN_LEFT)
		data->rotate_left = 1;
	else if (keycode == TURN_RIGHT)
		data->rotate_right = 1;
	else if (keycode == 53)
		exit(0);
	clear_screen(data);
	move(data);
	return (0);
}
