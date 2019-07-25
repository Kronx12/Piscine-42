SRC		= ft_cat.c
OBJ		= ${SRC:.c=.o}
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror
CC		= gcc
NAME	= ft_cat

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:		${OBJ}
			${CC} ${FLAGS} -c ${SRC} -o ${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}
