/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:25:02 by achopper          #+#    #+#             */
/*   Updated: 2020/11/19 22:09:12 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*ld;
	unsigned char	*ls;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!d && !s)
		return (dst);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		ld = d + len;
		ls = s + len;
		while (len--)
			*--ld = *--ls;
	}
	return (dst);
}
