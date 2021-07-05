/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritecaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:31:23 by achopper          #+#    #+#             */
/*   Updated: 2021/04/06 19:33:42 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_sprite_data(t_param *param)
{
	size_t	i;
	float	dx;

	i = 0;
	while (i < param->sprite_num)
	{
		param->sp[i].dist = sqrtf(powf((param->pl->x -
		param->sp[i].x), 2) + powf((param->pl->y - param->sp[i].y), 2));
		param->sp[i].sp_hgt = (int)((float)param->hgt / param->sp[i].dist *
		ZOOM);
		param->sp[i].sp_wdt = (int)((float)param->wdt / param->sp[i].dist *
		ZOOM);
		dx = param->sp[i].x - param->pl->x;
		param->sp[i].dir = acosf(dx / param->sp[i].dist);
		if (param->pl->y > param->sp[i].y)
			param->sp[i].dir = 2 * PI - param->sp[i].dir;
		fix_ang(&param->sp[i].dir);
		i++;
	}
	ins_sort(param->sp, param->sprite_num);
}

static void	get_more_sprite_data(t_param *param, size_t i)
{
	param->sp[i].ang_r = 90 * RA * ((float)param->sp[i].sp_wdt / (float)
	param->wdt);
	param->sp[i].step = (float)param->sp_text.tex_h / (float)
	param->sp[i].sp_hgt;
	param->sp[i].y_o = 0;
	if (param->sp[i].sp_hgt > param->hgt)
	{
		param->sp[i].y_o = (param->hgt - param->sp[i].sp_hgt) / 90;
		param->sp[i].sp_hgt = param->hgt;
	}
}

static void	get_little_bit_more_data(t_param *param, size_t i)
{
	param->pl->start_ang = param->pl->dir - 45 * RA;
	fix_ang(&param->pl->start_ang);
	param->sp[i].curr_a = param->sp[i].dir - param->pl->start_ang;
	fix_ang(&param->sp[i].curr_a);
	if (param->sp[i].curr_a > PI)
		param->sp[i].curr_a -= 2 * PI;
	param->sp[i].st_p = (int)(param->sp[i].curr_a / RA * ((float)
			param->wdt / 90));
}

static void	finally_do_spite(t_param *param, size_t i, int x, const float *ar)
{
	while (x < param->sp[i].sp_wdt * 0.5)
	{
		if (param->sp[i].st_p + x < 0 || param->sp[i].st_p + x > param->wdt)
		{
			x++;
			continue ;
		}
		param->sp[i].rx = (int)(param->sp_text.tex_w * (x + 0.5 *
				param->sp[i].sp_wdt) / param->sp[i].sp_wdt);
		param->iter = 0;
		while (param->iter < param->sp[i].sp_hgt)
		{
			param->sp_col = *(unsigned int*)(param->sp_text.addr + (int)((
			(float)param->sp[i].y_o + (float)param->iter) * param->sp[i].step)
			* param->sp_text.line_length + (int)(param->sp[i].rx *
			param->sp_text.bpp / 8));
			if (param->sp_col != *(unsigned int*)param->sp_text.addr &&
				ar[param->sp[i].st_p + x] > param->sp[i].dist)
				my_pixel_put(&param->data, (int)(param->sp[i].st_p + x),
				(int)(param->hgt - param->sp[i].sp_hgt) / 2 + param->iter,
				param->sp_col);
			param->iter++;
		}
		x++;
	}
}

void		draw_sprite(t_param *param, const float *ar)
{
	size_t	i;
	int		x;

	get_sprite_data(param);
	i = 0;
	while (i < param->sprite_num)
	{
		get_more_sprite_data(param, i);
		if (ang_diff(param->pl->dir, param->sp[i].dir) < 45 * RA +
		param->sp[i].ang_r * 0.5)
		{
			get_little_bit_more_data(param, i);
			x = (int)(param->sp[i].sp_wdt * (-0.5));
			finally_do_spite(param, i, x, ar);
		}
		i++;
	}
}
