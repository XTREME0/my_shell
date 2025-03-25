#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <readline/readline.h>
# include <sys/wait.h>

# define WHITE_SP "\r\t\v\f\n "

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

typedef struct t_redirs
{
	int		fd;
	int		type;
	char	*filename;
	char	*delim;
}	t_redirs;

typedef struct s_cmd
{
	char			**kwargs;
	int				fd_in;
	int				fd_out;
	char			*heredoc_file;
	char			*delim;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

void	free_table(char **strs);
char	*custom_join(char *s1, char *s2);
t_cmd	*ft_newcmd(void);
void	ft_addcmd(t_cmd **head, t_cmd *new);
void	ft_delcmd(t_cmd *cmd);
void	ft_clearcmds(t_cmd	**head);
t_cmd	*ft_firstcmd(t_cmd *cmd);
t_tokens	*ft_newtoken(char *tok_val);
void	ft_token_add(t_tokens **head, t_tokens *new);
void	ft_cleartoks(t_tokens **head);
void	ft_token_replace(t_tokens **head, t_tokens *new_lst);
void	ft_firsttok(t_tokens **head);

// tokenizing
void	assign_redirs(t_tokens *toks);
void	assign_files(t_tokens *toks);
void	assign_expans(t_tokens *toks);
int		remove_quote(t_tokens *toks);
void	assign_cmds(t_tokens *toks);
void	assign_words(t_tokens *toks);

// input splitting
t_tokens	*input_split(char *str);
int			get_word(char *s, size_t *i, t_tokens **head);
int			get_redir(char *s, size_t *i, t_tokens **head);
void		skip_q_content(char *s, size_t *i);
t_tokens	*tokenize(char *str);

// cmds list
t_cmd	*ft_newcmd(void);
void	ft_addcmd(t_cmd **head, t_cmd *new);
void	ft_delcmd(t_cmd *cmd);
void	ft_clearcmds(t_cmd	**head);
t_cmd	*ft_firstcmd(t_cmd *cmd);

// cmds
t_cmd	*create_nodes(t_tokens *toks);
int		set_args(t_cmd *cmds, t_tokens *toks);

// files

void	open_in(char *filename, t_cmd **cmd);
void	open_out(char *filename, t_cmd **cmd);
void	open_append(char *filename, t_cmd **cmd);
void	set_pipe(t_cmd **cmd);
int		open_heredoc(char *delim, t_cmd **cmd);

// utils
void	skip_spaces(char *s, size_t *i);
int		ft_isspace(char c);
int		is_redir(char c);
int		is_quote(char c);
int		has_quotes(char *str);
int		is_expan(char *val);

//remove these
char	*ft_utoa(unsigned int n);

// redirs
void	redir_pipe(t_cmd *cmds);
int	open_redirs(t_cmd *cmd, t_tokens *toks);

#endif