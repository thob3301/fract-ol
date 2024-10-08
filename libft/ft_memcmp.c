/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:39:11 by miteixei          #+#    #+#             */
/*   Updated: 2023/10/25 14:54:20 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	if (n >= 0)
	{
		while (n--)
		{
			if (temp_s1[i] == temp_s2[i])
				++i;
			else if (temp_s1[i] < temp_s2[i])
				return (temp_s1[i] - temp_s2[i]);
			else if (temp_s1[i] > temp_s2[i])
				return (temp_s1[i] - temp_s2[i]);
		}
	}
	return (0);
}
