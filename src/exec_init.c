/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:09:23 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/26 13:08:06 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	data_init(t_data *data, t_info *info)
{
	data->move_forward = 0;
	data->move_backward = 0;
	data->move_left = 0;
	data->move_right = 0;
	data->rotate_left = 0;
	data->rotate_right = 0;
	data->map_height = info->map_h;
	data->map_width = info->map_w;
	data->floor[0] = info->f[0];
	data->floor[1] = info->f[1];
	data->floor[2] = info->f[2];
	data->ceiling[0] = info->c[0];
	data->ceiling[1] = info->c[1];
	data->ceiling[2] = info->c[2];
}

void	textures_init(t_data *data, t_info *info)
{
	data->texture[0].ptr = mlx_xpm_file_to_image(data->mlx, info->no, \
	&data->texture[0].width, &(data->texture[0].height));
	data->texture[0].data = (int *)mlx_get_data_addr(data->texture[0].ptr, \
	&data->texture[0].b, &data->texture[0].l, &data->texture[0].e);
	data->texture[1].ptr = mlx_xpm_file_to_image(data->mlx, info->so, \
	&data->texture[1].width, &(data->texture[1].height));
	data->texture[1].data = (int *)mlx_get_data_addr(data->texture[1].ptr, \
	&data->texture[1].b, &data->texture[1].l, &data->texture[1].e);
	data->texture[2].ptr = mlx_xpm_file_to_image(data->mlx, info->ea, \
	&data->texture[2].width, &(data->texture[2].height));
	data->texture[2].data = (int *)mlx_get_data_addr(data->texture[2].ptr, \
	&data->texture[2].b, &data->texture[2].l, &data->texture[2].e);
	data->texture[3].ptr = mlx_xpm_file_to_image(data->mlx, info->we, \
	&data->texture[3].width, &(data->texture[3].height));
	data->texture[3].data = (int *)mlx_get_data_addr(data->texture[3].ptr, \
	&data->texture[3].b, &data->texture[3].l, &data->texture[3].e);
}
