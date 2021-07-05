/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 21:03:10 by achopper          #+#    #+#             */
/*   Updated: 2021/05/04 21:01:28 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	doo_loo(char *res, int len, unsigned long num, int base)
{
	while (len > 0)
	{
		res[len - 1] = num % base;
		if (num % base > 9)
			res[len - 1] += 97 - 10;
		else
			res[len - 1] += 48;
		num /= base;
		len--;
	}
}

char	*ft_itoa_base(unsigned long num, int base)
{
	char				*res;
	unsigned long		tmp;
	int					len;

	len = 0;
	tmp = num;
	if (tmp == 0)
		len = 1;
	while (tmp > 0)
	{
		tmp /= base;
		len++;
	}
	res = (char *)malloc(sizeof(char ) * len + 1);
	if (NULL == res)
		return (NULL);
	*(res + len) = '\0';
	doo_loo(res, len, num, base);
	return (res);
}
