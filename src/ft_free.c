/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:35:11 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/26 14:39:06 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_free_map(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->map_h)
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
}

void	ft_free(t_info *info)
{
	ft_free_map(info);
	free(info->file);
	free(info->no);
	free(info->so);
	free(info->we);
	free(info->ea);
}
