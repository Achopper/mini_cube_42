/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:49:27 by achopper          #+#    #+#             */
/*   Updated: 2021/01/09 16:49:27 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long n)
{
	long	tmp;
	long	num;

	tmp = n;
	if (tmp < 0)
	{
		tmp *= -1;
		ft_putchar('-');
	}
	num = tmp % 10 + '0';
	tmp /= 10;
	if (tmp != 0)
		ft_putnbr(tmp);
	ft_putchar(num);
}
