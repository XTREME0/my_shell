CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c addr_utils.c hex_utils.c nbr_utils.c \
		str_utils.c u_nbr_utils.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<
	$(AR) rcs $(NAME) $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean