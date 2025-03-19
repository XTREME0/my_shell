NAME	:= minishell

CFLAGS	:= -lreadline -fsanitize=address #-Wall -Werror -Wextra 
SRCS	:= main.c free_join.c exec_cmds.c builtins/* parsing/* libft/libft.a ft_printf/libftprintf.a

all	: ft_printf $(NAME) 

ft_printf:
	make -C ft_printf/

$(NAME)	: $(SRCS)
	cc $(CFLAGS) $(SRCS)

.PHONY: ft_printf
