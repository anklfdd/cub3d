/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:26:55 by gavril            #+#    #+#             */
/*   Updated: 2020/11/15 17:56:02 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int asc, size_t num)
{
	unsigned char	*string_str;
	size_t			ind;

	string_str = (unsigned char*)str;
	ind = 0;
	while (ind != num)
	{
		if (string_str[ind] == (unsigned char)asc)
		{
			return (&string_str[ind]);
		}
		ind++;
	}
	return (NULL);
}
