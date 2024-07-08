/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:31:50 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/08 18:32:31 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

void	init_map_size(t_info *info, int fd, char *str)
{
	int	max_width;
	int	len;
	int	row;

	max_width = -1;
	row = 0;
	printf("str : %s\n", str);
	while (str)
	{
		if (ft_strlen(str) > 0)
		{
			len = check_only_six_util(str);
			printf("len : %d\n", len);
			if (len < 0)
				parsing_error(2);
			max_width = ft_max(max_width, len);
			row++;
		}
		free(str);
		str = get_next_line(fd);
	}
	printf("max_w : %d\n", max_width);
	printf("max_h : %d\n", row);
	info->map_w = max_width;
	info->map_h = row;
}

void	init_map(t_info *info, int row)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(info->file, O_RDONLY);
	if (fd < 0 || fd == 2 || read(fd, 0, 0) == -1)
		parsing_error(2);
	i = 0;
	str = get_next_line(fd);
	while (str && i < row)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	init_map_size(info, fd, str);
}
