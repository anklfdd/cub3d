/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:53:37 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 22:03:05 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*string_src;
	unsigned char	*string_dst;
	size_t			num;

	string_src = (unsigned char *)src;
	string_dst = (unsigned char *)dst;
	num = 0;
	if (string_src < string_dst)
	{
		while (len != 0)
		{
			string_dst[len - 1] = string_src[len - 1];
			len--;
		}
	}
	else
	{
		while (num != len)
		{
			string_dst[num] = string_src[num];
			num++;
		}
	}
	return (string_dst);
}
