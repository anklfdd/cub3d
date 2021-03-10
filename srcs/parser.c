/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:07:07 by anastasia         #+#    #+#             */
/*   Updated: 2021/03/10 20:33:22 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_cnt_words(char **word)
{
	int		i;

	i = 0;
	while (word[i])
		i++;
	return (i);
}

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

int	ft_wall(char **word, char **wall)
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

int	ft_color(char **word, int *color)
{
	// int r;
	// int g;
	// int b;
	int		i;
	int		tmp_color;
	char	**clr;

	if (ft_cnt_words(word) != 2)
		return (1);
	clr = ft_split(word[1], ',');
	if (ft_cnt_words(clr) != 3)
		return (1);
	// r = ft_atoi(clr[0]);
	// g = ft_atoi(clr[1]);
	// b = ft_atoi(clr[2]);
	// *color = (r << 16) | (g << 8) | b;
	// printf("%d\n", *color);
	i = 0;
	*color = 0;
	while (i < 3)
	{
		tmp_color = ft_atoi(clr[i]);
		if (ft_count(tmp_color) == ft_strlen(clr[i]) && tmp_color >= 0 && tmp_color < 256)
			*color |= tmp_color << ((2 - i) * 8);
		else
			return (2);
		i++;
	}
	// printf("%d\n", *color);
	return (0);
}

//Обработать если нет флага и нет карты, то ошибка
int	ft_check_flag(char **word, t_map *map)
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
	//здесь поменять на код ошибки
	return (0);
}

int	ft_check_line(char *line, t_map *map)
{
	char	**word;
	int		err;
	
	word = ft_split(line, ' ');
	// обработать ошибки (при return 1)
	if ((err = ft_check_flag(word, map)) == 0) // если первое слово норм, идем дальше
	{
		err = 0;
		// printf("%d %d", map->win.width, map->win.height);
	}
	// else if ((err = ft_check_map()) == 0)
	// {
		// 
	// }
	else
		ft_error(err);
	// free(word);
	return (0);
}


//обработать пустые строки
int ft_parser(char *fname, t_map *map)
{
	int fd;
	char *line;

	fd = open(fname, O_RDONLY);
	// t_list
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		ft_check_line(line, map);
		// free(line);
	}
	get_next_line(fd, &line);
	// printf("%d %d\n", map->color.c, map->color.f);
	return (0);
}
