/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:18:01 by achopper          #+#    #+#             */
/*   Updated: 2021/05/05 18:36:10 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_save(char **saved_line)
{
	free(*saved_line);
	*saved_line = NULL;
	return ;
}

void	get_line(char *buf, char **saved_line)
{
	char			*tmp;

	if (!*saved_line)
		*saved_line = ft_strdup(buf);
	else
	{
		tmp = *saved_line;
		*saved_line = ft_strjoin(*saved_line, buf);
		free(tmp);
	}
	return ;
}

int	get_n_line(char **saved_line, char **line)
{
	char			*tmp;
	char			*p_n;

	if (!*saved_line)
	{
		*line = ft_strdup("");
		if (NULL == *line)
			return (-1);
		return (0);
	}
	p_n = ft_strchr(*saved_line, '\n');
	if (p_n)
	{
		*p_n = '\0';
		*line = ft_strdup(*saved_line);
		if (NULL == *line)
			return (-1);
		tmp = *saved_line;
		*saved_line = ft_strdup(++p_n);
		if (NULL == *saved_line)
			return (-1);
		free(tmp);
		return (1);
	}
	*line = ft_strdup(*saved_line);
	if (NULL == *saved_line)
		return (-1);
	free_save(saved_line);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*saved_line[5000];
	char			*buf;
	int				r_bytes;

	if (fd < 0 || !(line) || BUFFER_SIZE < 1)
		return (-1);
	r_bytes = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (NULL == buf)
		return (-1);
	while (r_bytes)
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		buf[r_bytes] = '\0';
		get_line(buf, &saved_line[fd]);
		if (!saved_line[fd])
			return (-1);
		if (ft_strchr(saved_line[fd], '\n'))
			break ;
	}
	free(buf);
	if (r_bytes == -1)
	{
		if (saved_line[fd])
			free_save(&saved_line[fd]);
		return (-1);
	}
	return (get_n_line(&saved_line[fd], line));
}
