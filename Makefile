
SRCMAN = ft_atoi.c \
	ft_lst_utils.c \


OBJMAN = $(SRCMAN:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar cr
FRM = rm -rf

NAME = push_swap
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJMAN)
	$(CC) $(CFLAGS) $(OBJMAN) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	$(FRM) $(OBJMAN)

fclean: clean
	$(FRM) $(NAME)

re: fclean all