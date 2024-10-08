/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:12:49 by miteixei          #+#    #+#             */
/*   Updated: 2023/10/10 15:04:27 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	char	*s_temp;

	s_temp = (char *) s;
	c = (char) c;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (*s_temp == c)
			return (s_temp);
		s_temp++;
	}
	return (NULL);
}
