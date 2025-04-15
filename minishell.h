/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:27:22 by ataai             #+#    #+#             */
/*   Updated: 2025/04/15 15:24:36 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "v2-parsing/parser.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdarg.h>

# define WHITE_SP "\r\t\v\f\n "
# define HD_EOF "\nheredoc delimited by end-of-file (wanted \"%s\")\n"
# define FD_ERR "\nminishell: %s: %s\n"

typedef struct s_env
{
	int		flag;	
	char		*key;
	char		*val;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_stb
{
	char			*str;
	struct s_stb	*next;
	struct s_stb	*prev;
}	t_stb;

typedef enum token_types
{
	CMD = 1,
	WORD,
	FILES,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	PIPE,
	HEREDOC,
	DELIM,
	EXPAND
}	t_tok_types;

typedef struct s_tokens
{
	int				tok_type;
	char			*tok_val;
	struct s_tokens	*next;
	struct s_tokens	*prev;
}	t_tokens;

typedef struct s_redirs
{
	int				fd;
	int				io;
	int				perm;
	char			*filename;
	char			*delim;
	struct s_redirs	*next;
}	t_redirs;

typedef struct s_cmd
{
	char			**kwargs;
	int				fd_in;
	int				fd_out;
	char			*heredoc_file;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

void	del_other_cmds(t_cmd *cmd_node);
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
int	unset(t_cmd * cmd, t_env **env);
int	put_export(t_env *env);
int	export_add_replace(t_env **env, char **pair);
void	my_exit(t_cmd *cmd, t_env **env);
int	set_by_key(t_env **env, char *key, char *val);
char	*ft_itoa(int n);
void	free_tab(char **tab);
void	env_error(char **pair);
void	set_flag(t_env *env, int f);
int	append_env(t_env **env, char **pair);
int	node_lst_len(t_env *env);
t_env	*add_env(char **pair);
int	exec_setup(t_cmd **cmd_node, t_env **my_env);
int	exec_cmd(t_cmd *cmd_node, t_env **my_env);
int	echo(t_cmd *cmd);
void	env_clear(t_env *e);
int     my_export(t_cmd *cmd_node, t_env *my_env);
void	go_back_clear_cmd(t_cmd *cmd);
void	print_cmd_err(char *cmd);
void	set_exit_status(t_env **my_env, int status);
// t_cmd	*add_cmd(char **cmd_args);
// void	cmd_add_back(t_cmd **lst, t_cmd *new);
// t_cmd	*cmdlast(t_cmd *lst);

//parsing 3la 9ed l7al 


t_stb	*stb_new(char *str);
void	stb_addfront(t_stb **head, t_stb *new);
void	stb_addback(t_stb **head, t_stb *new);
void	stb_clear(t_stb **head);
char	*stb_merge(t_stb *build);
void	replace(char **s, size_t start, size_t end, char *replace);

void		free_table(char **strs);
char		*custom_join(char *s1, char *s2);
t_cmd		*ft_newcmd(void);
void		ft_addcmd(t_cmd **head, t_cmd *new);
void		ft_delcmd(t_cmd *cmd);
void		ft_clearcmds(t_cmd	**head);
t_cmd		*ft_firstcmd(t_cmd *cmd);
t_tokens	*ft_newtoken(char *tok_val);
void		ft_token_add(t_tokens **head, t_tokens *new);
void		ft_cleartoks(t_tokens **head);
void		ft_token_replace(t_tokens **head, t_tokens *new_lst);
void		ft_firsttok(t_tokens **head);

// tokenizing
void		assign_redirs(t_tokens *toks);
void		assign_files(t_tokens *toks);
void		assign_expans(t_tokens *toks);
int			remove_quote(char **token);
void		assign_cmds(t_tokens *toks);
void		assign_words(t_tokens *toks);

// expansion
int			treat_strs(t_tokens **toks);
char		*env_val(t_env *env, char *exp);
int			remove_quote(char **token);
void		reg_expand(char **s, t_env *env, int tf);
void		skip_expand(char *str, size_t *i);

// input splitting
t_tokens	*input_split(char *str);
int			get_word(char *s, size_t *i, t_tokens **head);
int			get_redir(char *s, size_t *i, t_tokens **head);
void		skip_q_content(char *s, size_t *i);
t_tokens	*tokenize(char *str);

// cmds list
t_cmd		*ft_newcmd(void);
void		ft_addcmd(t_cmd **head, t_cmd *new);
void		ft_delcmd(t_cmd *cmd);
void		ft_clearcmds(t_cmd	**head);
t_cmd		*ft_firstcmd(t_cmd *cmd);
t_cmd	*construct_cmds(char *str, t_env *env);

// cmds
t_cmd		*create_nodes(t_tokens *toks);
int			set_args(t_cmd *cmds, t_tokens *toks);

// files

void		set_pipe(t_cmd **cmd);
int			open_check(t_redirs *redir, int perm);

// utils
void		skip_spaces(char *s, size_t *i);
int			ft_isspace(char c);
int			is_redir(char c);
int			is_quote(char c);
int			has_quotes(char *str);
int			is_expan(char *val);

void	fd_printf(int fd, const char *format, ...);

// redirs
void		redir_pipe(t_cmd *cmds);
int			open_redirs(t_cmd *cmd, t_tokens *toks, t_env *env);
int			create_redir(t_tokens *toks, t_redirs **redirs);
int			read_heredoc(t_redirs *redirs, t_env *env);
int			create_heredocs(t_redirs *redirs, t_env *env);
void		open_files(t_redirs *redirs, t_cmd *cmd);

// redirs list
t_redirs	*ft_newredir(void);
void		ft_addredir(t_redirs **head, t_redirs *new);
void		ft_clearredir(t_redirs **head);
void		clear_n_keep_redir(t_redirs **head, t_redirs *in, t_redirs *out);
t_redirs	*ft_lastredir(t_redirs **head);

char		*ft_mkhtmp(void);
#endif

