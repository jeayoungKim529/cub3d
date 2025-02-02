/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:21:18 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/26 14:37:01 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../libft_src/libft.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef enum e_true
{
	FALSE,
	TRUE
}	t_true;

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_direction;

typedef struct s_info
{
	size_t			map_w;
	size_t			map_h;
	char			**map;
	t_direction		direction;
	size_t			user_x;
	size_t			user_y;
	char			*file;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	unsigned char	f[3];
	unsigned char	c[3];
}	t_info;

//cub.c
void	parsing_error(int num);
//parsing.c
void	parsing(int argc, char *argv[], t_info *info);
//ft_free.c
void	ft_free(t_info *info);

#endif