/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:32:33 by gavril            #+#    #+#             */
/*   Updated: 2020/11/04 22:34:28 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	char	*string_src;
	char	*string_dst;
	size_t	a;

	string_src = (char*)src;
	string_dst = (char*)dst;
	a = 0;
	if (!src && !dst)
		return (NULL);
	while (a != num)
	{
		string_dst[a] = string_src[a];
		a++;
	}
	return (string_dst);
}
