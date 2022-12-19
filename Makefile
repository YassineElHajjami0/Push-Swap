
SRCMAN = main.c \
	ft_lst_utils.c \
	swap_push.c \
	rotates.c \
	fake_swaps.c \
	setcounts_nums.c \
	best_moves.c \
	put_in_a.c \
	fn.c \
	ft_split.c \
	ft_strjoin.c \
	parsing.c \

BONUS = checker.c \
	get_next_line.c \
	ft_lst_utils.c \
	swap_push.c \
	rotates.c \
	fake_swaps.c \
	setcounts_nums.c \
	best_moves.c \
	put_in_a.c \
	fn.c \
	ft_split.c \
	ft_strjoin.c \
	parsing.c \
	get_next_line_utils.c \


CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar cr
FRM = rm -rf

NAME = push_swap 
BN = checker
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(SRCMAN) $(HEADER)
	$(CC) $(CFLAGS) $(SRCMAN) -o $(NAME)

bonus : $(BONUS) $(HEADER)
	$(CC) $(CFLAGS) $(BONUS) -o $(BN)

clean:
	$(FRM) $(NAME)

fclean: clean

re: fclean all