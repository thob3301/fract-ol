/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:37:45 by miteixei          #+#    #+#             */
/*   Updated: 2023/11/17 18:33:27 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	i = 0;
	while ((temp_s1[i] || temp_s2[i]) && n--)
	{
		if (temp_s1[i] == temp_s2[i])
			++i;
		else if (temp_s1[i] < temp_s2[i])
			return (-1);
		else if (temp_s1[i] > temp_s2[i])
			return (1);
	}
	return (0);
}
