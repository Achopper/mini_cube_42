/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:54:24 by achopper          #+#    #+#             */
/*   Updated: 2021/04/07 17:42:59 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_param_line(char *line, int i, t_param *param)
{
	if (ft_strlen(line) <= 3 || (line[i] != 'R' && line[i] != 'C' && line[i] !=
	'F' &&
		(line[i] != 'N' && line[i + 1] != 'O') &&
		(line[i] != 'S' && line[i + 1] != 'O') &&
		(line[i] != 'W' && line[i + 1] != 'E') &&
		(line[i] != 'E' && line[i + 1] != 'A') &&
		line[i] != 'S' && line[i] != ' ' && *line))
	{
		param->err = 10;
		error(param);
	}
}

void			check_res(char *line, t_param *param)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(&line[1], ' ');
	while (tmp[i])
		i++;
	free_char_array(tmp);
	if (i > 2 || param->wdt <= 10 || param->hgt <= 10)
	{
		param->err = 3;
		error(param);
	}
	while (*++line)
		if (ft_isprint(*line) && !ft_isdigit(*line) && *line != ' ')
		{
			param->err = 3;
			error(param);
		}
	if (param->hgt > param->cur_hgt || param->wdt > param->cur_wdt)
	{
		param->wdt = param->cur_wdt;
		param->hgt = param->cur_hgt;
	}
}

void			check_line(char *s, t_param *param, char **tmp)
{
	int i;
	int num;
	int in_dig;

	i = 1;
	num = 0;
	in_dig = 0;
	while (s[i])
	{
		if (ft_isprint(s[i]) && !ft_isdigit(s[i]) && s[i] != ',' && s[i] != ' ')
			param->err = 4;
		if (ft_isdigit(s[i]))
		{
			!in_dig ? num++ : 0;
			in_dig = 1;
		}
		else
			in_dig = 0;
		i++;
	}
	while (tmp[in_dig])
		in_dig++;
	in_dig > 3 || in_dig < 3 ? param->err = 4 : 0;
	num > 3 || num < 3 ? param->err = 4 : 0;
	param->err > 0 ? error(param) : 0;
}

void			check_colour(t_param *param, char **tmp)
{
	if (!tmp)
	{
		param->err = 8;
		error(param);
	}
	if (param->colour.r < 0 || param->colour.r > 255 ||
		param->colour.g < 0 || param->colour.g > 255 ||
		param->colour.b < 0 || param->colour.b > 255)
	{
		param->err = 4;
		error(param);
	}
	free_char_array(tmp);
	param->fl++;
}
