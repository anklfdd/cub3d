/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:50:51 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 17:59:37 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_comp_dltdist(t_map *map)
{
	if (map->rc.raydiry == 0)
		map->rc.dltdistx = 0;
	else if (map->rc.raydirx == 0)
		map->rc.dltdistx = 1;
	else
		map->rc.dltdistx = fabs(1 / map->rc.raydirx);
	if (map->rc.raydirx == 0)
		map->rc.dltdisty = 0;
	else if (map->rc.raydiry == 0)
		map->rc.dltdisty = 1;
	else
		map->rc.dltdisty = fabs(1 / map->rc.raydiry);
}

void	ft_comp_step(t_map *map)
{
	if (map->rc.raydirx < 0)
	{
		map->rc.stepx = -1;
		map->rc.sidedistx = (map->plr.x - map->rc.mapx) * map->rc.dltdistx;
	}
	else
	{
		map->rc.stepx = 1;
		map->rc.sidedistx = (map->rc.mapx + 1.0
				- map->plr.x) * map->rc.dltdistx;
	}
	if (map->rc.raydiry < 0)
	{
		map->rc.stepy = -1;
		map->rc.sidedisty = (map->plr.y - map->rc.mapy) * map->rc.dltdisty;
	}
	else
	{
		map->rc.stepy = 1;
		map->rc.sidedisty = (map->rc.mapy + 1.0
				- map->plr.y) * map->rc.dltdisty;
	}
}

void	ft_check_hit(t_map *map)
{
	map->rc.hit = 0;
	while (map->rc.hit == 0)
	{
		if (map->rc.sidedistx < map->rc.sidedisty)
		{
			map->rc.sidedistx += map->rc.dltdistx;
			map->rc.mapx += map->rc.stepx;
			if (map->rc.stepx > 0)
				map->rc.side = south;
			else
				map->rc.side = north;
		}
		else
		{
			map->rc.sidedisty += map->rc.dltdisty;
			map->rc.mapy += map->rc.stepy;
			if (map->rc.stepy > 0)
				map->rc.side = east;
			else
				map->rc.side = west;
		}
		if (map->map[map->rc.mapx][map->rc.mapy] == '1')
			map->rc.hit = 1;
	}
}

void	ft_comp_ray(t_map *map)
{
	ft_comp_dltdist(map);
	ft_comp_step(map);
	ft_check_hit(map);
	ft_comp_lineh(map);
	ft_comp_tex(map);
}

int	ft_raycast(t_map *map)
{
	map->rc.x = 0;
	map->rc.zbuffer = (double *)ft_calloc(map->win.width, sizeof(double));
	floor_ceil(map);
	while (map->rc.x < map->win.width)
	{
		map->rc.camx = 2 * map->rc.x / (double)map->win.width - 1;
		map->rc.raydirx = map->plr.dirx + map->plr.planex * map->rc.camx;
		map->rc.raydiry = map->plr.diry + map->plr.planey * map->rc.camx;
		map->rc.mapx = (int)map->plr.x;
		map->rc.mapy = (int)map->plr.y;
		ft_comp_ray(map);
		map->rc.zbuffer[map->rc.x] = map->rc.prpwalldist;
		map->rc.x++;
	}
	if (map->cnt_spr != 0)
		dist_sprites(map->rc.zbuffer, map);
	free(map->rc.zbuffer);
	return (0);
}
