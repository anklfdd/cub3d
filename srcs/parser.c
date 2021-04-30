/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:07:07 by anastasia         #+#    #+#             */
/*   Updated: 2021/04/28 20:18:10 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_line(char *line, t_map *map)
{
	char	**word;
	int		err;

	word = ft_split(line, ' ');
	err = ft_check_flag(word, map);
	ft_free_w(word);
	return (ft_error(err));
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
	map->map = (char **)ft_calloc((ft_lstsize(*l_map) + 1), sizeof(char *));
	while (tmp)
	{
		map->map[++i] = tmp->content;
		err += ft_sym_in_map(map->map[i], &(map->cnt_spr));
		tmp = tmp->next;
	}
	map->spr = (t_sprite *)ft_calloc(map->cnt_spr, sizeof(t_sprite));
	err += ft_init_map(map, &plr);
	if (plr != 1 || err != 0)
		err = 5;
	return (ft_error(err));
}

int	get_next_line_in_cub(int fd, t_map *map)
{
	int		c_flag;
	char	*line;
	int		err;

	c_flag = 0;
	err = 0;
	line = NULL;
	map->l_map = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == '\0' && map->l_map == NULL)
			free(line);
		else if (c_flag++ < 8)
		{
			err += ft_check_line(line, map);
			free(line);
		}
		else
			ft_lstadd_back(&map->l_map, ft_lstnew(line));
	}
	if (map->l_map == NULL)
		return (7);
	ft_lstadd_back(&map->l_map, ft_lstnew(line));
	return (err);
}

int	ft_parser(char *fname, t_map *map)
{
	int		fd;
	int		err;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (7);
	err = 0;
	err += get_next_line_in_cub(fd, map);
	err += ft_check_map(map, &map->l_map);
	if (err != 0)
		ft_free_w(map->map);
	ft_lst_free(&map->l_map);
	return (err);
}
