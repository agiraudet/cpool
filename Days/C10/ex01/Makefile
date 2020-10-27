SRCS		= ft_stream.c main.c

H			= ft_stream.h

OBJS		= ${SRCS:.c=.o}

NAME		= ft_cat

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

HEADERS		= -I ${H}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${HEADERS}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean
