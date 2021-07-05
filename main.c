/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 23:20:31 by achopper          #+#    #+#             */
/*   Updated: 2021/04/07 14:05:04 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		hooks(t_param *param)
{
	move(param);
	draw_floor_and_ceiling(param);
	ray_cast(param);
	if (param->argc == 3 && ft_strncmp("--save", param->argv[2], 7) == 0)
	{
		ft_putendl_fd("Cub3d:Make screenshot...", 1);
		get_bmp(param);
		ft_putendl_fd("Cub3d:Screenshot complete", 1);
		exit(0);
	}
	if (param->save != 1)
	{
		mlx_put_image_to_window(param->vars.mlx, param->vars.win,
								param->data.img, 0, 0);
		mlx_do_sync(param->vars.mlx);
	}
	return (0);
}

static t_data	get_text(t_param *param, char *path, char *name)
{
	t_data res;

	if (!((res.img = mlx_xpm_file_to_image(param->vars.mlx,
	path, &res.tex_w, &res.tex_h))))
	{
		param->err = 6;
		error(param);
		write(2, name, 2);
		write(2, "\n", 1);
		exit(param->err);
	}
	res.addr = mlx_get_data_addr(res.img, &res.bpp, &res.line_length,
	&res.endian);
	return (res);
}

static void		init_texs(t_param *param)
{
	param->no_text = get_text(param, param->north_t, "NO");
	free(param->north_t);
	param->so_text = get_text(param, param->south_t, "SO");
	free(param->south_t);
	param->w_text = get_text(param, param->west_t, "WE");
	free(param->west_t);
	param->e_text = get_text(param, param->east_t, "EA");
	free(param->east_t);
	param->sp_text = get_text(param, param->sprite_t, "SP");
	free(param->sprite_t);
}

static void		check_name_and_start(int argc, char **argv, int fd,
	t_param *param)
{
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) || argc < 2)
	{
		param->err = 2;
		error(param);
	}
	if ((argc == 3 && ft_strncmp(argv[2], "--save", 7) != 0) || argc > 3 ||
		argc == 1)
	{
		param->err = 1;
		error(param);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		perror("Cub3d error");
		exit(-1);
	}
	init_param(param);
	mlx_get_screen_size(param->vars.mlx, &param->cur_wdt, &param->cur_hgt);
	parse_param(fd, param);
	init_texs(param);
	param->save != 1 ? param->vars.win = mlx_new_window(param->vars.mlx,
	param->wdt, param->hgt, "cub3d") : 0;
	param->data.img = mlx_new_image(param->vars.mlx, param->wdt, param->hgt);
	param->data.addr = mlx_get_data_addr(param->data.img,
	&param->data.bpp, &param->data.line_length, &param->data.endian);
}

int				main(int argc, char **argv)
{
	int		fd;
	t_param	param;
	t_pl	pl;

	fd = 0;
	param.pl = &pl;
	param.argv = argv;
	param.argc = argc;
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7) == 0)
		param.save = 1;
	check_name_and_start(argc, argv, fd, &param);
	if (param.save != 1)
	{
		mlx_loop_hook(param.vars.mlx, hooks, &param);
		mlx_hook(param.vars.win, 2, 1L << 0, key_press, &param);
		mlx_hook(param.vars.win, 3, 1L << 1, key_rel, &param);
		mlx_hook(param.vars.win, 17, 0, close_w, &param);
		mlx_loop(param.vars.mlx);
	}
	else
	{
		mlx_loop_hook(param.saver.mlx, hooks, &param);
		mlx_loop(param.saver.mlx);
	}
	return (0);
}
