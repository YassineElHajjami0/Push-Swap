
SRCMAN = main.c \
	ft_lst_utils.c \
	swap_push.c \
	rotates.c \
	fake_swaps.c \
	setcounts_nums.c \
	best_moves.c \
	put_in_a.c \
	fn.c \


CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar cr
FRM = rm -rf

NAME = push_swap
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(SRCMAN) $(HEADER)
	$(CC) $(CFLAGS) $(SRCMAN) -o $(NAME)

clean:
	$(FRM) $(NAME)

fclean: clean

re: fclean all