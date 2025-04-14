NAME	:= minishell

CFLAGS	:= -g -lreadline #-fsanitize=address #-Wall -Werror -Wextra 
SRCS	:= main.c free_join.c exec_cmds.c builtins/*.c v2-parsing/*.c libft/libft.a

all	:  $(NAME) 

$(NAME)	: $(SRCS)
	cc $(SRCS) $(CFLAGS)
