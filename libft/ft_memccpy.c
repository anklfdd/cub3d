/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:28:26 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 22:03:57 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int asc, size_t num)
{
	size_t			ind;
	unsigned char	*string_dst;
	unsigned char	*string_src;

	string_dst = (unsigned char *)dst;
	string_src = (unsigned char *)src;
	ind = 0;
	while (ind < num)
	{
		string_dst[ind] = string_src[ind];
		if (string_src[ind] == (unsigned char)asc)
			return (string_dst + ind + 1);
		ind++;
	}
	return (NULL);
}
