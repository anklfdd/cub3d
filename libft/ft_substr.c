/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:38:44 by gavril            #+#    #+#             */
/*   Updated: 2020/11/17 21:02:42 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	ind;

	ind = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start + 1 < len)
	{
		if (!(subs = (char*)malloc(sizeof(char) * (ft_strlen(s) - start + 1))))
			return (NULL);
	}
	else
	{
		if (!(subs = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
	}
	while (ind < len && s[start + ind])
	{
		subs[ind] = s[start + ind];
		ind++;
	}
	subs[ind] = '\0';
	return (subs);
}
