/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:01:15 by achopper          #+#    #+#             */
/*   Updated: 2021/04/07 17:05:45 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		get_p_pos(t_param *param, const int *i, const int *j, int p_num)
{
	if (param->map[*i][*j] == 'N' || param->map[*i][*j] == 'S' ||
		param->map[*i][*j] == 'W' || param->map[*i][*j] == 'E')
	{
		if (param->map[*i][*j] == 'N')
			param->pl->dir = (3 * PI) / 2;
		if (param->map[*i][*j] == 'S')
			param->pl->dir = PI / 2;
		if (param->map[*i][*j] == 'W')
			param->pl->dir = PI;
		if (param->map[*i][*j] == 'E')
			param->pl->dir = 0;
		param->pl->y = (float)*i * ZOOM + (float)ZOOM / 2;
		param->pl->x = (float)*j * ZOOM + (float)ZOOM / 2;
		p_num++;
		param->pl->dx = cosf(param->pl->dir) * SPEED;
		param->pl->dy = sinf(param->pl->dir) * SPEED;
	}
	return (p_num);
}

static void		get_map(t_list **list, int size, t_param *param)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *list;
	if (!(param->map = ft_calloc(size + 1, sizeof(char *))))
	{
		param->err = 8;
		error(param);
	}
	while (tmp)
	{
		if (!(param->map[i] = ft_calloc(param->max_map_wdt, sizeof(char
		*))))
		{
			param->err = 8;
			error(param);
		}
		ft_memcpy(param->map[i], tmp->content, ft_strlen(tmp->content));
		tmp = tmp->next;
		i++;
	}
	free_list(tmp);
}

static void		get_p_coor(t_param *param)
{
	int p_num;
	int i;
	int j;

	i = 0;
	p_num = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			p_num = get_p_pos(param, &i, &j, p_num);
			if (param->map[i][j] == '2')
				param->sprite_num++;
			j++;
		}
		i++;
	}
	if (p_num > 1 || p_num == 0)
	{
		param->err = 9;
		error(param);
	}
	param->max_map_hgt = i - 1;
}

static void		get_spr_coor(t_param *param)
{
	int i;
	int j;

	if (!(param->sp = (t_sprite*)calloc(param->sprite_num, sizeof(t_sprite))))
	{
		param->err = 8;
		error(param);
	}
	i = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == '2')
			{
				param->sp[param->iter].y = (float)i * ZOOM + (float)ZOOM / 2;
				param->sp[param->iter].x = (float)j * ZOOM + (float)ZOOM / 2;
				param->iter++;
			}
			j++;
		}
		i++;
	}
}

void			parse_map(int fd, t_param *param)
{
	char	*line;
	int		tmp;

	while (get_next_line(fd, &line))
	{
		if (param->ceiling_c >= 0 && param->floor_c >= 0 && param->sprite_t &&
			param->east_t && param->west_t && param->south_t &&
			param->north_t && param->hgt && param->wdt)
		{
			ft_lstadd_back(&param->head, ft_lstnew(line));
			tmp = check_max_wdt(line);
			param->max_map_wdt < tmp ? param->max_map_wdt = tmp : 0;
		}
//		if (!*line)
//			free(line);
	}
	ft_lstadd_back(&param->head, ft_lstnew(line));
	tmp = check_max_wdt(line);
	param->max_map_wdt < tmp ? param->max_map_wdt = tmp : 0;
	get_map(&param->head, ft_lstsize(param->head), param);
	get_p_coor(param);
	get_spr_coor(param);
	free_list(param->head);
	close(fd);
}
