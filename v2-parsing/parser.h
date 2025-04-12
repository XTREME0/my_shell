/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:35:32 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/12 15:24:54 by ariyad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <readline/readline.h>
# include <sys/wait.h>
# include <stdarg.h>

# define WHITE_SP "\r\t\v\f\n "
# define HD_EOF "\nheredoc delimited by end-of-file (wanted \"%s\")\n"
# define FD_ERR "\nminishell: %s: %s\n"

// remove these later

typedef struct s_env
{
	int		flag;	
	char		*key;
	char		*val;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

int	find_chr(char *str, char c);
t_env	*envlast(t_env *lst);
void	env_add_back(t_env **lst, t_env *new);
char	**split_by_two(char *env, char c);
t_env	*new_env(char *env);
t_env	*my_setenv(char **env);
void	env_clear(t_env *e);
// --------------------------

typedef struct s_stb
{
	char			*str;
	struct s_stb	*next;
	struct s_stb	*prev;
}	t_stb;

t_stb	*stb_new(char *str);
void	stb_addfront(t_stb **head, t_stb *new);
void	stb_addback(t_stb **head, t_stb *new);
void	stb_clear(t_stb **head);

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
char		*reg_expand(char *str, t_env *env, int tf);

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

//remove these
char		**ft_split(char const *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
int			ft_strcmp(char *str1, char *str2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_utoa(unsigned int n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strjoin_plus(char *s1, char *s2);
void		ft_putchar_fd(int fd, char c);
void		ft_pustr_fd(int fd, const char *s);

void	fd_printf(int fd, const char *format, ...);

// redirs
void		redir_pipe(t_cmd *cmds);
int			open_redirs(t_cmd *cmd, t_tokens *toks);
int			create_redir(t_tokens *toks, t_redirs **redirs);
int			read_heredoc(t_redirs *redirs);
int			create_heredocs(t_redirs *redirs);
void		open_files(t_redirs *redirs, t_cmd *cmd);

// redirs list
t_redirs	*ft_newredir(void);
void		ft_addredir(t_redirs **head, t_redirs *new);
void		ft_clearredir(t_redirs **head);
void		clear_n_keep_redir(t_redirs **head, t_redirs *in, t_redirs *out);
t_redirs	*ft_lastredir(t_redirs **head);

char		*ft_mkhtmp(void);



#endif