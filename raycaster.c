/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:28:41 by achopper          #+#    #+#             */
/*   Updated: 2021/03/31 17:30:12 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_floor_and_ceiling(t_param *param)
{
	int floor;
	int ceiling;
	int x;

	x = 0;
	while (x < param->wdt)
	{
		ceiling = 0;
		while (ceiling < param->hgt / 2)
		{
			my_pixel_put(&param->data, x, ceiling, param->ceiling_c);
			ceiling++;
		}
		floor = param->hgt / 2;
		while (floor < param->hgt - 1)
		{
			my_pixel_put(&param->data, x, floor, param->floor_c);
			floor++;
		}
		x++;
	}
}

static void	get_line_data(t_param *param, float *ang)
{
	param->w.line_h = (int)((float)param->hgt / param->w.dist * ZOOM);
	param->w.draw_s = (-param->w.line_h / 2) + (param->hgt / 2);
	param->w.draw_s < 0 ? param->w.draw_s = 0 : 0;
	param->w.draw_e = (param->w.line_h / 2) + (param->hgt / 2);
	param->w.draw_e >= param->hgt ? param->w.draw_e = param->hgt - 1 : 0;
	fix_ang(ang);
	if (((int)param->w.y % ZOOM == 0 || (int)param->w.y % ZOOM == ZOOM -
	1) && ((int)param->w.x % ZOOM != 0 || (int)param->w.x % ZOOM != ZOOM -
	1))
	{
		param->w.tex_x = (param->w.x / ZOOM) - floorf(param->w.x / ZOOM);
		if (*ang < PI)
			param->cur_text = param->so_text;
		else
			param->cur_text = param->no_text;
	}
	else
	{
		param->w.tex_x = (param->w.y / ZOOM) - floorf(param->w.y / ZOOM);
		if (*ang > 3 * PI / 2 || *ang < PI / 2)
			param->cur_text = param->e_text;
		else
			param->cur_text = param->w_text;
	}
}

static void	draw_line(t_param *param)
{
	float tmp;

	tmp = param->ray.start;
	get_line_data(param, &tmp);
	param->w.tex_x *= (float)param->cur_text.tex_w;
	param->w.step = (float)param->cur_text.tex_h / (float)param->w.line_h;
	param->w.tex_pos = ((float)param->w.draw_s - (float)param->hgt / 2 + (float)
			param->w.line_h / 2) * param->w.step;
	while (param->w.draw_s < param->w.draw_e)
	{
		if (((int)param->w.y % ZOOM == 0 && (int)param->w.x % ZOOM == 0)
		|| ((int)param->w.y % ZOOM == 0 && (int)param->w.x % ZOOM == ZOOM - 1)
		|| ((int)param->w.y % ZOOM == ZOOM - 1 && (int)param->w.x % ZOOM == 0)
		|| ((int)param->w.y % ZOOM == ZOOM - 1 && (int)param->w.x % ZOOM ==
		ZOOM - 1))
			param->wall_col = 0x606060;
		else
			param->wall_col = *(unsigned int *)(param->cur_text.addr + (
					(int)param->w.tex_pos * param->cur_text.line_length + (int)
					param->w.tex_x * (param->cur_text.bpp / 8)));
		my_pixel_put(&param->data, param->ray.index, param->w.draw_s,
		param->wall_col);
		param->w.draw_s++;
		param->w.tex_pos += param->w.step;
	}
}

static void	do_raycast(t_param *param)
{
	while (param->ray.start < param->ray.end)
	{
		param->ray.x = param->pl->x;
		param->ray.y = param->pl->y;
		while (param->map[(int)param->ray.y / ZOOM][(int)param->ray.x / ZOOM]
		!= '1')
		{
			param->ray.dx = cosf(param->ray.start);
			param->ray.dy = sinf(param->ray.start);
			param->ray.x += param->ray.dx;
			param->ray.y += param->ray.dy;
		}
		param->w.x = param->ray.x;
		param->w.y = param->ray.y;
		param->w.dist = sqrtf(powf((param->pl->x - param->w.x), 2) +
		powf((param->pl->y - param->w.y), 2));
		param->sp->buf[param->ray.index] = param->w.dist;
		param->w.dist = param->w.dist * cosf(param->pl->dir - param->ray.start);
		draw_line(param);
		param->ray.index++;
		param->ray.start += (PI / 2) / (float)param->wdt;
	}
	draw_sprite(param, param->sp->buf);
	free(param->sp->buf);
}

void		ray_cast(t_param *param)
{
	ft_bzero(&param->ray, sizeof(t_ray));
	if (!(param->sp->buf = (float*)calloc(param->wdt + 1, sizeof(float))))
	{
		param->err = 8;
		error(param);
	}
	param->ray.start = param->pl->dir - (PI / 4);
	param->ray.end = param->pl->dir + (PI / 4);
	do_raycast(param);
}
