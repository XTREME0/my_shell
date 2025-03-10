all	:
	cc main.c builtins/env.c builtins/export.c libft/libft.a ft_putstr.c free_join.c libft/ft_strlcat.c builtins/cd.c builtins/pwd.c builtins/unset.c builtins/exit.c libft/ft_itoa.c builtins/print_export.c builtins/export_helper.c parse_mimique.c -lreadline
