/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:21:18 by jeakim            #+#    #+#             */
/*   Updated: 2024/07/08 13:12:34 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft_src/libft.h"
# include <stdio.h>

typedef	struct s_info
{
	char	*file;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	// char	F[3];
	char	*C;
	// char	C[3];
}	t_info;

//cub.c
void	parsing_error(int flag);
//parsing.c
void	parsing(int argc, char *argv[], t_info *info);

#endif