/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataai <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:24:30 by ataai             #+#    #+#             */
/*   Updated: 2025/04/08 19:29:49 by ataai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_chr(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

t_env	*envlast(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	env_add_back(t_env **lst, t_env *new)
{
	if (lst != NULL)
	{
		if (*lst == NULL)
		{
			*lst = new;
		}
		else
		{
			new->prev = envlast(*lst);
			if (envlast(*lst) != NULL)
				envlast(*lst)->next = new;
		}
	}
}

char	**split_by_two(char *env, char c)
{
	int	j;
	int	c_idx;
	char	**s;

	if (env == NULL)
		return (NULL);
	s = malloc(sizeof(char *) * 3);
	if (s == NULL)
		return (NULL);
	j = 0;
	c_idx = find_chr(env, c);
	if (c_idx != -1)
	{
		s[0] = ft_substr(env, 0, c_idx);
		s[1] = ft_substr(env, c_idx + 1, ft_strlen(env));
		if (!s[0] || !s[1])
			return (free(s[0]), free(s[1]), free(s), NULL);
	}
	else
	{
		s[0] = ft_strdup(env);
		s[1] = NULL;
		if (!s[0])
			return (free(s[0]), free(s), NULL);
		return (s);
	}
	s[2] = NULL;
	return (s);
}

t_env	*new_env(char *env)
{
	t_env	*ptr;
	char	**pair;

	ptr = (t_env *)malloc(sizeof(t_env));
	if (ptr == NULL)
		return (NULL);
	pair = split_by_two(env, '=');
	if (pair == NULL)
		return (NULL);
	ptr->key = pair[0];
	ptr->val = pair[1];
	ptr->next = NULL;
	ptr->prev = NULL;
	free(pair);
	return (ptr);
}

t_env	*my_setenv(char **env)
{
	t_env	*tmp;
	t_env	*e;

	if (env == NULL)
		return (NULL);
	e = NULL;
	while (*env)
	{
		tmp = new_env(*env);
		if (tmp == NULL)
			return ( NULL); // clear_env to add
		env_add_back(&e, tmp);
		env++;
	}
	return (e);

}

void	env_clear(t_env *e)
{
	if (e == NULL)
		return ;
	if (e->next)
		env_clear(e->next);
	free(e->key);
	free(e->val);
	free(e);
}

void	sighandler(int sig)
{
	signal(sig, SIG_IGN);
	write(1, "\n$", 2);
	signal(SIGINT, sighandler);
}

int	shell_prompt(t_cmd *cmd_node, t_env *my_env)
{
	char	*prompt;

	if (cmd_node != NULL)
		ft_clearcmds(&cmd_node);
	cmd_node = NULL;
	while (1)
	{
		prompt = readline("$");
		if (prompt == NULL)
			break ;
		if (prompt[0] == 0)
		{
			free(prompt);
			continue ;
		}
		cmd_node = construct_cmds(prompt);
		if (cmd_node == NULL)
			return (-1);
		exec_setup(&cmd_node, &my_env);
		while (wait(NULL) != -1)
			;
		ft_clearcmds(&cmd_node);
		cmd_node = NULL;
		free(prompt);
	}
	env_clear(my_env);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_env	*my_env;
	t_cmd	*cmd_node;
	int	i;

	cmd_node = NULL;
	my_env = my_setenv(env);
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	shell_prompt(cmd_node, my_env);
	return (0);
}
