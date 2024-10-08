/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:46:17 by miteixei          #+#    #+#             */
/*   Updated: 2023/11/03 19:57:30 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;

	str = NULL;
	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (!len || !str_len || start > str_len - 1)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
		return (str);
	}
	if (len > str_len - start)
		len = str_len - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (str);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
