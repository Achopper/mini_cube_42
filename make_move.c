/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:46:39 by achopper          #+#    #+#             */
/*   Updated: 2021/04/06 18:29:13 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			up_down_handle(t_param *param)
{
	if (param->mv.up == 1)
	{
		if (param->map[(int)param->pl->y / ZOOM][(int)(param->pl->x +
		param->pl->dx) / ZOOM] != '1' && param->map[(int)param->pl->y /
		ZOOM][(int)(param->pl->x + 3 * param->pl->dx) / ZOOM] != '2')
			param->pl->x += param->pl->dx;
		if (param->map[(int)(param->pl->y + param->pl->dy) / ZOOM][(int)
		param->pl->x / ZOOM] != '1' && param->map[(int)(param->pl->y + 2 *
		param->pl->dy) / ZOOM][(int)param->pl->x / ZOOM] != '2')
			param->pl->y += param->pl->dy;
	}
	if (param->mv.down == 1)
	{
		if (param->map[(int)param->pl->y / ZOOM][(int)(param->pl->x -
		param->pl->dx) / ZOOM] != '1' && param->map[(int)param->pl->y /
		ZOOM][(int)(param->pl->x - 3 * param->pl->dx) / ZOOM] != '2')
			param->pl->x -= param->pl->dx;
		if (param->map[(int)(param->pl->y - param->pl->dy) / ZOOM][(int)
		param->pl->x / ZOOM] != '1' && param->map[(int)(param->pl->y - 2 *
		param->pl->dy) / ZOOM][(int)param->pl->x / ZOOM] != '2')
			param->pl->y -= param->pl->dy;
	}
}

static void			look_left_right_handle(t_param *param)
{
	if (param->mv.look_left == 1)
	{
		param->pl->dir -= 0.1f;
		if (param->pl->dir < 0)
			param->pl->dir += 2 * PI;
		param->pl->dx = cosf(param->pl->dir) * SPEED;
		param->pl->dy = sinf(param->pl->dir) * SPEED;
	}
	if (param->mv.look_right == 1)
	{
		param->pl->dir += 0.1f;
		if (param->pl->dir > 2 * PI)
			param->pl->dir -= 2 * PI;
		param->pl->dx = cosf(param->pl->dir) * SPEED;
		param->pl->dy = sinf(param->pl->dir) * SPEED;
	}
}

void				move(t_param *param)
{
	if (param->mv.left == 1)
	{
		if (param->map[(int)param->pl->y / ZOOM][(int)(param->pl->x +
		param->pl->dy) / ZOOM] != '1' && param->map[(int)param->pl->y /
		ZOOM][(int)(param->pl->x + 3 * param->pl->dy) / ZOOM] != '2')
			param->pl->x += param->pl->dy;
		if (param->map[(int)(param->pl->y - param->pl->dx) / ZOOM][(int)
		param->pl->x / ZOOM] != '1' && param->map[(int)(param->pl->y - 2 *
		param->pl->dx) / ZOOM][(int)param->pl->x / ZOOM] != '2')
			param->pl->y -= param->pl->dx;
	}
	if (param->mv.right == 1)
	{
		if (param->map[(int)param->pl->y / ZOOM][(int)(param->pl->x -
		param->pl->dy) / ZOOM] != '1' && param->map[(int)param->pl->y /
		ZOOM][(int)(param->pl->x - 3 * param->pl->dy) / ZOOM] != '2')
			param->pl->x -= param->pl->dy;
		if (param->map[(int)(param->pl->y + param->pl->dx) / ZOOM][(int)
		param->pl->x / ZOOM] != '1' && param->map[(int)(param->pl->y + 2 *
		param->pl->dx) / ZOOM][(int)param->pl->x / ZOOM] != '2')
			param->pl->y += param->pl->dx;
	}
	up_down_handle(param);
	look_left_right_handle(param);
}

int					key_press(int keycode, t_param *param)
{
	if (keycode == ESC)
	{
		cub_end(param);
		exit(0);
	}
	keycode == A ? param->mv.left = 1 : keycode;
	keycode == D ? param->mv.right = 1 : keycode;
	keycode == W ? param->mv.up = 1 : keycode;
	keycode == S ? param->mv.down = 1 : keycode;
	keycode == LEFT ? param->mv.look_left = 1 : keycode;
	keycode == RIGHT ? param->mv.look_right = 1 : keycode;
	return (0);
}

int					key_rel(int keycode, t_param *param)
{
	keycode == A ? param->mv.left = 0 : keycode;
	keycode == D ? param->mv.right = 0 : keycode;
	keycode == W ? param->mv.up = 0 : keycode;
	keycode == S ? param->mv.down = 0 : keycode;
	keycode == LEFT ? param->mv.look_left = 0 : keycode;
	keycode == RIGHT ? param->mv.look_right = 0 : keycode;
	return (0);
}
