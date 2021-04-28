/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:09:01 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 18:08:22 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_angle(char **map, int x, int y)
{
	if (map[x + 1] != NULL && (int)ft_strlen(map[x + 1]) - 2 >= y
		&& y - 1 >= 0 && map[x + 1][y - 1] == ' ')
		return (1);
	if (x - 1 >= 0 && y - 1 >= 0 && map[x - 1][y - 1] == ' ')
		return (1);
	if (map[x + 1] != NULL && (int)ft_strlen(map[x + 1]) - 2 >= y
		&& map[x + 1][y + 1] == ' ')
		return (1);
	else if (map[x + 1] != NULL && (int)ft_strlen(map[x + 1]) - 2 < y)
		return (1);
	if (x - 1 >= 0 && map[x - 1][y + 1] == ' ')
		return (1);
	return (0);
}

int	ft_cap(char **map, int x, int y)
{
	if (map[x][y] == ' ' || ft_angle(map, x, y) == 1)
		return (1);
	if (map[x][y] != '2')
		map[x][y] = '4';
	return (0);
}

int	ft_chval(char **map, int x, int y)
{
	ft_cap(map, x, y);
	if ((int)ft_strlen(map[x]) - 1 > y && (map[x][y + 1] == '0'
		|| map[x][y + 1] == ' ' || map[x][y + 1] == '2'))
		if (map[x][y + 2] == '\0' || ft_chval(map, x, y + 1) == 1)
			return (1);
	if (y - 1 >= 0 && (map[x][y - 1] == '0' || map[x][y - 1] == ' '
		|| map[x][y - 1] == '2'))
	{
		if (y - 1 == 0 || ft_chval(map, x, y - 1) == 1)
			return (1);
	}
	else if (y - 1 < 0)
		return (1);
	if (map[x + 1] != NULL && (map[x + 1][y] == '0'
		|| map[x + 1][y] == ' ' || map[x + 1][y] == '2'))
		if (map[x + 2] == NULL || ft_chval(map, x + 1, y) == 1
			|| (int)ft_strlen(map[x + 2]) <= y)
			return (1);
	if (x - 1 >= 0 && (map[x - 1][y] == '0' || map[x - 1][y] == ' '
		|| map[x - 1][y] == '2'))
		if (x - 1 == 0 || ft_chval(map, x - 1, y) == 1
			|| (int)ft_strlen(map[x - 2]) <= y)
			return (1);
	return (0);
}
