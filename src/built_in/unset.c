/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:18 by swautele          #+#    #+#             */
/*   Updated: 2022/05/20 15:08:45 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstsearch(t_list *env, char *searched)
{
	int	len;

	len = ft_strlen(searched);
	while (env)
	{
		if (ft_strncmp(searched, env->content, len) == 0
			&& env->content[len] == '=')
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
	char	*name;

	i = 0;
	while (is_whitespace(data->str[i]) == TRUE)
		i++;
	i += 5;
	name = find_next_name(data, i);
	to_del = ft_lstsearch(data->envp, name);
	if (to_del == NULL)
		return ;
	next = to_del->next;
	previous = data->envp;
	if (to_del == previous)
		data->envp = next;
	while (previous->next != to_del)
		previous = previous->next;
	ft_lstdelone(to_del, &free);
	previous->next = next;
	free(name);
}
