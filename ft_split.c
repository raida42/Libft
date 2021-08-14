/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:56:11 by raida             #+#    #+#             */
/*   Updated: 2021/04/28 14:08:46 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static char	**ft_result(char **result, const char *s, char c, size_t word)
{
	size_t	i;
	size_t	ccount;
	size_t	word_size;

	i = 0;
	while (i < word)
	{
		ccount = 0;
		word_size = 0;
		while (s[ccount] == c && s[ccount] == c)
			ccount++;
		while (s[ccount + word_size] != c && s[ccount + word_size])
			word_size++;
		result[i] = ft_substr(s, ccount, word_size);
		if (!result[i])
			return (ft_free(result));
		s = s + ccount + word_size;
		i++;
	}
	result[i] = NULL;
	return (result);
}

static size_t	ft_word(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		word++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word;

	if (!s)
		return (NULL);
	word = ft_word(s, c);
	result = (char **)malloc(sizeof(char *) * (word + 1));
	if (!result)
		return (NULL);
	return (ft_result(result, s, c, word));
}
