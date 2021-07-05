/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_mng.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:22:00 by achopper          #+#    #+#             */
/*   Updated: 2021/04/06 15:34:48 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_err(t_param *param)
{
	param->errors[1] = "Wrong argv";
	param->errors[2] = "Wrong file extension \".cub\"";
	param->errors[3] = "Wrong res";
	param->errors[4] = "Wrong colour";
	param->errors[5] = "Something wrong in map";
	param->errors[6] = "Texture path is wrong - ";
	param->errors[7] = "Can't make snimok.bmp,sorry";
	param->errors[8] = "Malloc error";
	param->errors[9] = "Something wrong,i dont know,maybe it's player "
	"number,or maybe you forgot some parameter,or something else";
	param->errors[10] = "Wrong params, please enter valid params";
}

void		error(t_param *param)
{
	init_err(param);
	if (param->err > 0 && param->err != 6)
	{
		write(2, "Cub3d error: ", 13);
		ft_putendl_fd(param->errors[param->err], 2);
		if (param->err > 4 && param->err != 10)
			cub_end(param);
		exit(param->err);
	}
	if (param->err == 6)
	{
		write(2, "Cub3d error: ", 13);
		ft_putstr_fd(param->errors[param->err], 2);
		cub_end(param);
		return ;
	}
}
