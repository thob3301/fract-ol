/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:15:02 by miteixei          #+#    #+#             */
/*   Updated: 2023/11/19 18:22:27 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (!little_len)
		return ((char *)big);
	if (!len)
		return (NULL);
	while ((i < len) && big[i])
	{
		if (!ft_strncmp(&big[i], little, little_len)
			&& ((i + little_len) <= len))
			return ((char *)&big[i]);
		++i;
	}
	return (NULL);
}
