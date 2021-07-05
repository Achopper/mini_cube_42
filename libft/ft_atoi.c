/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:37:45 by achopper          #+#    #+#             */
/*   Updated: 2020/11/09 15:53:13 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	val;

	sign = 1;
	val = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\t' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (ft_isdigit(*str))
	{
		if ((val > 2147483647) && sign > 0)
			return (-1);
		if ((val > 2147483647) && sign < 0)
			return (0);
		val = (val * 10) + *str - '0';
		str++;
	}
	return ((int)val * sign);
}
