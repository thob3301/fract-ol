/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:47:13 by miteixei          #+#    #+#             */
/*   Updated: 2023/11/19 21:46:57 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (*str == set[i])
			return (1);
		else if (set[i])
			++i;
	}
	return (0);
}

static size_t	ft_strstrt(char const *str, char const *set)
{
	size_t	start;

	start = 0;
	while (str[start])
	{
		if (ft_inset(&str[start], set))
			++start;
		else
			break ;
	}
	return (start);
}

static size_t	ft_strend(char const *str, char const *set, size_t start)
{
	size_t	end;

	end = ft_strlen(str);
	while (start < end)
	{
		if (ft_inset(&str[end - 1], set))
			--end;
		else
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ret_str;

	start = 0;
	if (!set || !s1)
		return (NULL);
	start = ft_strstrt(s1, set);
	end = ft_strend(s1, set, start);
	ret_str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!ret_str)
		return (NULL);
	ft_strlcpy(ret_str, &s1[start], (end - start + 1));
	return (ret_str);
}
