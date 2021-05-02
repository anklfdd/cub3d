/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:57:11 by gavril            #+#    #+#             */
/*   Updated: 2021/05/02 17:25:46 by gavril           ###   ########.fr       */
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
			return (8);
		i++;
	}
	return (0);
}

int	ft_c(t_map *map, int i, int *pl, int *u)
{
	int		j;

	j = 0;
	while (map->map[i][j])
	{
		if (map->map[i][j] == '0' || map->map[i][j] == '2')
			if (new_ff(map->map, i, j) != 0)
				return (9);
		if (map->map[i][j] == '2')
		{
			map->spr[*u - 1].x = i;
			map->spr[*u - 1].y = j;
			*u -= 1;
		}
		if (ft_strchar_ind("NSWE", map->map[i][j]) != 0)
		{
			ft_init_plr(map->map[i][j], &(map->plr), i, j);
			if (new_ff(map->map, i, j) != 0)
				return (10);
			*pl += 1;
		}
		j++;
	}
	return (0);
}

int	ft_init_map(t_map *map, int *pl)
{
	int		i;
	int		err;
	int		u;

	i = 0;
	err = 0;
	u = map->cnt_spr;
	while (map->map[i] != NULL)
	{
		if (map->map[i][0] == '\0')
			return (5);
		err = ft_c(map, i, pl, &u);
		if (err != 0)
			return (err);
		i++;
	}
	if (*pl != 1)
		return (10);
	return (0);
}
