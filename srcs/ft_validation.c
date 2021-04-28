/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:57:11 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 16:47:14 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_sym_in_map(char *map, size_t *cnt_spr)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '2')
			*cnt_spr += 1;
		if (ft_strchar_ind("NSWE120 ", map[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_c(t_map *map, int i, int *pl, int u)
{
	int		j;
	int		err;

	j = 0;
	err = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] == '0')
			err += ft_chval(map->map, i, j);
		if (map->map[i][j] == '2')
		{
			map->spr[u - 1].x = i;
			map->spr[u - 1].y = j;
			u--;
		}
		if (ft_strchar_ind("NSWE", map->map[i][j]) != 0)
		{
			ft_init_plr(map->map[i][j], &(map->plr), i, j);
			err += ft_chplr(map->map, i, j);
			*pl += 1;
		}
		j++;
	}
	return (err);
}

int	ft_init_map(t_map *map, int *pl)
{
	int		i;
	int		err;
	int		u;

	i = 0;
	err = 0;
	u = map->cnt_spr;
	while (map->map[i])
	{
		if (map->map[i][0] == '\0')
			err = 5;
		err += ft_c(map, i, pl, u);
		i++;
	}
	return (err);
}
