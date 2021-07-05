/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:31:47 by achopper          #+#    #+#             */
/*   Updated: 2020/11/09 21:06:14 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (NULL == s1 || NULL == s2)
		return (NULL);
	res = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (NULL == res)
		return (NULL);
	ft_memcpy(res, s1, ft_strlen(s1));
	res += ft_strlen(s1);
	ft_memcpy(res, s2, ft_strlen(s2));
	res += ft_strlen(s2);
	*res = '\0';
	return (res - (ft_strlen(s1) + ft_strlen(s2)));
}
