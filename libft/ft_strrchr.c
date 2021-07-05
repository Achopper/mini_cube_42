/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:25:27 by achopper          #+#    #+#             */
/*   Updated: 2020/11/02 20:25:29 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = (int)ft_strlen(s);
	ptr = (char *)s;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (&ptr[i]);
		i--;
	}
	return (NULL);
}
