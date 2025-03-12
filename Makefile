NAME	:= minishell

CFLAGS	:= -lreadline #-Wall -Werror -Wextra 
SRCS	:= main.c parse_mimique.c builtins/* parsing/* libft/libft.a

all	: $(NAME)

$(NAME)	: $(SRCS)
	cc $(CFLAGS) $(SRCS)
