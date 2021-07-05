/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 21:10:00 by achopper          #+#    #+#             */
/*   Updated: 2020/11/20 15:37:11 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trimleft(const char *s1, const char *set)
{
	int		lefttrim;

	lefttrim = 0;
	while (*s1 && ft_strchr(set, *s1) != NULL)
	{
		lefttrim++;
		s1++;
	}
	return (lefttrim);
}

static int	trimright(const char *s1, const char *set)
{
	int		righttrim;
	int		i;

	i = ft_strlen(s1);
	i--;
	righttrim = 0;
	while (*s1)
		s1++;
	s1--;
	while (i != 0 && ft_strchr(set, *s1) != NULL)
	{
		righttrim++;
		i--;
		s1--;
	}
	return (righttrim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		left;
	int		right;
	int		len;

	if (NULL == s1)
		return (NULL);
	left = trimleft(s1, set);
	right = trimright(s1, set);
	len = ft_strlen(s1) - (left + right);
	if (len <= 0)
		return (ft_strdup(""));
	res = ft_substr(s1, left, len);
	if (res)
		return (NULL);
	return (res);
}
