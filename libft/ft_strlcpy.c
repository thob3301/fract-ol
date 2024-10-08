/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:46:17 by miteixei          #+#    #+#             */
/*   Updated: 2023/10/18 18:39:29 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src || !size)
		return (ft_strlen(src));
	if (size && src)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
		return (ft_strlen(src));
	}
	return (ft_strlen(src));
}
