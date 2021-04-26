/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasia <anastasia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:08:49 by anastasia         #+#    #+#             */
/*   Updated: 2021/04/26 23:09:54 by anastasia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int sprite()
// map->spr[5].x
//            .y

int			cast_sprite(t_map *map, double *zbuffer)    
{
	size_t	i;
	double	sprx;
	double	spry;
	double	invdet;
	double	transx;
	double	transy;
	int		spr_scrn_x;
	int		spr_h;
	int		draw_start_y;
	int		draw_end_y;
	int		spr_w;
	int		draw_start_x;
	int		draw_end_x;
	int		stripe;
	int		texx;
	int		texy;
	int		y;
	int		d;
	int		color;

	i = 0;
	while (i < map->cnt_spr)
	{
		sprx = map->spr[i].x - map->plr.x + 0.5;
		spry = map->spr[i].y - map->plr.y + 0.5;
		invdet = 1.0 / (map->plr.planex * map->plr.diry - map->plr.planey * map->plr.dirx);
		transx = invdet * (map->plr.diry * sprx - map->plr.dirx * spry);
		transy = invdet * (-map->plr.planey * sprx + map->plr.planex * spry);
		spr_scrn_x = (int)((map->win.width / 2) * (1 + transx / transy));
		spr_h = abs((int)(map->win.height / transy));
		draw_start_y = -spr_h / 2 + map->win.height / 2;
		if (draw_start_y < 0)
			draw_start_y = 0;
		draw_end_y = spr_h / 2 + map->win.height / 2;
		if (draw_end_y >= map->win.height)
			draw_end_y = map->win.height - 1;
		spr_w = abs((int)(map->win.height / transy));
		draw_start_x = -spr_w / 2 + spr_scrn_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		draw_end_x = spr_w / 2 + spr_scrn_x;
		if (draw_end_x >= map->win.width)
			draw_end_x = map->win.width - 1;
		stripe = draw_start_x;
		while (stripe < draw_end_x)
		{
			texx = (int)((512 * (stripe - (-spr_w / 2 + spr_scrn_x)) * map->tex.width[sprite] / spr_w) / 512);
			if (transy > 0 && stripe > 0 && stripe < map->win.width && transy < zbuffer[stripe])
			{
				y = draw_start_y;
				while (y < draw_end_y)
				{
					d = (y) * 512 - map->win.height * 256 + spr_h * 256; // (y)
					texy = ((d * map->tex.height[sprite]) / spr_h) / 512;
					color = map->tex.texture[sprite][map->tex.width[sprite] * texy + texx];
					if ((color & 0xFFFFFF) != 0)
						map->mlx.addr[y * map->win.width + stripe] = color;
					y++;
				}
			}
			stripe++;
		}
		i++;
	}
	return (0);
}

void    ft_swap(double *a, double *b, t_sprite *c, t_sprite *d)
{
    double tmp;
    t_sprite tmp2;

    tmp = *a;
    *a = *b;
    *b = tmp;

    tmp2 = *c;
    *c = *d;
    *d = tmp2;
}

int		paint_sprites(double *zbuffer, t_map *map)
{
	size_t		i;
    double dist[map->cnt_spr];
	i = 0;
	while(i < map->cnt_spr)
	{
        dist[i] = ((map->plr.x - map->spr[i].x) * (map->plr.x - map->spr[i].x) + (map->plr.y - map->spr[i].y) * (map->plr.y - map->spr[i].y));
		i++;
	}
    size_t j = map->cnt_spr - 1;
    while (j > 0)
    {
        i = 0;
        while (i < j)
        {
            if (dist[i] < dist[i + 1])
                ft_swap(&dist[i], &dist[i + 1], &map->spr[i], &map->spr[i + 1]);
            i++;
        }
        j--;
    }
	cast_sprite(map, zbuffer);
	return (0);
}
