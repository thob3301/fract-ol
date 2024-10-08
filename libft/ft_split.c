/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:35:59 by miteixei          #+#    #+#             */
/*   Updated: 2024/08/22 20:38:29 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			++words;
			while (s[i] && s[i] != c)
				++i;
		}
		else
			++i;
	}
	return (words);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

static void	ft_free_all(char **array, size_t i)
{
	while (i > 0)
	{
		--i;
		free(array[i]);
	}
	free(array);
}

static char	**ft_array_insert(char const *s, char c,
		char **array, size_t words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] && s[i] == c)
			++i;
		array[j] = ft_substr(s, i, ft_word_len(&s[i], c));
		if (!array[j])
		{
			ft_free_all(array, j);
			return (NULL);
		}
		while (s[i] && s[i] != c)
			++i;
		++j;
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_words(s, c);
	array = (char **)malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = ft_array_insert(s, c, array, words);
	return (array);
}
