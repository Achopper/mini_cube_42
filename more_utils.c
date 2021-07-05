/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:17:41 by achopper          #+#    #+#             */
/*   Updated: 2021/04/07 14:07:21 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_param(t_param *param)
{
	param->vars.mlx = mlx_init();
	param->saver.mlx = mlx_init();
	param->fl = 0;
	param->wdt = 0;
	param->cur_wdt = 0;
	param->hgt = 0;
	param->cur_hgt = 0;
	param->err = 0;
	param->iter = 0;
	param->head = NULL;
	param->max_map_wdt = 0;
	param->max_map_hgt = 0;
	param->north_t = NULL;
	param->south_t = NULL;
	param->west_t = NULL;
	param->east_t = NULL;
	param->sprite_t = NULL;
	param->floor_c = -1;
	param->ceiling_c = -1;
	param->map = NULL;
	param->sp = NULL;
}

float	*fix_ang(float *ang)
{
	if (*ang < 0)
		*ang += 2 * PI;
	if (*ang > 2 * PI)
		*ang -= 2 * PI;
	return (ang);
}

float	ang_diff(float a1, float a2)
{
	float res;

	res = a1 - a2;
	if (res < 0)
		res += 2 * PI;
	else if (res > 2 * PI)
		res -= 2 * PI;
	if (res > PI)
		res = 2 * PI - res;
	return (res);
}

int		close_w(t_param *param)
{
	cub_end(param);
	exit(0);
}

int		check_max_wdt(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		i++;
	}
	return (i);
}
