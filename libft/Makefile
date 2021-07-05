NAME		=	libft.a

OBJ			=	ft_memcmp.o ft_memchr.o ft_bzero.o  ft_memccpy.o ft_memcpy.o ft_memmove.o ft_memset.o \
				ft_strlen.o ft_strlcpy.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strnstr.o ft_strncmp.o \
				ft_atoi.o ft_isdigit.o ft_isalpha.o ft_toupper.o ft_tolower.o ft_isalnum.o ft_isascii.o \
				ft_isprint.o ft_strdup.o ft_calloc.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o \
				ft_strmapi.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putnbr.o ft_putchar.o \
				ft_putendl.o ft_putstr.o ft_numlen.o ft_itoa_base.o get_next_line.o ft_isspace.o ft_free_char_array.o

BONUS_OBJ	=	ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o \
 				ft_lstiter.o ft_lstmap.o

CFLAGS		=	-Wall -Werror -Wextra

all:		${NAME}

%.o: 		%.c
	gcc ${CFLAGS} -c $< ${DEPFLAGS}

DEPS  := $(patsubst %.o,%.d,${OBJ})
BDEPS := $(patsubst %.o,%.d,${BONUS_OBJ})
-include ${DEPS}
DEPFLAGS = -MMD -MF $(@:.o=.d)

$(NAME):	${OBJ}
	ar rc libft.a ${OBJ}
	ranlib ${NAME}

bonus:		${BONUS_OBJ}
	ar rc libft.a ${BONUS_OBJ}
	ranlib ${NAME}

clean:
	rm -f ${OBJ} ${DEPS}
	rm -f ${BONUS_OBJ} ${BDEPS}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY:		clean fclean re all




