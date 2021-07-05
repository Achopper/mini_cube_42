/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:03:48 by achopper          #+#    #+#             */
/*   Updated: 2021/05/05 17:54:39 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	ssize_t	i;

	i = -1;
	if (NULL == s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		res = (char *)malloc(sizeof(char) * 1);
		if (NULL == res)
			return (NULL);
		*res = '\0';
		return (res);
	}
	res = (char *)malloc(sizeof(char) * len + 1);
	if (NULL == res)
		return (NULL);
	while (start--)
		s++;
	while (++i != (ssize_t)len)
		*res++ = *s++;
	*res = '\0';
	return (res - len);
}
