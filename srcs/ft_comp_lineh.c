/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp_lineh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:53:31 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 18:01:52 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_comp_lineh(t_map *map)
{
	if (map->rc.side == 0 || map->rc.side == 1)
		map->rc.prpwalldist = (map->rc.mapx - map->plr.x
				+ (1 - map->rc.stepx) / 2) / map->rc.raydirx;
	else
		map->rc.prpwalldist = (map->rc.mapy - map->plr.y
				+ (1 - map->rc.stepy) / 2) / map->rc.raydiry;
	map->rc.lineheight = (int)(map->win.height / map->rc.prpwalldist);
	map->rc.drawstart = -map->rc.lineheight / 2 + map->win.height / 2;
	if (map->rc.drawstart < 0)
		map->rc.drawstart = 0;
	map->rc.drawend = map->rc.lineheight / 2 + map->win.height / 2;
	if (map->rc.drawend >= map->win.height)
		map->rc.drawend = map->win.height - 1;
	if (map->rc.side == 0 || map->rc.side == 1)
		map->rc.wallx = map->plr.y + map->rc.prpwalldist * map->rc.raydiry;
	else
		map->rc.wallx = map->plr.x + map->rc.prpwalldist * map->rc.raydirx;
	map->rc.wallx -= (int)map->rc.wallx;
	map->rc.texx = (int)(map->rc.wallx
			* (double)(map->tex.width[map->rc.side]));
}

void	ft_comp_tex(t_map *map)
{
	if ((map->rc.side <= 1 && map->rc.raydirx > 0)
		|| (map->rc.side >= 2 && map->rc.raydiry < 0))
		map->rc.texx = map->tex.width[map->rc.side] - map->rc.texx - 1;
	map->rc.step = 1.0 * map->tex.height[map->rc.side] / map->rc.lineheight;
	map->rc.texpos = (map->rc.drawstart - map->win.height
			/ 2 + map->rc.lineheight / 2) * map->rc.step;
	map->rc.y = map->rc.drawstart;
	while (map->rc.y < map->rc.drawend)
	{
		map->rc.texy = (int)map->rc.texpos
			& (map->tex.height[map->rc.side] - 1);
		map->rc.texpos += map->rc.step;
		map->mlx.addr[map->rc.x + map->win.width * map->rc.y]
			= map->tex.texture[map->rc.side][map->rc.texx
			+ map->rc.texy * map->tex.width[map->rc.side]];
		map->rc.y++;
	}
}
