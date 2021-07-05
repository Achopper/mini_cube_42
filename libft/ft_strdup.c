/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:10:01 by achopper          #+#    #+#             */
/*   Updated: 2020/11/07 14:41:14 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1);
	res = (char *)malloc(sizeof(*res) * (len + 1));
	if (NULL == res)
		return (NULL);
	while (*s1)
		*res++ = *s1++;
	*res = '\0';
	res -= len;
	return (res);
}
