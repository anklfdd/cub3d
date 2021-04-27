/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:39:56 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 22:07:19 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *str)
{
	size_t	len;
	size_t	ind;
	char	buf;

	len = ft_strlen(str) - 1;
	ind = 0;
	buf = 0;
	if (str[0] == '-')
		ind++;
	while (ind < len)
	{
		buf = str[ind];
		str[ind] = str[len];
		str[len] = buf;
		ind++;
		len--;
	}
	return (str);
}

static char	*ft_strcpy(char *dst, char *src)
{
	int	ind;

	ind = 0;
	if (!src || !dst)
		return (0);
	while (src[ind])
	{
		dst[ind] = src[ind];
		ind++;
	}
	dst[ind] = '\0';
	return (dst);
}

size_t	ft_count(long int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = n * (-1);
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	ind;
	char	*str;

	ind = 0;
	str = (char *)malloc(sizeof(char) * (ft_count(n) + 1));
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		str[ind++] = '-';
		n = n * (-1);
	}
	if (n == 0)
		str[ind++] = '0';
	while (n > 0)
	{
		str[ind++] = n % 10 + '0';
		n = n / 10;
	}
	str[ind] = '\0';
	return (ft_reverse(str));
}
