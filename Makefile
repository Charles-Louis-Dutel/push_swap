NAME = push_swap
SRCS = \
	algo_pile_of_3.c algo_utils.c algo.c \
	command_a.c command_b.c manage_error.c \
	manage_pile.c push_swap.c selecting_algo.c \
	utils.c \

OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
