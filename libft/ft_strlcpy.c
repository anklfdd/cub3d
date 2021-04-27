/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:56:48 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 21:55:14 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t sz)
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
	return (ft_strlen(src));
}
