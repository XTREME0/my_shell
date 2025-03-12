NAME	:= minishell

CFLAGS	:= -lreadline #-Wall -Werror -Wextra 
SRCS	:= main.c builtins/* parsing/* libft/libft.a ft_printf/libftprintf.a

all	: ft_printf $(NAME) 

ft_printf:
	make -C ft_printf/

$(NAME)	: $(SRCS)
	cc $(CFLAGS) $(SRCS)

.PHONY: ft_printf
