/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:07:07 by anastasia         #+#    #+#             */
/*   Updated: 2021/04/27 18:32:34 by gavril           ###   ########.fr       */
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

int	ft_color(char **word, int *color)
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
	return (ft_error(err));
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

int	ft_check_line(char *line, t_map *map)
{
	char	**word;
	int		err;

	word = ft_split(line, ' ');
	err = ft_check_flag(word, map);
	ft_free_w(word);
	return (ft_error(err));
}

int	ft_strchar(const char *str, int sym)
{
	int		ind;

	ind = 0;
	if (!str || !sym)
		return (0);
	while (str[ind] != '\0')
	{
		if (str[ind] == sym)
			return (ind + 1);
		ind++;
	}
	if (sym == '\0')
		return (ind + 1);
	return (0);
}

int	ft_angle(char **map, int x, int y)
{
	if (map[x + 1] != NULL && (int)ft_strlen(map[x + 1]) - 2 >= y && y - 1 >= 0 && map[x + 1][y - 1] == ' ')
		return (1);
	if (x - 1 >= 0 && y - 1 >= 0 && map[x - 1][y - 1] == ' ')
		return (1);
	if (map[x + 1] != NULL && (int)ft_strlen(map[x + 1]) - 2 >= y && map[x + 1][y + 1] == ' ')
		return (1);
	else if (map[x + 1] != NULL && (int)ft_strlen(map[x + 1]) - 2 < y)
		return (1);
	if (x - 1 >= 0 && map[x - 1][y + 1] == ' ')
		return (1);
	return (0);
}

int	ft_chval(char **map, int x, int y)
{
	if (map[x][y] == ' ' || ft_angle(map, x, y) == 1)
		return (1);
	if (map[x][y] != '2')
		map[x][y] = '4';
	if ((int)ft_strlen(map[x]) - 1 > y && (map[x][y + 1] == '0' || map[x][y + 1] == ' ' || map[x][y + 1] == '2'))
		if (map[x][y + 2] == '\0' || ft_chval(map, x, y + 1) == 1)
			return (1);
	if (y - 1 >= 0 && (map[x][y - 1] == '0' || map[x][y - 1] == ' ' || map[x][y - 1] == '2'))
	{
		if (y - 1 == 0 || ft_chval(map, x, y - 1) == 1)
			return (1);
	}
	else if (y - 1 < 0)
		return (1);
	if (map[x + 1] != NULL && (map[x + 1][y] == '0' || map[x + 1][y] == ' ' || map[x + 1][y] == '2'))
		if (map[x + 2] == NULL || ft_chval(map, x + 1, y) == 1 || (int)ft_strlen(map[x + 2]) <= y)
			return (1);
	if (x - 1 >= 0 && (map[x - 1][y] == '0' || map[x - 1][y] == ' ' || map[x - 1][y] == '2'))
		if (x - 1 == 0 || ft_chval(map, x - 1, y) == 1 || (int)ft_strlen(map[x - 2]) <= y)
			return (1);
	return (0);
}

int	ft_chplr(char **map, int i, int j)
{
	int		res;

	res = 4;
	if ((int)ft_strlen(map[i]) > j + 1 && ft_strchar("412", map[i][j + 1]) != 0)
		res -= 1;
	if (j - 1 >= 0 && ft_strchar("412", map[i][j - 1]) != 0)
		res -= 1;
	if (map[i + 2] != NULL && ft_strchar("412", map[i + 1][j]) != 0)
		res -= 1;
	if (i - 1 >= 0 && ft_strchar("412", map[i - 1][j]) != 0)
		res -= 1;
	return (res);
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

int	ft_check_sym(t_map *map, int *pl)
{
	int		i;
	int		j;
	int		err;
	int		u;

	i = 0;
	err = 0;
	u = map->cnt_spr;
	while (map->map[i])
	{
		j = 0;
		if (map->map[i][0] == '\0')
			err = 5;
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
			if (ft_strchar("NSWE", map->map[i][j]) != 0)
			{
				ft_init_plr(map->map[i][j], &(map->plr), i, j);
				err += ft_chplr(map->map, i, j);
				*pl += 1;
			}
			j++;
		}
		i++;
	}
	return (err);
}

int	ft_ch_sym(char *map, size_t *cnt_spr)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '2')
			*cnt_spr += 1;
		if (ft_strchar("NSWE120 ", map[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_map(t_map *map, t_list **l_map)
{
	int		err;
	t_list	*tmp;
	int		i;
	int		plr;

	err = 0;
	map->cnt_spr = 0;
	tmp = *l_map;
	i = -1;
	plr = 0;
	map->map = (char **)malloc(sizeof(char *) * (ft_lstsize(*l_map) + 1));
	while (tmp)
	{
		map->map[++i] = tmp->content;
		err += ft_ch_sym(map->map[i], &(map->cnt_spr));
		tmp = tmp->next;
	}
	map->spr = (t_sprite *)ft_calloc(map->cnt_spr, sizeof(t_sprite));
	err += ft_check_sym(map, &plr);
	if (plr != 1 || err != 0)
		err = 5;
	return (ft_error(err));
}

int	ft_parser(char *fname, t_map *map)
{
	int		fd;
	char	*line;
	int		c_flag;
	int		err;
	t_list	*l_map;

	fd = open(fname, O_RDONLY);
	line = NULL;
	c_flag = 0;
	err = 0;
	l_map = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == '\0' && l_map == NULL)
		{
			free(line);
			continue ;
		}
		if (c_flag++ < 8)
		{
			err += ft_check_line(line, map);
			free(line);
		}
		else
			ft_lstadd_back(&l_map, ft_lstnew(line));
	}
	ft_lstadd_back(&l_map, ft_lstnew(line));
	err += ft_check_map(map, &l_map);
	if (err != 0)
		ft_free_w(map->map);
	ft_lst_free(&l_map);
	return (err);
}
