/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:59:33 by achopper          #+#    #+#             */
/*   Updated: 2021/03/31 17:20:27 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				cub_end(t_param *param)
{
	free_char_array(param->map);
	free(param->sp);
}

void				free_list(t_list *b_list)
{
	t_list *tmp;

	while (b_list)
	{
		tmp = b_list;
		b_list = b_list->next;
		free(tmp->content);
		free(tmp);
	}
}

void				ins_sort(t_sprite *src, size_t len)
{
	size_t		i;
	size_t		j;
	t_sprite	tmp;

	i = 1;
	while (i < len)
	{
		j = i;
		while (j > 0 && src[j - 1].dist < src[j].dist)
		{
			tmp = src[j - 1];
			src[j - 1] = src[j];
			src[j] = tmp;
			j--;
		}
		i++;
	}
}

int					create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void				my_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
