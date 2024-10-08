/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:24:07 by miteixei          #+#    #+#             */
/*   Updated: 2023/10/27 20:02:48 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((('\t' <= nptr[i]) && (nptr[i] <= '\r')) || nptr[i] == ' ')
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		++i;
	}
	if (ft_isdigit(nptr[i]))
	{
		while (ft_isdigit(nptr[i]))
		{
			result = result * 10 + (nptr[i] - '0');
			++i;
		}
	}
	return (result * sign);
}
