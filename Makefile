NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
LIB_LOC = ./libft
LIBRARY = libft.a
SRCS	= push_swap.c src/indexer.c src/init.c src/lower_sort.c src/utils/utils_1.c \
src/utils/utils_2.c src/utils/utils_3.c src/utils/utils_4.c src/utils/utils_5.c \
src/operations/operations_1.c src/operations/operations_2.c src/operations/operations_3.c
BONUS	= checker.c src/operations/operations_1.c src/operations/operations_2.c \
src/operations/operations_3.c src/indexer.c src/utils/utils_1.c src/utils/utils_2.c \
src/lower_sort.c src/init.c

OBJS	= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUS:.c=.o}

all: $(NAME)

$(LIBRARY):
	$(MAKE) -C $(LIB_LOC)

$(NAME): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(LIB_LOC) -lft

bonus: $(BONUS_OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) -o checker $(BONUS_OBJS) -L $(LIB_LOC) -lft

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) clean -C $(LIB_LOC)

fclean: clean
	rm -f $(NAME) checker
	$(MAKE) fclean -C $(LIB_LOC)

re:	fclean all

.PHONY: all bonus clean fclean re