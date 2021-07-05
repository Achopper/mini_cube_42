/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:06:45 by achopper          #+#    #+#             */
/*   Updated: 2020/11/11 22:59:38 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c)
{
	int	word_count;
	int	in_word;

	word_count = 0;
	in_word = 0;
	while (*s)
	{
		if (in_word == 0 && *s != c)
		{
			in_word = 1;
			word_count++;
		}
		if (in_word == 1 && *s == c)
			in_word = 0;
		s++;
	}
	return (word_count);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static void	*everyone_want_to_be_free(char **res)
{
	int	count;

	count = 0;
	while (res[count])
	{
		free(res[count]);
		count++;
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		n_words;
	int		n_words_ret;

	if (NULL == s)
		return (NULL);
	n_words = word_counter(s, c);
	n_words_ret = word_counter(s, c);
	res = (char **)malloc(sizeof(res) * (n_words + 1));
	if (NULL == res)
		return (NULL);
	while (n_words)
	{
		while (*s == c && *s)
			s++;
		*res = ft_substr(s, 0, word_len((char *)s, c));
		if (NULL == *res)
			return (everyone_want_to_be_free(res));
		res++;
		s += word_len(s, c);
		n_words--;
	}
	*res = NULL;
	return (res - n_words_ret);
}
