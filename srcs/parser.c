/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:07:07 by anastasia         #+#    #+#             */
/*   Updated: 2021/03/11 20:57:31 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cnt_words(char **word)
{
	int		i;

	i = 0;
	while (word[i])
		i++;
	return (i);
}

int		ft_r(char **word, t_window *win)
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
		return (2);
	if (ft_count(win->height) == ft_strlen(word[2]) && win->height > 0)
	{
		if (win->height > DISP_H)
			win->height = DISP_H;
	}
	else
		return (2);
	return (0);
}

int		ft_wall(char **word, char **wall)
{
	int fd;

	if (ft_cnt_words(word) != 2)
		return (1);
	if ((fd = open(word[1], O_RDONLY)) > 0)
	{
		*wall = ft_strdup(word[1]);
		close(fd);
	}
	else
		return (3);
	return (0);
}

int		ft_color(char **word, int *color)
{
	int		i;
	int		tmp_clr;
	char	**clr;
	int		err;

	i = 0;
	err = 0;
	clr = ft_split(word[1], ',');
	if (ft_cnt_words(word) != 2 || ft_cnt_words(clr) != 3)
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

int		ft_check_flag(char **word, t_map *map)
{
	if (ft_strncmp(word[0], "R", 1) == 0)
		return (ft_r(word, &(map->win)));
	else if (ft_strncmp(word[0], "NO", 2) == 0)
		return (ft_wall(word, &(map->wall.no)));
	else if (ft_strncmp(word[0], "SO", 2) == 0)
		return (ft_wall(word, &(map->wall.so)));
	else if (ft_strncmp(word[0], "WE", 2) == 0)
		return (ft_wall(word, &(map->wall.we)));
	else if (ft_strncmp(word[0], "EA", 2) == 0)
		return (ft_wall(word, &(map->wall.ea)));
	else if (ft_strncmp(word[0], "S", 1) == 0)
		return (ft_wall(word, &(map->wall.spr)));
	else if (ft_strncmp(word[0], "F", 1) == 0)
		return (ft_color(word, &(map->color.f)));
	else if (ft_strncmp(word[0], "C", 1) == 0)
		return (ft_color(word, &(map->color.c)));
	return (4);
}

int		ft_check_line(char *line, t_map *map)
{
	char	**word;
	int		err;

	word = ft_split(line, ' ');
	if ((err = ft_check_flag(word, map)) != 0)
		ft_error(err);
	ft_free_w(word);
	return (err);
}

int		ft_check_map(char *line, t_map *map)
{
	int err;

	err = 0;
	ft_error(err);
	return (err);
}

int		ft_parser(char *fname, t_map *map)
{
	int		fd;
	char	*line;
	int		c_flag;
	int		err;

	fd = open(fname, O_RDONLY);
	line = NULL;
	c_flag = 0;
	err = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == '\0')
			continue ;
		if (c_flag++ < 8 && ft_check_line(line, map) == 0)
			err = 0;
		else if (ft_check_map(line, map) == 0)
			err = 0;
		free(line);
	}
	free(line);
	line = NULL;
	return (err);
}
