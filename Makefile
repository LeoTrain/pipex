NAME	= pipex
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c srcs/exec_cmds.c srcs/get_cmd_path.c srcs/utils.c
OBJS	= $(SRCS:.c=.o)
PRINTF	= ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	make -C ft_printf

clean:
	rm -f $(OBJS)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

test: all
	./test
