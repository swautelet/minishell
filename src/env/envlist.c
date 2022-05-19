/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:25:30 by swautele          #+#    #+#             */
/*   Updated: 2022/05/19 14:24:45 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*convert_to_list(char **envp)
{
	t_list	*env;
	int		i;
	int		j;
	t_list	*add;
	char	*copy;

	copy = ft_calloc(sizeof(char), ft_strlen(envp[0] + 1));
	j = -1;
	while (envp[0][++j])
		copy[j] = envp[0][j];
	env = ft_lstnew(copy);
	i = 0;
	while (envp[++i])
	{
		copy = ft_calloc(sizeof(char), ft_strlen(envp[i] + 1));
		j = -1;
		while (envp[i][++j])
			copy[j] = envp[i][j];
		add = ft_lstnew(copy);
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