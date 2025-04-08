NAME	:= minishell

CFLAGS	:= -lreadline #-fsanitize=address #-Wall -Werror -Wextra 
SRCS	:= main.c free_join.c exec_cmds.c builtins/* v2-parsing/* libft/libft.a

all	:  $(NAME) 

$(NAME)	: $(SRCS)
	cc $(CFLAGS) $(SRCS)
