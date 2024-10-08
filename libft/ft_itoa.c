/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miteixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:57:56 by miteixei          #+#    #+#             */
/*   Updated: 2023/11/21 19:10:44 by miteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ilen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		++len;
	while (n / 10)
	{
		++len;
		n /= 10;
	}
	return (++len);
}

static char	*ft_dtostr(char *nums, int n, int len)
{
	if (n == -2147483648)
	{
		ft_strlcpy(nums, "-2147483648", 12);
		return (nums);
	}
	if (n < 0)
	{
		nums[0] = '-';
		n *= -1;
	}
	nums[len] = '\0';
	while (n / 10)
	{
		nums[--len] = (n % 10) + '0';
		n /= 10;
	}
	nums[--len] = (n % 10) + '0';
	return (nums);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		ilen;

	ilen = ft_ilen(n);
	str = (char *)malloc((ilen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_dtostr(str, n, ilen);
	return (str);
}
