/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:25:30 by swautele          #+#    #+#             */
/*   Updated: 2022/05/18 14:57:24 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*convert_to_list(char **envp)
{
	t_list	*env;
	int		i;
	t_list	*add;

	env = ft_lstnew(envp[0]);
	i = 0;
	while (envp[++i])
	{
		add = ft_lstnew(envp[i]);
		ft_lstadd_back(&env, add);
	}
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