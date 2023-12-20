NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

###########################Sources#############################
SRCS = \
	algo_pile_of_3.c algo_utils.c find_cheapest_in_chunk.c\
	command_a.c command_b.c manage_error.c chunk.c \
	manage_pile.c push_swap.c selecting_algo.c \
	utils.c algo.c find_cheapest.c command_rr_rrr.c

SRCS_BONUS = bonus_checker.c bonus_command.c \
	command_a.c command_b.c manage_error.c chunk.c \
	manage_pile.c find_cheapest_in_chunk.c selecting_algo.c \
	utils.c algo.c find_cheapest.c command_rr_rrr.c \
	algo_pile_of_3.c algo_utils.c

###########################Objects#############################
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
OBJS_ALL = ${OBJS} ${OBJS_BONUS}

###########################Libs#############################
LIBFT = ./libft/libft.a
FT_PRINTF = ./libft/ft_printf/libftprintf.a
GNL = ./libft/get_next_line/libgnl.a
ALL_LIB = ${LIBFT} ${FT_PRINTF} ${GNL}

###########################Rules#############################
all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ${ALL_LIB} -o ${NAME}

bonus: ${OBJS_BONUS}
	@${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS_BONUS} ${ALL_LIB} -o ${NAME_BONUS}

clean:
	@${MAKE} -C ./libft fclean
	rm -f ${OBJS_ALL}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
