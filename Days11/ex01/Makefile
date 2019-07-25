
SRCS	= ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_swap.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
HEADER	= ./includes/ft.h
OBJS	= ${SRCS:.c=.o}
NAME	= libft.a
FLAGS	= -Wall -Wextra -Werror
CC		= gcc
RM		= rm -f

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I includes

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
