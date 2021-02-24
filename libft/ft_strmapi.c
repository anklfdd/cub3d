/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:48:35 by gavril            #+#    #+#             */
/*   Updated: 2020/11/13 20:24:32 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*str;
	size_t		ind;
	size_t		j;

	ind = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(str = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[j] != '\0')
	{
		str[ind] = f(j, (char)s[j]);
		ind++;
		j++;
	}
	str[ind] = '\0';
	return (str);
}
