/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:18:11 by gavril            #+#    #+#             */
/*   Updated: 2021/05/02 17:23:37 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_r(char **word, t_window *win)
{
	if (ft_cnt_words(word) != 3)
		return (1);
	win->width = ft_atoi(word[1]);
	win->height = ft_atoi(word[2]);
	if (ft_count(win->width) == ft_strlen(word[1]) && win->width > 0)
	{
		if (win->width > DISP_W)
			win->width = DISP_W;
	}
	else
		return (-2);
	if (ft_count(win->height) == ft_strlen(word[2]) && win->height > 0)
	{
		if (win->height > DISP_H)
			win->height = DISP_H;
	}
	else
		return (-2);
	return (0);
}

int	ft_wall(char **word, char **wall)
{
	int		fd;

	if (ft_cnt_words(word) != 2)
		return (1);
	fd = open(word[1], O_RDONLY);
	if (fd > 0)
	{
		*wall = ft_strdup(word[1]);
		close(fd);
	}
	else
		return (3);
	return (0);
}

int	cnt_dot(char *str)
{
	int	cnt_dot;
	int	i;

	cnt_dot = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			cnt_dot++;
		i++;
	}
	return (cnt_dot);
}

int	ft_color(char **word, int *color)
{
	int		i;
	int		tmp_clr;
	char	**clr;
	int		err;

	i = 0;
	err = 0;
	clr = ft_split(word[1], ',');
	if (ft_cnt_words(word) != 2 || ft_cnt_words(clr) != 3
		|| cnt_dot(word[1]) != 2)
		err = 1;
	while (clr[i])
	{
		tmp_clr = ft_atoi(clr[i]);
		if (ft_count(tmp_clr) == ft_strlen(clr[i])
			&& tmp_clr >= 0 && tmp_clr <= 255)
			*color |= tmp_clr << ((2 - i) * 8);
		else
			err = 2;
		i++;
	}
	ft_free_w(clr);
	return (err);
}

int	ft_check_flag(char **word, t_map *map)
{
	if (ft_strncmp(word[0], "R", 1) == 0)
		return (ft_r(word, &(map->win)));
	else if (ft_strncmp(word[0], "NO", 2) == 0)
		return (ft_wall(word, &(map->wall[north])));
	else if (ft_strncmp(word[0], "SO", 2) == 0)
		return (ft_wall(word, &(map->wall[south])));
	else if (ft_strncmp(word[0], "WE", 2) == 0)
		return (ft_wall(word, &(map->wall[west])));
	else if (ft_strncmp(word[0], "EA", 2) == 0)
		return (ft_wall(word, &(map->wall[east])));
	else if (ft_strncmp(word[0], "S", 1) == 0)
		return (ft_wall(word, &(map->wall[sprite])));
	else if (ft_strncmp(word[0], "F", 1) == 0)
		return (ft_color(word, &(map->color.f)));
	else if (ft_strncmp(word[0], "C", 1) == 0)
		return (ft_color(word, &(map->color.c)));
	return (4);
}
