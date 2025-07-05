CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT_PATH = ./libft
LIBFT_A = $(LIBFT_PATH)/libft.a
LIBFT_SRCS = $(wildcard $(LIBFT_PATH)/*.c)
SRCS = srcs/ft_printf.c srcs/arg_to_str.c srcs/arg_to_ptr.c srcs/arg_to_int.c srcs/arg_to_uint.c srcs/arg_to_hexa.c
OBJS = $(SRCS:.c=.o) $(LIBFT_OBJS)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	ar rcs $(NAME) $(OBJS)

$(LIBFT_A):
	$(MAKE) bonus -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

bonus: $(NAME)
