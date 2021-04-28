/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:47:17 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 17:20:18 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_chplr(char **map, int i, int j)
{
	int		res;

	res = 4;
	if ((int)ft_strlen(map[i]) > j + 1
		&& ft_strchar_ind("412", map[i][j + 1]) != 0)
		res -= 1;
	if (j - 1 >= 0 && ft_strchar_ind("412", map[i][j - 1]) != 0)
		res -= 1;
	if (map[i + 2] != NULL && ft_strchar_ind("412", map[i + 1][j]) != 0)
		res -= 1;
	if (i - 1 >= 0 && ft_strchar_ind("412", map[i - 1][j]) != 0)
		res -= 1;
	return (res);
}

void	ft_sym_w_e(char sym, t_plr *plr)
{
	if (sym == 'W')
	{
		plr->dirx = 0;
		plr->diry = -1;
		plr->planex = -0.66;
		plr->planey = 0;
	}
	if (sym == 'E')
	{
		plr->dirx = 0;
		plr->diry = 1;
		plr->planex = 0.66;
		plr->planey = 0;
	}
}

void	ft_init_plr(char sym, t_plr *plr, int i, int j)
{
	plr->x = i;
	plr->y = j;
	if (sym == 'N')
	{
		plr->dirx = -1;
		plr->diry = 0;
		plr->planex = 0;
		plr->planey = 0.66;
	}
	if (sym == 'S')
	{
		plr->dirx = 1;
		plr->diry = 0;
		plr->planex = 0;
		plr->planey = -0.66;
	}
	if (sym == 'W')
		ft_sym_w_e(sym, plr);
	if (sym == 'E')
		ft_sym_w_e(sym, plr);
}
