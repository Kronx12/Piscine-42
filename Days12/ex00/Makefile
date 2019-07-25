SRC		= ft_display_file.c
NAME 	= ft_display_file
FLAGS	= -Wall -Wextra -Werror
CC		= gcc
RM		= rm -f
OBJ		= ${SRC:.c=.o}

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:		${OBJ}
			${CC} ${FLAGS} -c ${SRC} -o ${NAME}
clean:
			${RM} ${OBJ}
fclean:		clean
			${RM} ${NAME}
