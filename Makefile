NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

###########################Sources#############################
SRCS_DIR = sources/
FILE = push_swap.c

SRC = $(addprefix $(SRCS_DIR), $(FILE))

FILES = \
	algo_pile_of_3.c algo_utils.c find_cheapest_in_chunk.c \
	command_a.c command_b.c manage_error.c chunk.c \
	manage_pile.c selecting_algo.c \
	utils.c algo.c find_cheapest.c command_rr_rrr.c

SRCS = $(addprefix $(SRCS_DIR), $(FILES))

BONUS_DIR = sources/bonus/
FILES_BONUS = \
	checker_bonus.c command_bonus.c

SRCS_BONUS = $(addprefix $(BONUS_DIR), $(FILES_BONUS))

###########################Objects#############################
OBJ = ${SRC:.c=.o}
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
OBJS_ALL = ${OBJ} ${OBJS} ${OBJS_BONUS}

###########################Libs#############################
LIBFT = ./libft/libft.a
FT_PRINTF = ./libft/ft_printf/libftprintf.a
GNL = ./libft/get_next_line/libgnl.a
ALL_LIB = ${LIBFT} ${FT_PRINTF} ${GNL}

###########################Rules#############################

${NAME}: ${OBJ} ${OBJS}
	@${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJ} ${OBJS} ${ALL_LIB} -o ${NAME}

all: ${NAME} bonus

bonus: ${OBJS_BONUS}
	@${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ${OBJS_BONUS} ${ALL_LIB} -o ${NAME_BONUS}

clean:
	@${MAKE} -C ./libft fclean
	rm -f ${OBJS_ALL}

fclean: clean
	rm -f ${NAME}
	rm -f ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
