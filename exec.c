#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>
# include "./minilibx_mms_20210621/mlx.h"

#include "cub.h"
#include "parsing.h"


//화면 크기와 맵 크기 정의
#define screenWidth 640
#define screenHeight 480
#define TURN_LEFT 123
#define TURN_RIGHT 124
#define MOVE_FORWARD 13
#define MOVE_BACKWARD 1
#define MOVE_LEFT 0
#define MOVE_RIGHT 2
// #define mapWidth 24
// #define mapHeight 24

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

		num =str - '0';
	if (cnt > 1)
		num = 0;
	return (num * neg);
}

typedef struct {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    int move_forward;
    int move_backward;
    int rotate_left;
    int rotate_right;
	char **worldMap;
	int mapHeight;
	int mapWidth;
} t_data;


void move_player(t_data *data);
int main_loop(t_data *data);

//픽셀 색상 지정
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

//화면을 검정색으로
void clear_screen(t_data *data)
{
    for (int y = 0; y < screenHeight; y++)
    {
        for (int x = 0; x < screenWidth; x++)
        {
            my_mlx_pixel_put(data, x, y, 0x000000);  // 0x000000은 검은색
        }
    }
}
//키 이벤트 처리
int key_press(int keycode, t_data *data)
{
    if (keycode == MOVE_FORWARD) data->move_forward = 1;
    if (keycode == MOVE_BACKWARD)  data->move_backward = 1;
    if (keycode == TURN_LEFT)  data->rotate_left = 1;
    if (keycode == TURN_RIGHT)  data->rotate_right = 1;
    if (keycode == 53) exit(0);

    move_player(data);

    clear_screen(data);

    return (0);
}
// 키 누름 해제 이벤트 처리
int key_release(int keycode, t_data *data)
{
    if (keycode == MOVE_FORWARD) data->move_forward = 0;
    if (keycode == MOVE_BACKWARD)  data->move_backward = 0;
    if (keycode == TURN_LEFT)  data->rotate_left = 0;
    if (keycode == TURN_RIGHT)  data->rotate_right = 0;

    main_loop(data);

    return (0);
}
//플레이어 이동 및 회전
void move_player(t_data *data)
{
    // double moveSpeed = 0.05;
    double moveSpeed = 0.1;
    double rotSpeed = 0.03;

//전진
    if (data->move_forward)
    {
		//충돌 검사 후 이동
        if (!cub_atoi(data->worldMap[(int)(data->posX + data->dirX * moveSpeed)][(int)(data->posY)]))
            data->posX += data->dirX * moveSpeed;
        if (!cub_atoi(data->worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * moveSpeed)]))
            data->posY += data->dirY * moveSpeed;
    }
	//후진
    if (data->move_backward)
    {
		//충돌 검사 후 이동
        if (!cub_atoi(data->worldMap[(int)(data->posX - data->dirX * moveSpeed)][(int)(data->posY)]))
            data->posX -= data->dirX * moveSpeed;
        if (!cub_atoi(data->worldMap[(int)(data->posX)][(int)(data->posY - data->dirY * moveSpeed)]))
            data->posY -= data->dirY * moveSpeed;
    }
	//오른쪽 회전
    if (data->rotate_right)
    {
		//방향 벡터와 카메라 평면 회전
        double oldDirX = data->dirX;
        data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
        data->dirY = oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
        double oldPlaneX = data->planeX;
        data->planeX = data->planeX * cos(-rotSpeed) - data->planeY * sin(-rotSpeed);
        data->planeY = oldPlaneX * sin(-rotSpeed) + data->planeY * cos(-rotSpeed);
    }
	//왼쪽 회전
    if (data->rotate_left)
    {
		//방향 벡터와 카메라 평면 회전
        double oldDirX = data->dirX;
        data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
        data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
        double oldPlaneX = data->planeX;
        data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
        data->planeY = oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
    }
}


//메인 렌더링 루프
int main_loop(t_data *data)
{
    // move_player(data);
    clear_screen(data);

// 각 수직선에 대해 레이캐스팅 수행
    for (int x = 0; x < screenWidth; x++)
    {
        double cameraX = 2 * x / (double)screenWidth - 1; //x값(화면의 수직선)이 위치가 카메라평면에서 차지하는 x좌표 입니다
        double rayDirX = data->dirX + data->planeX * cameraX; // 광광선의 방향벡터
        double rayDirY = data->dirY + data->planeY * cameraX;
		//현재 맵 위치
        int mapX = (int)data->posX;
        int mapY = (int)data->posY;

        double sideDistX, sideDistY; //현재 위치에서 다음 x 또는 y면까지의 광선 길이

		//DDA 알고리즘 변수 초기화
	//하나의 x 또는 y 면에서 다음 x 또는 y 면까지의 광선 길이
        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;
//x 또는 y 방향에서 어떤 방향으로 움직일지(+1 또는 -1)
        int stepX, stepY;
        int hit = 0;//was there a wall hit?
        int side;//was a NS or a EW wall hit?

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (data->posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (data->posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
        }

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (cub_atoi(data->worldMap[mapX][mapY]) > 0) hit = 1;
        }



		// 벽까지 거리 계산
        if (side == 0) perpWallDist = (sideDistX - deltaDistX);
        else           perpWallDist = (sideDistY - deltaDistY);


		//화면에 그릴 벽의 높이
        int lineHeight = (int)(screenHeight / perpWallDist);

        int drawStart = -lineHeight / 2 + screenHeight / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

		// 벽 색상
        int color;
        // switch(cub_atoi(data->worldMap[mapX][mapY]))
        // {
        //     case 1:  color = 0xFF0000;  break;
        //     case 2:  color = 0x00FF00;  break;
        //     case 3:  color = 0x0000FF;  break;
        //     case 4:  color = 0xFFFFFF;  break;
        //     default: color = 0xFFFF00;  break;
        // }
		color = 0xFFFF00;
		// 벽면 음영 처리
        if (side == 1) color = color / 2;
		// 수직선 그리기
        for (int y = drawStart; y < drawEnd; y++)
            my_mlx_pixel_put(data, x, y, color);
    }

	//렌더링 된 이미지 윈도우에 올리기
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}

int	map(t_info	info)
{
    t_data data;


    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, screenWidth, screenHeight, "Raycaster");
    data.img = mlx_new_image(data.mlx, screenWidth, screenHeight);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	data.worldMap = info.map;
    data.posX = info.user_x; // 위위치
    data.posY = info.user_y; // 위위치
    data.dirX = -1; // 방방향벡터 
    data.dirY = 0; // 방방향벡터  
    data.planeX = 0; // 카카메라 평면
    data.planeY = 0.66;

    data.move_forward = 0;
    data.move_backward = 0;
    data.rotate_left = 0;
    data.rotate_right = 0;

	data.mapHeight = info.map_h;
	data.mapWidth = info.map_w;

	// for(int i = 0; i < data.mapHeight; i++)
	// {
	// 	for(int j = 0; j < data.mapWidth; j++)
    //     {
    //         // printf("%d ", cub_atoi(data.worldMap[i][j]));
    //         printf("%c", data.worldMap[i][j]);
    //     }
    //     printf("|\n");
	// }

    mlx_loop_hook(data.mlx, main_loop, &data);
    mlx_hook(data.win, 2, 1L<<0, key_press, &data);
    mlx_hook(data.win, 3, 1L<<1, key_release, &data);
    mlx_loop(data.mlx);

    return (0);
}