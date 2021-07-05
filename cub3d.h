/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achopper <achopper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:55:43 by achopper          #+#    #+#             */
/*   Updated: 2021/04/07 14:31:08 by achopper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <limits.h>
# include <math.h>
# include <errno.h>

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define PI 3.14159265359f
# define RA 0.0174533f
# define ZOOM 100
# define SPEED 20

typedef struct		s_colour{
	int				r;
	int				g;
	int				b;
}					t_colour;

typedef struct		s_move {
	int				left;
	int				right;
	int				up;
	int				down;
	int				look_left;
	int				look_right;
}					t_mv;

typedef struct		s_ray {
	float			x;
	float			y;
	float			dx;
	float			dy;
	int				index;
	float			start;
	float			end;
}					t_ray;

typedef struct		s_vars {
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_pl {
	float			x;
	float			y;
	float			dir;
	float			dx;
	float			dy;
	float			start_ang;
}					t_pl;

typedef struct		s_data {
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				tex_h;
	int				tex_w;
}					t_data;

typedef struct		s_wall {
	float			x;
	float			y;
	float			tex_x;
	float			tex_pos;
	float			step;
	int				line_h;
	int				draw_s;
	int				draw_e;
	float			dist;
}					t_wall;

typedef struct		s_sprite {
	float			x;
	float			y;
	float			curr_a;
	float			dist;
	float			dir;
	float			ang_r;
	float			step;
	float			*buf;
	int				sp_hgt;
	int				sp_wdt;
	int				rx;
	int				y_o;
	int				st_p;
}					t_sprite;

typedef struct		s_param {
	char			**argv;
	int				argc;
	int				save;
	char			*errors[15];
	int				err;
	int				cur_wdt;
	int				cur_hgt;
	int				wdt;
	int				hgt;
	int				iter;
	char			*north_t;
	char			*south_t;
	char			*west_t;
	char			*east_t;
	char			*sprite_t;
	int				floor_c;
	int				ceiling_c;
	char			**map;
	int				max_map_wdt;
	int				max_map_hgt;
	int 			fl;
	unsigned int	wall_col;
	unsigned int	sp_col;
	size_t			sprite_num;
	t_wall			w;
	t_pl			*pl;
	t_data			data;
	t_vars			saver;
	t_vars			vars;
	t_mv			mv;
	t_ray			ray;
	t_colour		colour;
	t_data			no_text;
	t_data			so_text;
	t_data			w_text;
	t_data			e_text;
	t_data			sp_text;
	t_data			cur_text;
	t_sprite		*sp;
	t_list			*head;

}					t_param;

void				free_list(t_list *b_list);
void				parse_param(int fd, t_param *param);
void				parse_map(int fd, t_param *param);
int					create_trgb(int t, int r, int g, int b);
void				cub_end(t_param *param);
void				my_pixel_put(t_data *data, int x, int y, unsigned int
color);
void				init_param(t_param *param);
void				check_param_line(char *line, int i, t_param *param);
void				check_res(char *line, t_param *param);
void				check_colour(t_param *param, char **tmp);
void				check_line(char *s, t_param *param, char **tmp);
void				check_map(t_param *param);
int					check_max_wdt(char *line);
int					key_rel(int keycode, t_param *param);
int					key_press(int keycode, t_param *param);
int					close_w(t_param *param);
void				move(t_param *param);
void				ins_sort(t_sprite *data, size_t len);
void				ray_cast(t_param *param);
void				draw_floor_and_ceiling(t_param *param);
void				draw_sprite(t_param *param, const float *ar);
float				ang_diff(float a1, float a2);
float				*fix_ang(float *ang);
void				get_bmp(t_param *param);
void				error(t_param *param);

#endif
