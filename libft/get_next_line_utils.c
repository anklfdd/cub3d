/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:18:36 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 22:19:35 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strlcpy_gnl(char *dst, const char *src, size_t sz)
{
	size_t	ind;

	ind = 0;
	if (!src || !dst)
		return (0);
	if (sz != 0)
	{
		while (ind < sz - 1 && src[ind])
		{
			dst[ind] = src[ind];
			ind++;
		}
		dst[ind] = '\0';
	}
	return (dst);
}

size_t		ft_strchr_gnl(const char *str, int sym)
{
	size_t	ind;

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
