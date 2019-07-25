SRCS = srcs/ft_resolve.c srcs/ft_resolve2.c srcs/main.c

INCLUDES = includes/ft_lib.h

OBJS = ${SRCS:.c=.o}

NAME = bsq

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I includes

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
