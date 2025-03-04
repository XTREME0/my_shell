/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:27:22 by ataai             #+#    #+#             */
/*   Updated: 2025/03/04 23:01:13 by ataai            ###   ########.fr       */
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
# include "libft/libft.h"

typedef struct s_env
{
	int		flag;	
	char		*key;
	char		*val;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;
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
int	my_exit(t_env **env, int x);
int	set_by_key(t_env **env, char *key, const char *val);
char	*ft_itoa(int n);
#endif
