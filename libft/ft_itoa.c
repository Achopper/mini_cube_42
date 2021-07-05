/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:28:29 by achopper          #+#    #+#             */
/*   Updated: 2021/05/04 20:48:04 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_symbols(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		sign;
	long	tmp;

	sign = 0;
	tmp = n;
	len = count_symbols(n);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (NULL == res)
		return (NULL);
	if (n < 0)
	{
		tmp *= -1;
		sign = 1;
	}
	res[len] = '\0';
	while (len--)
	{
		res[len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	if (sign == 1)
		res[0] = '-';
	return (res);
}
