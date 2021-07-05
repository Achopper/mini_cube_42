/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:27:29 by achopper          #+#    #+#             */
/*   Updated: 2021/05/04 21:20:06 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;
	size_t	j;

	i = 0;
	n_len = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	if (n_len > ft_strlen(haystack))
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] && i + j < len)
		{
			if (needle[j] != haystack[i + j])
				break ;
			j++;
		}
		if (j == n_len)
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
