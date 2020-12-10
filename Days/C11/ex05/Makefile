SRCS		= ft_atoi.c ft_op.c ft_print.c ft_proc_op.c main.c

OBJS		= ${SRCS:.c=.o}

NAME		= do-op

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c ${SRCS}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean
