/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:18:41 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 21:15:47 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_in_line(char **line, char **data, char *buf)
{
	char	*tmp;

	tmp = NULL;
	if (*data && !buf)
	{
		*line = (char *)malloc(sizeof(char) * ft_strchr_gnl(*data, '\n'));
		*line = ft_strlcpy_gnl(*line, *data, ft_strchr_gnl(*data, '\n'));
		tmp = *data;
		*data = ft_strjoin(tmp + ft_strchr_gnl(*data, '\n'), "");
		free(tmp);
		tmp = NULL;
	}
	else if (data && buf)
	{
		*line = (char *)malloc(sizeof(char) * ft_strchr_gnl(buf, '\n'));
		*line = ft_strlcpy_gnl(*line, buf, ft_strchr_gnl(buf, '\n'));
		tmp = *data;
		*data = ft_strjoin(buf + ft_strchr_gnl(buf, '\n'), "");
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

static int	reading_file(char **data, char **buf, char **line)
{
	if (ft_strchr_gnl(*buf, '\n'))
	{
		if (*data)
		{
			*data = strjoin_data_buf(*data, *buf);
			write_in_line(line, data, 0);
			return (1);
		}
		else if (!(*data))
		{
			write_in_line(line, data, *buf);
			return (1);
		}
	}
	else if (!(ft_strchr_gnl(*buf, '\n')))
	{
		if (*data)
			*data = strjoin_data_buf(*data, *buf);
		else if (!(*data))
			*data = ft_strjoin(*buf, "");
	}
	return (0);
}

static int	write_last_line(char **data, char **line)
{
	size_t	a;

	a = 0;
	if (*data != NULL)
	{
		while (((*data)[a]) != '\0')
			a++;
		*line = (char *)malloc(sizeof(char) * a + 1);
		*line = ft_strlcpy_gnl(*line, *data, a + 1);
		free(*data);
		*data = NULL;
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * 1);
		*line[0] = '\0';
	}
	return (0);
}

int	ft_read(int fd, char *buf, char **line, char **data)
{
	ssize_t	ret_read;

	ret_read = 1;
	while (ret_read > 0)
	{
		ret_read = read(fd, buf, BUFFER_SIZE);
		buf[ret_read] = '\0';
		if ((reading_file(data, &buf, line)) == 1)
		{
			free(buf);
			return (1);
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*data;
	char		*buf;

	if (BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || (read(fd, buf, 0)) == -1)
		return (-1);
	if (data && ft_strchr_gnl(data, '\n'))
	{
		write_in_line(line, &data, 0);
		free(buf);
		return (1);
	}
	if (ft_read(fd, buf, line, &data) == 1)
		return (1);
	free(buf);
	return (write_last_line(&data, line));
}
