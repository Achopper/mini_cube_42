/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_maker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:08:45 by achopper          #+#    #+#             */
/*   Updated: 2021/03/31 17:14:57 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_int_in_ar(unsigned char *sr, unsigned int x)
{
	sr[0] = (unsigned char)x;
	sr[1] = (unsigned char)(x >> 8);
	sr[2] = (unsigned char)(x >> 16);
	sr[3] = (unsigned char)(x >> 24);
}

static void	make_bmp_header(t_param *param, int fd)
{
	unsigned char	bmp[54];
	unsigned int	size;

	ft_bzero(bmp, 54);
	size = 54 + (4 * (param->wdt * param->hgt));
	bmp[0] = 'B';
	bmp[1] = 'M';
	put_int_in_ar(bmp + 2, size);
	bmp[10] = 54;
	bmp[14] = 40;
	put_int_in_ar(bmp + 18, param->wdt);
	put_int_in_ar(bmp + 22, param->hgt);
	bmp[26] = 1;
	bmp[28] = 32;
	write(fd, bmp, 54);
}

void		get_bmp(t_param *param)
{
	int				fd;
	int				i;
	int				j;
	unsigned int	col;

	if ((fd = open("snimok.bmp", O_RDWR | O_CREAT, 0777)) < 0)
	{
		param->err = 7;
		error(param);
	}
	make_bmp_header(param, fd);
	i = param->hgt - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < param->wdt)
		{
			col = *(unsigned int*)(param->data.addr + (i *
			param->data.line_length + j * (param->data.bpp / 8)));
			write(fd, &col, 4);
			j++;
		}
		i--;
	}
	close(fd);
}
