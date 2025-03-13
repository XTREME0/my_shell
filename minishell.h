/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:27:22 by ataai             #+#    #+#             */
/*   Updated: 2025/03/13 12:56:37 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include "ft_printf/ft_printf.h"
/* # include "libft/libft.h"*/

typedef struct s_env
{
	int		flag;	
	char		*key;
	char		*val;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef enum token_types
{
	CMD = 1,
	WORD,
	FILES,
	SINGLE_Q,
	DOUBLE_Q,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	PIPE,
	HEREDOC,
	DELIM,
	EXPAND
}	t_tok_types;

typedef struct s_inp
{
	char			*str;
	int				exp_split;
	int				exported;
	struct s_inp	*next;
}	t_inp;

typedef struct s_tokens
{
	int		tok_type;
	char	*tok_val;
	// int		*redir_in;
	// int		*redir_out;
	// int		heredoc;
	// int		*append;
	// int		expand;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_cmd
{
	char			**kwargs;
	int				fd_in;
	int				fd_out;
	int				heredoc_fd;
	char			*heredoc_file;
	char			*delim;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

/*typedef	struct s_cmd
{
	char	*cmd;
	char	**args;
	int		fd_in;
	int		fd_out;
	int		is_append;
	int		is_heredoc;
	char	*heredoc_delim;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;*/

char	*get_val(t_env *env, char *key);
int	print_env(t_env *env);
void	ft_putstr(char *str);
int	my_export_write(t_env *env, char *arg);
void	env_add_back(t_env **lst, t_env *n);
t_env	*new_env(char *env);
char	**split_by_two(char *env, char c);
void	print_export(t_env *env);
char	*free_join(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int	cd(t_env **env, char *str);
int	pwd(void);
int	unset(t_env **env, char *key);
int	put_export(t_env *env);
int	export_add_replace(t_env **env, char **pair);
void	my_exit(int x);
int	set_by_key(t_env **env, char *key, const char *val);
char	*ft_itoa(int n);
void	free_tab(char **tab);
void	env_error(char **pair);
void	set_flag(t_env *env, int f);
int	append_env(t_env **env, char **pair);
int	node_lst_len(t_env *env);
t_env	*add_env(char **pair);
int	exec_setup(t_cmd **cmd_node);
int	exec_cmd(t_cmd *cmd_node);
// t_cmd	*add_cmd(char **cmd_args);
// void	cmd_add_back(t_cmd **lst, t_cmd *new);
// t_cmd	*cmdlast(t_cmd *lst);

// Parsin 3la 9ed l7al

# define WHITE_SP "\r\t\v\f\n "


t_cmd	*ft_newcmd(void);
t_cmd	*ft_firstcmd(t_cmd *cmd);
void	ft_addcmd(t_cmd **head, t_cmd *new);
void	ft_delcmd(t_cmd *cmd);
void	ft_clearcmds(t_cmd	**head);
int	create_nodes(t_tokens *toks, t_cmd	**cmds);
int	set_args(t_tokens *toks, t_cmd *cmds);
int	set_redirs(t_tokens *toks, t_cmd **cmds);
int	get_expans(char *str, size_t *i, t_inp **head, t_env *env);

void	open_out(char *filename, t_cmd **cmd);
void	open_in(char *filename, t_cmd **cmd);
void	open_append(char *filename, t_cmd **cmd);
int		open_heredoc(char *delim, t_cmd **cmd);
void	set_pipe(t_cmd **cmd);


t_inp	*ft_newinp(char *str);
void	ft_addinp(t_inp **head, t_inp *new);
int		append_inp(t_inp **head, char *str, int exp_split);
void	ft_clearinp(t_inp **head);

t_tokens	*ft_newtoken(char *str);
void	ft_token_add(t_tokens **head, t_tokens *new);
void	ft_cleartoks(t_tokens **head);

t_tokens	*tokenize(char *str, t_env **env);

int	join_inps(t_tokens **toks_head, t_inp **inp_head);

int	filter_line(const char *str, t_env **env, t_tokens **toks);

int	get_q_content(char *str, size_t *i, t_inp **head, t_env *env);

void	skip_white_sp(const char *str, size_t *i);
int		is_quote(char c);
int		ft_isspace(char c);
int		is_redir(char *str);

void	free_table(char **strs);

t_cmd	*construct_cmds(char *str, t_env **env);

#endif
