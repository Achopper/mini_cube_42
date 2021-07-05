/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:24:43 by achopper          #+#    #+#             */
/*   Updated: 2021/04/07 16:15:52 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_neigb(t_param *param, int i, int j)
{
	if (param->map[i][j] == '0' || param->map[i][j] == '2' || param->map[i][j]
	== 'S' || param->map[i][j] == 'W' || param->map[i][j] == 'N' ||
		param->map[i][j] == 'E')
	{
		if (!ft_strchr("120SWNE", param->map[i][j + 1]) ||
			!ft_strchr("120SWNE", param->map[i][j - 1]) ||
			!ft_strchr("120SWNE", param->map[i - 1][j]) ||
			!ft_strchr("120SWNE", param->map[i + 1][j]) ||
			!ft_strchr("120SWNE", param->map[i - 1][j - 1]) ||
			!ft_strchr("120SWNE", param->map[i - 1][j + 1]) ||
			!ft_strchr("120SWNE", param->map[i + 1][j - 1]) ||
			!ft_strchr("120SWNE", param->map[i + 1][j + 1]) ||
			param->map[i + 1][j] == '\0' || param->map[i + 1][j - 1] == '\0' ||
			param->map[i + 1][j + 1] == '\0')
			return (1);
	}
	return (0);
}

static int		check_symb_and_fill_sp(t_param *param)
{
	int i;
	int j;

	i = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (!ft_strchr(" 012SWNE", param->map[i][j]))
				return (1);
			if (check_neigb(param, i, j))
				return (1);
			j++;
		}
		while (j != param->max_map_wdt)
		{
			param->map[i][j] = ' ';
			j++;
		}
		i++;
	}
	return (0);
}

static int		check_first_and_last(t_param *param)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (param->map[0][++j])
		if (!ft_strchr(" 1", param->map[0][j]))
			return (1);
	j = -1;
	while (param->map[param->max_map_hgt][++j])
		if (!ft_strchr(" 1", param->map[param->max_map_hgt][j]))
			return (1);
	while (param->map[i])
	{
		if (!ft_strchr(" 1", param->map[i][0]) ||
			!ft_strchr(" 1", param->map[i][param->max_map_wdt - 1]))
			return (1);
		i++;
	}
	return (0);
}

void			check_map(t_param *param)
{
	if (check_first_and_last(param) || check_symb_and_fill_sp(param))
	{
		param->err = 5;
		error(param);
		exit(param->err);
	}
}
