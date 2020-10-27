DIR_SRCS 	= ./srcs

SRCS 		= ${DIR_SRCS}/ft_putchar.c ${DIR_SRCS}/ft_swap.c ${DIR_SRCS}/ft_putstr.c ${DIR_SRCS}/ft_strlen.c ${DIR_SRCS}/ft_strcmp.c

INC_DIR 	= ./includes

OBJS 		= ${SRCS:.c=.o}

NAME 		= libft.a

CC 			= gcc

RM 			= rm -f

AR 			= ar rc

CFLAGS 		= -c -Wall -Wextra -Werror

HEADERS 	= -I$(INC_DIR)

.c.o :
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${HEADERS}

${NAME} :   ${OBJS}
			${AR} ${NAME} ${OBJS}
all : 		${NAME}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}

re :		fclean all

.PHONY : 	all clean fclean re
