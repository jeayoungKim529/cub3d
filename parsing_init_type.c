/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:59:45 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/10 11:15:33 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "parsing.h"

long long	ft_atoi_type(const char *str)
{
	long long	neg;
	long long	num;
	int			cnt;

	cnt = 0;
	num = 0;
	neg = 1;
	while (*str == '\n' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		cnt++;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	if (cnt > 1)
		num = 0;
	return (num * neg);
}

void	init_fc(t_info *info, char *s, int flag)
{
	char	**tmp;
	int		i;

	tmp = ft_split(s, ',');
	i = 0;
	while (tmp[i])
		i++;
	if (i != 3)
		parsing_error(2);
	if (flag == 0)
	{
		i = -1;
		while (++i < 3)
			info->f[i] = ft_atoi(tmp[i]);
	}
	if (flag == 1)
	{
		i = -1;
		while (++i < 3)
			info->c[i] = ft_atoi_type(tmp[i]);
	}
	i = -1;
	while (++i < 3)
		free(tmp[i]);
}

int	init_six(t_info *info, char *str, int i)
{
	char	**tmp;

	tmp = ft_split(str, ' ');
	while (tmp[i])
		i++;
	if (ft_strncmp(tmp[0], "NO", 3) == 0)
		info->no = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "SO", 3) == 0)
		info->so = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "WE", 3) == 0)
		info->we = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "EA", 3) == 0)
		info->ea = ft_strdup(tmp[1]);
	else if (ft_strncmp(tmp[0], "F", 2) == 0)
		init_fc(info, str, 0);
	else if (ft_strncmp(tmp[0], "C", 2) == 0)
		init_fc(info, str, 1);
	else
		return (0);
	while (--i >= 0)
		free(tmp[i]);
	free(tmp);
	return (1);
}

int	init_type(t_info *info)
{
	char	*str;
	int		fd;
	int		num;
	int		row;

	fd = open(info->file, O_RDONLY);
	if (fd < 0 || fd == 2 || read(fd, 0, 0) == -1)
		parsing_error(1);
	num = 0;
	row = 0;
	str = get_next_line(fd);
	while (str && num < 6)
	{
		if (ft_strlen(str) > 0)
		{
			num += init_six(info, str, 0);
		}
		row++;
		free(str);
		str = get_next_line(fd);
	}
	if (num != 6)
		parsing_error(1);
	close(fd);
	return (row + 1);
}
