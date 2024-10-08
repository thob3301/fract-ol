/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:14:17 by miteixei          #+#    #+#             */
/*   Updated: 2023/10/23 17:32:28 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_temp;

	s_temp = (unsigned char *) s;
	c = (unsigned char) c;
	while (n--)
	{
		if (*s_temp == c)
			return ((void *)s_temp);
		s_temp++;
	}
	return (NULL);
}
