/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:15:42 by achopper          #+#    #+#             */
/*   Updated: 2020/11/16 20:13:34 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	tmp;
	int		num;

	tmp = n;
	if (tmp < 0)
	{
		tmp *= -1;
		ft_putchar_fd('-', fd);
	}
	num = tmp % 10 + '0';
	tmp /= 10;
	if (tmp != 0)
		ft_putnbr_fd(tmp, fd);
	ft_putchar_fd(num, fd);
}
