/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariyad <ariyad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:35:32 by ariyad            #+#    #+#             */
/*   Updated: 2025/04/08 16:29:42 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

//# define WHITE_SP "\r\t\v\f\n "
//# define HD_EOF "\nheredoc delimited by end-of-file (wanted \"%s\")\n"
//# define FD_ERR "\nminishell: %s: %s\n"
//
//typedef enum token_types
//{
//	CMD = 1,
//	WORD,
//	FILES,
//	REDIR_IN,
//	REDIR_OUT,
//	APPEND,
//	PIPE,
//	HEREDOC,
//	DELIM,
//	EXPAND
//}	t_tok_types;
//
//typedef struct s_tokens
//{
//	int				tok_type;
//	char			*tok_val;
//	struct s_tokens	*next;
//	struct s_tokens	*prev;
//}	t_tokens;
//
//typedef struct s_redirs
//{
//	int				fd;
//	int				io;
//	int				perm;
//	char			*filename;
//	char			*delim;
//	struct s_redirs	*next;
//}	t_redirs;
//
//typedef struct s_cmd
//{
//	char			**kwargs;
//	int				fd_in;
//	int				fd_out;
//	char			*heredoc_file;
//	struct s_cmd	*next;
//	struct s_cmd	*prev;
//}	t_cmd;
//
//void		free_table(char **strs);
//char		*custom_join(char *s1, char *s2);
//t_cmd		*ft_newcmd(void);
//void		ft_addcmd(t_cmd **head, t_cmd *new);
//void		ft_delcmd(t_cmd *cmd);
//void		ft_clearcmds(t_cmd	**head);
//t_cmd		*ft_firstcmd(t_cmd *cmd);
//t_tokens	*ft_newtoken(char *tok_val);
//void		ft_token_add(t_tokens **head, t_tokens *new);
//void		ft_cleartoks(t_tokens **head);
//void		ft_token_replace(t_tokens **head, t_tokens *new_lst);
//void		ft_firsttok(t_tokens **head);
//
//// tokenizing
//void		assign_redirs(t_tokens *toks);
//void		assign_files(t_tokens *toks);
//void		assign_expans(t_tokens *toks);
//int			remove_quote(t_tokens *toks);
//void		assign_cmds(t_tokens *toks);
//void		assign_words(t_tokens *toks);
//
//// expansion
//int			rm_q_n_expand(t_tokens **toks);
//
//// input splitting
//t_tokens	*input_split(char *str);
//int			get_word(char *s, size_t *i, t_tokens **head);
//int			get_redir(char *s, size_t *i, t_tokens **head);
//void		skip_q_content(char *s, size_t *i);
//t_tokens	*tokenize(char *str);
//
//// cmds list
//t_cmd		*ft_newcmd(void);
//void		ft_addcmd(t_cmd **head, t_cmd *new);
//void		ft_delcmd(t_cmd *cmd);
//void		ft_clearcmds(t_cmd	**head);
//t_cmd		*ft_firstcmd(t_cmd *cmd);
//
//// cmds
//t_cmd		*create_nodes(t_tokens *toks);
//int			set_args(t_cmd *cmds, t_tokens *toks);
//
//// files
//
//void		set_pipe(t_cmd **cmd);
//
//// utils
//void		skip_spaces(char *s, size_t *i);
//int			ft_isspace(char c);
//int			is_redir(char c);
//int			is_quote(char c);
//int			has_quotes(char *str);
//int			is_expan(char *val);
//
//// redirs
//void		redir_pipe(t_cmd *cmds);
//int			open_redirs(t_cmd *cmd, t_tokens *toks);
//int			create_redir(t_tokens *toks, t_redirs **redirs);
//int			read_heredoc(t_redirs *redirs);
//int			create_heredocs(t_redirs *redirs);
//void		open_files(t_redirs *redirs, t_cmd *cmd);
//
//// redirs list
//t_redirs	*ft_newredir(void);
//void		ft_addredir(t_redirs **head, t_redirs *new);
//void		ft_clearredir(t_redirs **head);
//void		clear_n_keep_redir(t_redirs **head, t_redirs *in, t_redirs *out);
//t_redirs	*ft_lastredir(t_redirs **head);
//
//char		*ft_mkhtmp(void);

#endif
