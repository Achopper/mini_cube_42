/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:50:41 by achopper          #+#    #+#             */
/*   Updated: 2021/04/07 17:29:05 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_res(char *line, t_param *param, int i)
{
	if ((line[i] == 'R' && line[i + 1] == ' '))
	{
		while (!ft_isdigit(line[i]) && line[i] != '\0')
			i++;
		while (ft_isdigit(line[i]))
		{
			param->wdt = param->wdt * 10 + (line[i] - '0');
			i++;
		}
		while (!ft_isdigit(line[i]))
			i++;
		while (ft_isdigit(line[i]))
		{
			param->hgt = param->hgt * 10 + (line[i] - '0');
			i++;
		}
		if (!param->hgt || !param->wdt)
		{
			param->err = 3;
			error(param);
		}
		check_res(line, param);
		param->fl++;
	}
}

static char		*get_path(char *line, int j, t_param *param)
{
	char	*res;
	size_t	i;

	i = 0;
	while (ft_isspace(line[j]) && line[j] != '\0')
		j++;
	if (!(res = ft_substr(line, j, ft_strlen(line) - j)))
	{
		param->err = 8;
		error(param);
	}
	if (!res)
	{
		param->err = 6;
		error(param);
	}
	while (ft_isprint(res[i]) && res[i] != ' ')
		i++;
	if (ft_strlen(res) > i)
		res[i] = '\0';
	param->fl++;
	return (res);
}

static void		get_text_paths(char *line, t_param *param, int i)
{
	int j;

	j = 2;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		param->north_t = get_path(line, j, param);
	if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		param->south_t = get_path(line, j, param);
	if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		param->west_t = get_path(line, j, param);
	if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		param->east_t = get_path(line, j, param);
	if (line[i] == 'S' && line[i + 1] == ' ')
		param->sprite_t = get_path(line, j, param);
}

static void		get_f_and_c_colour(char *line, t_param *param, int i)
{
	char **tmp;

	!ft_isdigit(line[ft_strlen(line) - 1]) ? param->err = 4 : 0;
	if (line[i] == 'F' && line[i + 1] == ' ')
	{
		tmp = ft_split(&line[1], ',');
		check_line(line, param, tmp);
		param->colour.r = ft_atoi(tmp[i]);
		param->colour.g = ft_atoi(tmp[++i]);
		param->colour.b = ft_atoi(tmp[++i]);
		param->floor_c = create_trgb(0, param->colour.r, param->colour.g,
		param->colour.b);
		check_colour(param, tmp);
	}
	if (line[i] == 'C' && line[i + 1] == ' ')
	{
		tmp = ft_split(&line[1], ',');
		check_line(line, param, tmp);
		param->colour.r = ft_atoi(tmp[i]);
		param->colour.g = ft_atoi(tmp[++i]);
		param->colour.b = ft_atoi(tmp[++i]);
		param->ceiling_c = create_trgb(0, param->colour.r, param->colour.g,
		param->colour.b);
		check_colour(param, tmp);
	}
}

void			parse_param(int fd, t_param *param)
{
	char	*line;
	int		i;

	while (get_next_line(fd, &line))
	{
		i = 0;
		check_param_line(line, i, param);
		get_res(line, param, i);
		get_text_paths(line, param, i);
		if (line[i] == 'C' || line[i] == 'F')
			get_f_and_c_colour(line, param, i);
		free(line);
		if (param->ceiling_c >= 0 && param->floor_c >= 0 && param->sprite_t &&
			param->east_t && param->west_t && param->south_t && param->north_t
			&& param->hgt && param->wdt)
			break ;
	}
	if (param->fl > 8)
	{
		param->err = 10;
		error(param);
	}
	parse_map(fd, param);
	check_map(param);
	close(fd);
}
