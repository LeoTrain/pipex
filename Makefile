NAME	= pipex
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c
OBJS	= $(SRCS:.c=.o)
PRINTF	= ./headers/ft_printf.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

test: all
	./test
