/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:59:31 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 20:41:37 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	transform_sprite(t_map *map, size_t i)
{
	double	sprx;
	double	spry;
	double	invdet;
	double	transx;

	sprx = map->spr[i].x - map->plr.x + 0.5;
	spry = map->spr[i].y - map->plr.y + 0.5;
	invdet = 1.0 / (map->plr.planex * map->plr.diry
			- map->plr.planey * map->plr.dirx);
	transx = invdet * (map->plr.diry * sprx - map->plr.dirx * spry);
	map->c_spr.transy = invdet * (-map->plr.planey
			* sprx + map->plr.planex * spry);
	map->c_spr.spr_scrn_x = (int)((map->win.width / 2)
			* (1 + transx / map->c_spr.transy));
	map->c_spr.spr_h = abs((int)(map->win.height / map->c_spr.transy));
}

void	computation_sprite(t_map *map)
{
	map->c_spr.draw_start_y = -map->c_spr.spr_h / 2 + map->win.height / 2;
	if (map->c_spr.draw_start_y < 0)
		map->c_spr.draw_start_y = 0;
	map->c_spr.draw_end_y = map->c_spr.spr_h / 2 + map->win.height / 2;
	if (map->c_spr.draw_end_y >= map->win.height)
		map->c_spr.draw_end_y = map->win.height - 1;
	map->c_spr.spr_w = abs((int)(map->win.height / map->c_spr.transy));
	map->c_spr.draw_start_x = -map->c_spr.spr_w / 2 + map->c_spr.spr_scrn_x;
	if (map->c_spr.draw_start_x < 0)
		map->c_spr.draw_start_x = 0;
	map->c_spr.draw_end_x = map->c_spr.spr_w / 2 + map->c_spr.spr_scrn_x;
	if (map->c_spr.draw_end_x >= map->win.width)
		map->c_spr.draw_end_x = map->win.width - 1;
}

void	color_stripe(t_map *map, int color)
{
	int		y;
	int		d;

	y = map->c_spr.draw_start_y;
	while (y < map->c_spr.draw_end_y)
	{
		d = y * 512 - map->win.height * 256 + map->c_spr.spr_h * 256;
		map->c_spr.texy = ((d * map->tex.height[sprite])
				/ map->c_spr.spr_h) / 512;
		color = map->tex.texture[sprite][map->tex.width[sprite]
			* map->c_spr.texy + map->c_spr.texx];
		if ((color & 0xFFFFFF) != 0)
			map->mlx.addr[y * map->win.width + map->c_spr.stripe] = color;
		y++;
	}
}

void	paint_sprite(t_map *map, double *zbuffer, int color)
{
	int		tmp;

	map->c_spr.stripe = map->c_spr.draw_start_x;
	while (map->c_spr.stripe < map->c_spr.draw_end_x)
	{
		tmp = map->c_spr.stripe - (-map->c_spr.spr_w / 2
				+ map->c_spr.spr_scrn_x);
		map->c_spr.texx = (int)((512 * tmp
					* map->tex.width[sprite] / map->c_spr.spr_w) / 512);
		if (map->c_spr.transy > 0 && map->c_spr.stripe > 0
			&& map->c_spr.stripe < map->win.width
			&& map->c_spr.transy < zbuffer[map->c_spr.stripe])
			color_stripe(map, color);
		map->c_spr.stripe++;
	}
}

int	cast_sprite(t_map *map, double *zbuffer)
{
	size_t	i;
	int		color;

	i = 0;
	color = 0;
	while (i < map->cnt_spr)
	{
		transform_sprite(map, i);
		computation_sprite(map);
		paint_sprite(map, zbuffer, color);
		i++;
	}
	return (0);
}
