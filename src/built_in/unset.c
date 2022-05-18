/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:18 by swautele          #+#    #+#             */
/*   Updated: 2022/05/18 18:49:33 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstsearch(t_list *env, char *searched)
{
	while (env)
	{
		if (ft_strncmp(searched, env->content, ft_strlen(searched)) == 0)
		{
			return (env);
		}
		env = env->next;
	}
	return (NULL);
}

void	unset_env(t_param *data)
{
	int		i;
	t_list	*to_del;
	t_list	*previous;
	t_list	*next;

	i = 5;
	while (is_whitespace(data->str[i]) == TRUE)
		i++;
	to_del = ft_lstsearch(data->envp, &data->str[i]);
	next = to_del->next;
	previous = data->envp;
	if (to_del == previous)
		data->envp = next;
	while (previous->next != to_del)
		previous = previous->next;
	ft_lstdelone(to_del, &free);
	previous->next = next;
}
