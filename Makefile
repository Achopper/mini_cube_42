# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achopper <achopper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 20:53:49 by achopper          #+#    #+#              #
#    Updated: 2021/04/06 16:44:43 by achopper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
CC		= gcc
FLAGS	=  -Wall -Wextra -Werror -O3
MLFLAG  =  -framework OpenGL -framework Appkit

OBJ = main.o parse_param.o parse_map.o  param_validator.o make_move.o raycaster.o \
      spritecaster.o screenshot_maker.o err_mng.o map_validator.o more_utils.o utils.o

LIBFT_D = libft/
MLX_D = minilibx/
LIBFT = libft.a
MLX = libmlx.dylib

all:	${NAME}

%.o: 		%.c
	${CC} ${FLAGS} -c $< ${DEPFLAGS}

DEPS  := $(patsubst %.o,%.d,${OBJ})
-include ${DEPS}
DEPFLAGS = -MMD -MF $(@:.o=.d)

${NAME}:  ${LIBFT_D}${LIBFT} ${MLX_D}${MLX}  ${OBJ}
	${CC} ${MLFLAG} -O3 ${OBJ} -L${LIBFT_D} -lft -L${MLX_D} -lmlx -o ${NAME}

${LIBFT_D}${LIBFT}:
	cd libft && ${MAKE} -j3 && ${MAKE} -j3 bonus

${MLX_D}${MLX}:
	cd minilibx && ${MAKE} && cp ${MLX} ../${MLX}

clean:
		rm -f ${OBJ} ${DEPS}
		${MAKE} -C${LIBFT_D} clean
		${MAKE} -C${MLX_D} clean

fclean: clean
		rm -f ${NAME}
		rm -f ${MLX}
		${MAKE} -C${LIBFT_D} fclean
		${MAKE} -C${MLX_D} clean

re:		fclean all




