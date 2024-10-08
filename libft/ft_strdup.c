/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:04:33 by miteixei          #+#    #+#             */
/*   Updated: 2023/10/30 18:27:45 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	str_len;

	str_len = ft_strlen(s);
	str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, str_len + 1);
	return (str);
}
