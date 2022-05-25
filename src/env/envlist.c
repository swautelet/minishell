/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:25:30 by swautele          #+#    #+#             */
/*   Updated: 2022/05/25 10:34:07 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	loop_list(char **envp, t_list *env)
{
	int		i;
	int		j;
	char	*copy;
	t_list	*add;

	i = 0;
	while (envp[++i])
	{
		copy = ft_calloc(sizeof(char), ft_strlen(envp[i]) + 1);
		if (!copy)
		{
			ft_lstclear(env, &free);
			return ;
		}
		j = -1;
		while (envp[i][++j])
			copy[j] = envp[i][j];
		add = ft_lstnew(copy);
		if (!add)
		{
			ft_lstclear(env, &free);
			return ;
		}
		ft_lstadd_back(&env, add);
	}
}

t_list	*convert_to_list(char **envp)
{
	t_list	*env;
	// int		i;
	int		j;
	// t_list	*add;
	char	*copy;

	copy = ft_calloc(sizeof(char), ft_strlen(envp[0]) + 1);
	if (!copy)
		return (NULL);
	j = -1;
	while (envp[0][++j])
		copy[j] = envp[0][j];
	env = ft_lstnew(copy);
	if (!env)
	{
		free (copy);
		return (NULL);
	}
	loop_list(envp, env);
	return (env);
}

char	**convert_to_char(t_list *env)
{
	char	**envp;
	int		i;

	envp = ft_calloc(sizeof(char *), ft_lstsize(env) + 1);
	i = 0;
	while (env->next)
	{
		envp[i] = env->content;
		env = env->next;
		i++;
	}
	envp[i] = env->content;
	return (envp);
}

char	*my_getenv(t_param *data, char *searched)
{
	t_list	*reader;
	int		len;

	reader = data->envp;
	len = ft_strlen(searched);
	if (searched == NULL)
		return (NULL);
	while (1)
	{
		while (ft_strncmp(reader->content, searched, len) != 0)
		{
			reader = reader->next;
			if (reader == NULL)
				return (NULL);
		}
		if (reader->content[len] == '=')
			break ;
		else
			reader = reader->next;
	}
	return (&reader->content[len + 1]);
}
