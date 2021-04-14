/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:04:19 by gavril            #+#    #+#             */
/*   Updated: 2021/04/14 21:49:44 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(int param)
{
    (void)param;
    exit(0);
}

void	clear_window(t_map *map)
{
	int i;
	
	i = 0;
	while (i < map->win.width * map->win.height)
	{
		map->mlx.addr[i] = 0x000000;
		i++;
	}
}

void	paint_line(int x, int start, int end, t_map *map)
{
	while (start < end)
	{
		map->mlx.addr[map->win.width * start + x] = 0x120A8F;
		start++;
	}
}

int		ft_rayc(t_map *map)
{
	double camx;
	double raydirx;
	double raydiry;
	double dltdistx;
	double dltdisty;
	double sidedistx;
	double sidedisty;
	int mapx;
	int mapy;
	int stepx;
    int stepy;
	int hit;
	int side;
	double prpwalldist;
	int drawstart;
	int lineheight;
	int drawend;
	int x;
	
	//plane крутить вместе с dir
	x = 0;
	clear_window(map);
	while (x < map->win.width)
	{
		camx = 2 * x / (double)map->win.width - 1;
		raydirx = map->plr.dirx + map->plr.planex * camx;
		raydiry = map->plr.diry + map->plr.planey * camx;
		mapx = (int)map->plr.x;
		mapy = (int)map->plr.y;
		// printf("%f %f\n", raydirx, raydiry);
		
		if (raydiry == 0)
			dltdistx = 0;
		else if (raydirx == 0)
			dltdistx = 1;
		else
			dltdistx = fabs(1 / raydirx);
		if (raydirx == 0)
				dltdisty = 0;
		else if (raydiry == 0)
			dltdisty = 1;
		else
			dltdisty = fabs(1 / raydiry);
		
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (map->plr.x - mapx) * dltdistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - map->plr.x) * dltdistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (map->plr.y - mapy) * dltdisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - map->plr.y) * dltdisty;
		}
		hit = 0;
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += dltdistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += dltdisty;
				mapy += stepy;
				side = 1;
			}
			if (map->map[mapx][mapy] == '1')
				hit = 1;
			if (side == 0)
				prpwalldist = (mapx - map->plr.x + (1 - stepx) / 2) / raydirx;
			else
				prpwalldist = (mapy - map->plr.y + (1 - stepy) / 2) / raydiry;
			lineheight = (int)(map->win.height / prpwalldist);
			drawstart = -lineheight / 2 + map->win.height / 2;
			if (drawstart < 0)
				drawstart = 0;
			drawend = lineheight / 2 + map->win.height / 2;
			if (drawend >= map->win.height)
				drawend = map->win.height - 1;
			
		}
		paint_line(x, drawstart, drawend, map);
		x++;
	}
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win, map->mlx.img, 0, 0);
	return (0);
}

int		key_press(int keycode, t_map *map)
{
	if (keycode == 53) // close
		exit(0);
		//w
	if (keycode == 13)
	{
		if (map->map[(int)(map->plr.x + map->plr.dirx * 0.3)][(int)map->plr.y] != '1')
			map->plr.x += map->plr.dirx * 0.1;
		if (map->map[(int)(map->plr.x)][(int)(map->plr.y + map->plr.diry * 0.3)] != '1')
			map->plr.y += map->plr.diry * 0.1;
		// map->plr.y += 0.01;
	}

	// A
	if (keycode == 0)
	{
		if (map->map[(int)(map->plr.x - map->plr.dirx * 0.3)][(int)map->plr.y] != '1')
		{
			map->plr.x += map->plr.dirx * 0.5;
			map->plr.y += map->plr.diry * 0.5;
		}
		if (map->map[(int)(map->plr.x)][(int)(map->plr.y - map->plr.diry * 0.3)] != '1')
		{
			map->plr.x -= map->plr.dirx * 0.5;
			map->plr.y -= map->plr.diry * 0.5;
		}
	}
	
	//s
	if (keycode == 1)
	{
		if (map->map[(int)(map->plr.x - map->plr.dirx * 0.3)][(int)map->plr.y] != '1')
			map->plr.x -= map->plr.dirx * 0.1;
		if (map->map[(int)(map->plr.x)][(int)(map->plr.y - map->plr.diry * 0.3)] != '1')
			map->plr.y -= map->plr.diry * 0.1;
		// map->plr.y = 0.01;
	}
	// if (keycode == 2) // D

	double olddirx;
	double oldplanex;
	// <
	if (keycode == 123)
	{
		olddirx = map->plr.dirx;
		map->plr.dirx = map->plr.dirx * cos(0.1) - map->plr.diry * sin(0.1);
		map->plr.diry = olddirx * sin(0.1) + map->plr.diry * cos(0.1);
		oldplanex = map->plr.planex;
		map->plr.planex = map->plr.planex * cos(0.1) - map->plr.planey * sin(0.1);
		map->plr.planey = oldplanex * sin(0.1) + map->plr.planey * cos(0.1);
		// printf("dx = %f dy = %f px = %f py = %f\n", map->plr.dirx, map->plr.diry, map->plr.planex, map->plr.planey);
	}

	// >
	if (keycode == 124)
	{
		olddirx = map->plr.dirx;
		map->plr.dirx = map->plr.dirx * cos(-0.1) - map->plr.diry * sin(-0.1);
		map->plr.diry = olddirx * sin(-0.1) + map->plr.diry * cos(-0.1);
		oldplanex = map->plr.planex;
		map->plr.planex = map->plr.planex * cos(-0.1) - map->plr.planey * sin(-0.1);
		map->plr.planey = oldplanex * sin(-0.1) + map->plr.planey * cos(-0.1);
	}
	ft_rayc(map);
	return (0);
}

void	init_mlx(t_map	*map)
{
	// int		offset;

	map->mlx.mlx = mlx_init();
	map->mlx.mlx_win = mlx_new_window(map->mlx.mlx, map->win.width, map->win.height, "cub");
	map->mlx.img = mlx_new_image(map->mlx.mlx, map->win.width, map->win.height);
	// mlx_loop(mlx);
	map->mlx.addr = (int *)mlx_get_data_addr(map->mlx.img, &map->mlx.bpp, &map->mlx.llen,
                                 &map->mlx.endian);

	// offset = (y * llen + x * (bpp / 8));
	// int y = 100;
	// int x = 100;
	// while (y++ < 200)
	// {
	// 	x = 100;
	// 	while (x++ < 200)
	// 		mlx_pixel_put(map->mlx.mlx, map->mlx.mlx_win, x, y, 0x00FF00FF);
	// 	// mlx->addr[i] = 0xFF0000;
	// 	// i++;
	// }

	// map->plr.planex = 0;
	// map->plr.planey = 0.66;
	ft_rayc(map);
	// mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	mlx_hook(map->mlx.mlx_win, 17, 0, ft_close, 0);
	mlx_hook(map->mlx.mlx_win, 2, 0, key_press, map);

	mlx_loop(map->mlx.mlx);
}
