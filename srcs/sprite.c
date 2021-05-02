/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:08:49 by anastasia         #+#    #+#             */
/*   Updated: 2021/05/02 17:12:51 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_swap(double *a, double *b, t_sprite *c, t_sprite *d)
{
	double		tmp;
	t_sprite	tmp2;

	tmp = *a;
	*a = *b;
	*b = tmp;
	tmp2 = *c;
	*c = *d;
	*d = tmp2;
}

void	sort_sprites(double *dist, t_map *map)
{
	size_t	i;
	size_t	j;

	j = map->cnt_spr - 1;
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
}

void	dist_sprites(double *zbuffer, t_map *map)
{
	size_t	i;
	double	*dist;

	i = 0;
	dist = (double *)ft_calloc(map->cnt_spr, sizeof(double));
	while (i < map->cnt_spr)
	{
		dist[i] = ((map->plr.x - map->spr[i].x) * (map->plr.x - map->spr[i].x)
				+ (map->plr.y - map->spr[i].y) * (map->plr.y - map->spr[i].y));
		i++;
	}
	sort_sprites(dist, map);
	free(dist);
	cast_sprite(map, zbuffer);
}
