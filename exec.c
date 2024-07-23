/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 20:52:10 by jimchoi           #+#    #+#             */
/*   Updated: 2024/07/23 21:47:23 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"



long long	cub_atoi(char str)
{
	long long	neg;
	long long	num;
	int			cnt;

	cnt = 0;
	num = 0;
	neg = 1;
	if (str == ' ')
		return (1);
	else if (!ft_isdigit(str))
		return (0);

		num =str - '0';
	if (cnt > 1)
		num = 0;
	return (num * neg);
}



// void move_player(t_data *data);
// int main_loop(t_data *data);
int	main_loop(t_data * data);

//픽셀 색상 지정




//플레이어 이동 및 회전
// void move_player(t_data *data)
// {
//     // double moveSpeed = 0.05;
//     double moveSpeed = 0.1;
//     double rotSpeed = 0.03;

// //전진
//     if (data->move_forward)
//     {
// 		//충돌 검사 후 이동
//         if (!cub_atoi(data->worldMap[(int)(data->posX + data->dirX * moveSpeed)][(int)(data->posY)]))
//             data->posX += data->dirX * moveSpeed;
//         if (!cub_atoi(data->worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * moveSpeed)]))
//             data->posY += data->dirY * moveSpeed;
//     }
// 	//후진
//     if (data->move_backward)
//     {
// 		//충돌 검사 후 이동
//         if (!cub_atoi(data->worldMap[(int)(data->posX - data->dirX * moveSpeed)][(int)(data->posY)]))
//             data->posX -= data->dirX * moveSpeed;
//         if (!cub_atoi(data->worldMap[(int)(data->posX)][(int)(data->posY - data->dirY * moveSpeed)]))
//             data->posY -= data->dirY * moveSpeed;
//     }
// // 왼쪽 이동
// 	if (data->move_left)
// 	{
// 		// 방향벡터 dir을 90도 회전시켜 측면 이동 벡터 생성

// 		double move_x = -data->dirY * moveSpeed;
// 		double move_y = data->dirX * moveSpeed;

// 		if(!cub_atoi(data->world_map[(int)(data->pos_x + move_x)][(int)(data->pos_y)]))
// 			data->posX += move_x;
// 		if(!cub_atoi(data->worldMap[(int)(data->posX)][(int)(data->posY + move_y)]))
// 			data->posY += move_y;
// 	}
// 	//오른쪽 이동
// 	if (data->move_right)
// 	{

// 		double move_x = data->dirY * moveSpeed;
// 		double move_y = -data->dirX * moveSpeed;

// 		if (!cub_atoi(data->worldMap[(int)(data->posX + move_x)][(int)(data->posY)]))
// 			data->posX += move_x;
// 		if (!cub_atoi(data->worldMap[(int)(data->posX)][(int)(data->posY + move_y)]))
// 			data->posY += move_y;
// 	}
// 	//오른쪽 회전
//     if (data->rotate_right)
//     {
// 		//방향 벡터와 카메라 평면 회전
//         double oldDirX = data->dirX;
//         data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
//         data->dirY = oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
//         double oldPlaneX = data->planeX;
//         data->planeX = data->planeX * cos(-rotSpeed) - data->planeY * sin(-rotSpeed);
//         data->planeY = oldPlaneX * sin(-rotSpeed) + data->planeY * cos(-rotSpeed);
//     }
// 	//왼쪽 회전
//     if (data->rotate_left)
//     {
// 		//방향 벡터와 카메라 평면 회전
//         double oldDirX = data->dirX;
//         data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
//         data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
//         double oldPlaneX = data->planeX;
//         data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
//         data->planeY = oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
//     }
// }


// //메인 렌더링 루프
// int main_loop(t_data *data)
// {
//     // move_player(data);
//     clear_screen(data);

// // 각 수직선에 대해 레이캐스팅 수행
//     for (int x = 0; x < SCREEN_WIDTH; x++)
//     {
//         double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; //x값(화면의 수직선)이 위치가 카메라평면에서 차지하는 x좌표 입니다
//         double rayDirX = data->dirX + data->planeX * cameraX; // 광광선의 방향벡터
//         double rayDirY = data->dirY + data->planeY * cameraX;
// 		//현재 맵 위치
//         int mapX = (int)data->posX;
//         int mapY = (int)data->posY;

//         double sideDistX, sideDistY; //현재 위치에서 다음 x 또는 y면까지의 광선 길이

// 		//DDA 알고리즘 변수 초기화
// 	//하나의 x 또는 y 면에서 다음 x 또는 y 면까지의 광선 길이
//         double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
//         double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
//         double perpWallDist;
// //x 또는 y 방향에서 어떤 방향으로 움직일지(+1 또는 -1)
//         int stepX, stepY;
//         int hit = 0;//was there a wall hit?
//         int side;//was a NS or a EW wall hit?

//         if (rayDirX < 0)
//         {
//             stepX = -1;
//             sideDistX = (data->posX - mapX) * deltaDistX;
//         }
//         else
//         {
//             stepX = 1;
//             sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
//         }
//         if (rayDirY < 0)
//         {
//             stepY = -1;
//             sideDistY = (data->posY - mapY) * deltaDistY;
//         }
//         else
//         {
//             stepY = 1;
//             sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
//         }

//         int wall;
//         while (hit == 0)
//         {
//             if (sideDistX < sideDistY)
//             {
//                 sideDistX += deltaDistX;
//                 mapX += stepX;
//                 side = 0;
//                 wall = 0;
//                 if (stepX > 0)
//                     wall = 1;
//             }
//             else
//             {
//                 sideDistY += deltaDistY;
//                 mapY += stepY;
//                 side = 1;
//                 wall = 2;
//                 if (stepY > 0)
//                     wall = 3;
//             }
//             if (cub_atoi(data->worldMap[mapX][mapY]) > 0) hit = 1;
//         }



// 		// 벽까지 거리 계산
//         if (side == 0) perpWallDist = (sideDistX - deltaDistX);
//         else           perpWallDist = (sideDistY - deltaDistY);


// 		//화면에 그릴 벽의 높이
//                // 벽 높이 계산 수정
//         int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

//         // 드로잉 범위 계산 수정
//         int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
//         if (drawStart < 0) drawStart = 0;
//         int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
//         if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

// 		// 벽 색상
//         // int color;
//         // if (wall == 0)
//         //     color = 0xFFFF00;
//         // else if (wall == 1)
//         //     color = 0xFFFFFF;
//         // else if (wall == 2)
//         //     color = 0x0000FF;
//         // else if (wall == 3)
//         //     color = 0xFF0000;

//        double wallX;
//         if (side == 0) wallX = data->posY + perpWallDist * rayDirY;
//         else           wallX = data->posX + perpWallDist * rayDirX;
//         wallX -= floor(wallX);

//         int texX = (int)(wallX * (double)data->texture[wall].width);
//         if (side == 0 && rayDirX > 0) texX = data->texture[wall].width - texX - 1;
//         if (side == 1 && rayDirY < 0) texX = data->texture[wall].width - texX - 1;

//          double step = 1.0 * data->texture[wall].height / lineHeight;
//         double texPos = (drawStart - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;

//         for (int y = drawStart; y < drawEnd; y++)
//         {
//             int texY = (int)texPos % ((data->texture[wall].height - 1));
//             texPos += step;
//             int color = data->texture[wall].data[data->texture[wall].height * texY + texX];

//             my_mlx_pixel_put(data, x, y, color);
//         }
//     }
//     mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//     return (0);
// }


// int main_loop(t_data *data)
// {
//     // move_player(data);
//     clear_screen(data);

//     // 각 수직선에 대해 레이캐스팅 수행
//     for (int x = 0; x < SCREEN_WIDTH; x++)
//     {
//         double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; // x값(화면의 수직선)이 위치가 카메라 평면에서 차지하는 x좌표
//         double rayDirX = data->dir_x + data->plane_x * cameraX; // 광선의 방향 벡터
//         double rayDirY = data->dir_y + data->plane_y * cameraX;
        
//         // 현재 맵 위치
//         int mapX = (int)data->pos_x;
//         int mapY = (int)data->pos_y;

//         double sideDistX, sideDistY; // 현재 위치에서 다음 x 또는 y면까지의 광선 길이

//         // DDA 알고리즘 변수 초기화
//         // 하나의 x 또는 y 면에서 다음 x 또는 y 면까지의 광선 길이
//         double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
//         double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
//         double perpWallDist;

//         // x 또는 y 방향에서 어떤 방향으로 움직일지(+1 또는 -1)
//         int stepX, stepY;
//         int hit = 0; // was there a wall hit?
//         int side; // was a NS or a EW wall hit?

//         if (rayDirX < 0)
//         {
//             stepX = -1;
//             sideDistX = (data->pos_x - mapX) * deltaDistX;
//         }
//         else
//         {
//             stepX = 1;
//             sideDistX = (mapX + 1.0 - data->pos_x) * deltaDistX;
//         }
//         if (rayDirY < 0)
//         {
//             stepY = -1;
//             sideDistY = (data->pos_y - mapY) * deltaDistY;
//         }
//         else
//         {
//             stepY = 1;
//             sideDistY = (mapY + 1.0 - data->pos_y) * deltaDistY;
//         }

//         int wall;
//         while (hit == 0)
//         {
//             if (sideDistX < sideDistY)
//             {
//                 sideDistX += deltaDistX;
//                 mapX += stepX;
//                 side = 0;
//                 wall = 0;
//                 if (stepX > 0)
//                     wall = 1;
//             }
//             else
//             {
//                 sideDistY += deltaDistY;
//                 mapY += stepY;
//                 side = 1;
//                 wall = 2;
//                 if (stepY > 0)
//                     wall = 3;
//             }
//             if (cub_atoi(data->world_map[mapX][mapY]) > 0)
//                 hit = 1;
//         }

//         // 벽까지 거리 계산
//         if (side == 0)
//             perpWallDist = (sideDistX - deltaDistX);
//         else
//             perpWallDist = (sideDistY - deltaDistY);

//         // 화면에 그릴 벽의 높이
//         int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

//         // 드로잉 범위 계산
//         int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
//         if (drawStart < 0)
//             drawStart = 0;
//         int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
//         if (drawEnd >= SCREEN_HEIGHT)
//             drawEnd = SCREEN_HEIGHT - 1;

//         // 벽 텍스처 좌표 계산
//         double wallX;
//         if (side == 0)
//             wallX = data->pos_y + perpWallDist * rayDirY;
//         else
//             wallX = data->pos_x + perpWallDist * rayDirX;
//         wallX -= floor(wallX);

//         int texX = (int)(wallX * (double)data->texture[wall].width);
//         if (side == 0 && rayDirX > 0)
//             texX = data->texture[wall].width - texX - 1;
//         if (side == 1 && rayDirY < 0)
//             texX = data->texture[wall].width - texX - 1;

//         double step = 1.0 * data->texture[wall].height / lineHeight;
//         double texPos = (drawStart - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;

//         for (int y = drawStart; y < drawEnd; y++)
//         {
//             int texY = (int)texPos % (data->texture[wall].height - 1);
//             texPos += step;
//             int color = data->texture[wall].data[data->texture[wall].height * texY + texX];

//             my_mlx_pixel_put(data, x, y, color);
//         }
//     }
//     mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
//     return (0);
// }





int main_loop1(t_data *data);

int	map(t_info	info)
{
	t_data data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	data.img = mlx_new_image(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	set_direction(&data, &info);
	data_init(&data, &info);
	textures_init(&data, &info);
	mlx_loop_hook(data.mlx, main_loop1, &data);
	mlx_hook(data.win, 2, 1L<<0, key_press, &data);
	mlx_hook(data.win, 3, 1L<<1, key_release, &data);
	mlx_hook(data.win, 17, 0, &handle_exit, 0);
	mlx_loop(data.mlx);
	return (0);
}
