/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:14:32 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/24 20:07:22 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	init_ray(t_data *data, t_dda *d, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	d->ray_dir_x = data->dir_x + data->plane_x * camera_x;
	d->ray_dir_y = data->dir_y + data->plane_y * camera_x;
}

void	set_delta_dist(t_dda *d)
{
	if (d->ray_dir_x == 0)
		d->delta_dist_x = 1e30;
	else
		d->delta_dist_x = fabs(1 / d->ray_dir_x);
	if (d->ray_dir_y == 0)
		d->delta_dist_y = 1e30;
	else
		d->delta_dist_y = fabs(1 / d->ray_dir_y);
}

void	calculate_perp_wall_dist_texture_x(t_data *data, t_dda *d)
{
	double	wall_x;

	if (d->side == 0)
		d->perp_wall_dist = d->side_dist_x - d->delta_dist_x;
	else
		d->perp_wall_dist = d->side_dist_y - d->delta_dist_y;
	if (d->side == 0)
		wall_x = data->pos_y + d->perp_wall_dist * d->ray_dir_y;
	else
		wall_x = data->pos_x + d->perp_wall_dist * d->ray_dir_x;
	wall_x -= floor(wall_x);
	d->tex_x = (int)(wall_x * (double)(data->texture[0].width));
	if ((d->side == 0 && d->ray_dir_x > 0) || \
	(d->side == 1 && d->ray_dir_y < 0))
		d->tex_x = data->texture[0].width - d->tex_x - 1;
}

void	draw_texture(t_data *data, t_dda *d, int x, int y)
{
	double	step;
	double	tex_pos;
	int		color;
	int		start;
	int		end;

	d->line_height = (int)(SCREEN_HEIGHT / d->perp_wall_dist);
	start = (-d->line_height / 2 + SCREEN_HEIGHT / 2);
	end = d->line_height / 2 + SCREEN_HEIGHT / 2;
	if (start < 0)
		start = 0;
	if (end >= SCREEN_HEIGHT)
		end = SCREEN_HEIGHT - 1;
	step = 1.0 * data->texture[0].height / d->line_height;
	tex_pos = (start - SCREEN_HEIGHT / 2 + d->line_height / 2) * step;
	y = start - 1;
	while (++y < end)
	{
		d->tex_y = (int)tex_pos & (data->texture[d->wall].height - 1);
		tex_pos += step;
		color = data->texture[d->wall].data[data->texture[d->wall].height * \
		d->tex_y + d->tex_x];
		my_mlx_pixel_put(data, x, y, color);
	}
}

int	main_loop(t_data *data)
{
	t_dda	d;
	int		x;
	int		y;

	x = -1;
	y = 0;
	clear_screen(data);
	while (++x < SCREEN_WIDTH)
	{
		d.map_x = (int)data->pos_x;
		d.map_y = (int)data->pos_y;
		init_ray(data, &d, x);
		set_delta_dist(&d);
		init_dda(data, &d);
		perform_dda(data, &d);
		calculate_perp_wall_dist_texture_x(data, &d);
		draw_texture(data, &d, x, y);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
