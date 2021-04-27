/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:15:08 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 21:47:57 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_symset(const char *set, char sym)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == sym)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ind;
	char	*res;
	size_t	len_trim;

	ind = 0;
	if (!s1)
		return (0);
	len_trim = ft_strlen(s1);
	if (!set)
		return (ft_strdup(s1));
	while (s1[ind] && ft_symset(set, (char)s1[ind]))
	{
		ind++;
	}
	if (ind == (size_t)(ft_strlen(s1)))
		return (ft_strdup(""));
	while (ft_symset(set, s1[len_trim - 1]))
	{
		len_trim--;
	}
	res = (char *)malloc(sizeof(char) * (len_trim - ind + 1));
	ft_strlcpy(res, s1 + ind, len_trim - ind + 1);
	return (res);
}
