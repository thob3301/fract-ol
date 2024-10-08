/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:40:33 by miteixei          #+#    #+#             */
/*   Updated: 2023/10/23 16:34:38 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*s_temp;

	s_temp = (char *) s;
	c = (char) c;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (s_temp[len] == c)
			return (&s_temp[len]);
	}
	return (NULL);
}
