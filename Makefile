all	:
	cc main.c builtins/env.c builtins/export.c libft/libft.a ft_putstr.c free_join.c libft/ft_strlcat.c -lreadline
