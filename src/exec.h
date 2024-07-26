/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeakim <jeakim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:40:49 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/26 16:44:42 by jeakim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <math.h>
# include <stdlib.h>
# include "../minilibx_mms_20210621/mlx.h"
# include "cub.h"
# include "parsing.h"

# define TURN_LEFT 123
# define TURN_RIGHT 124
# define MOVE_FORWARD 13
# define MOVE_BACKWARD 1
# define MOVE_LEFT 0
# define MOVE_RIGHT 2
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
// # define MOVE_SPEED 0.05
// # define ROTATE 0.025
// # define SCREEN_WIDTH 1280
// # define SCREEN_HEIGHT 960
# define MOVE_SPEED 0.1
# define ROTATE 0.05

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		width;
	int		height;
	int		b;
	int		l;
	int		e;
}				t_img;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				b;
	int				l;
	int				e;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				move_forward;
	int				move_backward;
	int				move_left;
	int				move_right;
	int				rotate_left;
	int				rotate_right;
	char			**map;
	int				map_height;
	int				map_width;
	unsigned char	floor[3];
	unsigned char	ceiling[3];
	t_img			texture[4];
}	t_data;

typedef struct s_dda
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		wall;
	int		line_height;
	int		tex_x;
	int		tex_y;
}	t_dda;
//exec_dda
void		init_dda(t_data *data, t_dda *d);
void		perform_dda(t_data *data, t_dda *d);
//exec_direction
void		set_direction(t_data *data, t_info *info);
void		set_direction_n(t_data *data);
void		set_direction_s(t_data *data);
void		set_direction_w(t_data *data);
void		set_direction_e(t_data *data);
//exec_image
int			create_rgb(int r, int g, int b);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		clear_screen(t_data *data);
//exec_init
void		data_init(t_data *data, t_info *info);
void		textures_init(t_data *data, t_info *info);
//exec_key_handling
int			handle_exit(int num);
int			key_press(int keycode, t_data *data);
//exec_move
void		move(t_data *data);
void		move_vertical(t_data *data);
void		move_horizontal(t_data *data);
void		rotate(t_data *data);
//exec_raycast
void		init_ray(t_data *data, t_dda *d, int x);
void		calculate_wall(t_data *data, t_dda *d);
void		draw_wall(t_data *data, t_dda *d, int x, int y);
int			main_loop(t_data *data);
//exec
long long	cub_atoi(char str);

#endif