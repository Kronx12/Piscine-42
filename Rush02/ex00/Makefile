SRCS = *.c

INCLUDES = ./ft_parser.h ./ft_struct.h ./ft_struct2.h ./lib.h

OBJS = ${SRCS:.c=.o}

NAME = rush-02

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I includes

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: 	fclean all

.PHONY:	all clean fclean re
