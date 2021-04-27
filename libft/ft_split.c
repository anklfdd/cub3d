/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavril <gavril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:14:42 by gavril            #+#    #+#             */
/*   Updated: 2021/04/27 22:22:14 by gavril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(char **str, size_t n)
{
	while (n > 0)
	{
		free(str[n]);
		n--;
	}
	free(str);
}

static size_t	ft_sym_count(char const *s, char c)
{
	size_t count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static char		*ft_words(char const *s, char c)
{
	char	*str;
	size_t	ind;

	ind = 0;
	if (!(str = ft_calloc(ft_sym_count(s, c) + 1, sizeof(char))))
		return (NULL);
	while (*s && *s != c)
	{
		str[ind++] = *s++;
	}
	str[ind] = '\0';
	return (str);
}

static size_t	ft_word_count(char const *str, char c)
{
	size_t ind;
	size_t amount;

	ind = 0;
	amount = 0;
	while (*str)
	{
		if (*str && *str != c && ind == 0)
		{
			amount++;
			ind = 1;
		}
		if (*str && ind == 1 && *str == c)
		{
			ind = 0;
		}
		str++;
	}
	return (amount);
}

char			**ft_split(char const *s, char c)
{
	char	**words;
	size_t	ind;

	if (!s)
		return (NULL);
	if (!(words = ft_calloc((ft_word_count(s, c) + 1), sizeof(char**))))
		return (NULL);
	ind = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			if (!(words[ind++] = ft_words(s, c)))
			{
				ft_free(words, ft_word_count(s, c));
				return (NULL);
			}
			s += ft_sym_count(s, c);
		}
	}
	words[ind] = NULL;
	return (words);
}
