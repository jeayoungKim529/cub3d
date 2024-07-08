/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:21:18 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/08 19:05:37 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft_src/libft.h"
# include <stdio.h>

typedef struct s_info
{
	size_t			map_w;
	size_t			map_h;
	char			**map;
	char			*file;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	unsigned char	f[3];
	unsigned char	c[3];
}	t_info;

//cub.c
void	parsing_error(int flag);
//parsing.c
void	parsing(int argc, char *argv[], t_info *info);

#endif