/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:49:56 by gavril            #+#    #+#             */
/*   Updated: 2021/04/28 21:36:11 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ind1;
	size_t	ind2;
	char	*res;

	ind1 = 0;
	ind2 = 0;
	if (!s1 || !s1)
		return (NULL);
	res = (char *)malloc(((ft_strlen(s1)
					+ ft_strlen(s2) + 1) * (sizeof(char))));
	if (!res)
		return (NULL);
	while (s1[ind1] != '\0')
	{
		res[ind1] = s1[ind1];
		ind1++;
	}
	while (s2[ind2])
	{
		res[ind1] = s2[ind2];
		ind1++;
		ind2++;
	}
	res[ind1] = '\0';
	return (res);
}
