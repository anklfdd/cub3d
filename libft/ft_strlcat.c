/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:53:22 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 21:55:30 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t sz)
{
	size_t	ind;
	size_t	len;
	size_t	m;

	ind = 0;
	len = 0;
	while (dst[len] != '\0' && len < sz)
		len++;
	m = len;
	while (src[ind] && len + 1 < sz)
	{
		dst[len] = src[ind];
		len++;
		ind++;
	}
	if (m < sz)
		dst[len] = '\0';
	return (ft_strlen(src) + m);
}
