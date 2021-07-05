/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:27:47 by achopper          #+#    #+#             */
/*   Updated: 2020/11/09 22:56:23 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	int			size_s;

	i = 0;
	size_s = 0;
	if (src == NULL)
		return (0);
	while (src[size_s])
		size_s++;
	if (dstsize == 0)
		return (size_s);
	while (*src != '\0' && ((dstsize - 1) > i))
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (size_s);
}
