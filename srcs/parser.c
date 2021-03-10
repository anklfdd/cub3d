/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasia <anastasia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:07:07 by anastasia         #+#    #+#             */
/*   Updated: 2021/03/10 17:49:02 by anastasia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_r(char **word, t_window *win)
{
	win->width = ft_atoi(word[1]);
	win->height = ft_atoi(word[2]);
	printf("af");
	if (ft_count(win->width) == ft_strlen(word[1]) && win->width > 0)
	{
		if (win->width > DISP_W)
			win->width = DISP_W;
	}
	else
		return (1);
	if (ft_count(win->height) == ft_strlen(word[2]) && win->height > 0)
	{
		if (win->height > DISP_H)
			win->height = DISP_H;
	}
	else
		return (1);
	return (0);
}

// int	ft_no(char **word, t_wall *wall)
// {
// 	return (0);
// }

int	ft_check_flag(char **word, t_map *map)
{
	printf("af");
	if (ft_strncmp(word[0], "R", 1) == 0)
		return (ft_r(word, &(map->win)));
	// else if (ft_strncmp(word[0], "NO", 2) == 0)
	// 	return (ft_no(word, &(map->wall)));
	else if (ft_strncmp(word[0], "SO", 2) == 0)
		return (0);
	else if (ft_strncmp(word[0], "WE", 2) == 0)
		return (0);
	else if (ft_strncmp(word[0], "EA", 2) == 0)
		return (0);
	else if (ft_strncmp(word[0], "S", 1) == 0)
		return (0);
	else if (ft_strncmp(word[0], "F", 1) == 0)
		return (0);
	else if (ft_strncmp(word[0], "C", 1) == 0)
		return (0);
	return (1);
}

int	ft_check_line(char *line, t_map *map)
{
	char **word;
	int i;
	int ch;
	
	word = ft_split(line, ' ');
	i = 0;
	ch = 0;
	printf("af");
	while (*word)
	{
		// обработать ошибки (при return 1)
		if (ft_check_flag(word, map) == 0) // если первое слово норм, идем дальше
		{
			printf("%d %d", map->win.width, map->win.height);
			// if ()
		}
		i++;
		ch++;
	}
	return (0);
}

int ft_parser(char *fname, t_map *map)
{
	int fd;
	char *line;

	fd = open(fname, O_RDONLY);
	// t_list
	line = NULL;
	printf("af");
	while (get_next_line(fd, &line) >= 0)
	{
		ft_check_line(line, map);
		// free(line);
	}
	return (0);
}
