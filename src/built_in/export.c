/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:13 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 15:02:24 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	size_table(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (-1);
	while (env[i])
	{
		i++;
	}
	return (i);
}

char	*find_variable_name(char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (!str[i])
		return (NULL);
	name = ft_calloc(sizeof(char), i + 1);
	while (--i >= 0)
		name[i] = str[i];
	return (name);
}

void	remove_escape_string(char *str)
{
	t_skip	f;

	f.flag = 0;
	f.decal = 0;
	while (str[++f.j] && str[f.j + f.decal])
	{
		if (str[f.j] == "'"[0] || str[f.j] == '"')
		{
			f.flag = str[f.j];
			f.decal++;
		}
		else if (f.flag != 0 && str[f.j + f.decal] == f.flag)
		{
			f.flag = 0;
			f.decal++;
		}
		str[f.j] = str[f.j + f.decal];
	}
}

void	export_env(t_param *data)
{
	t_list	*new;
	char	*copy;
	char	*name;
	int		i;
	int		j;

	i = 6;
	while (is_whitespace(data->str[i]) == TRUE)
		i++;
	name = find_variable_name(&data->str[i]);
	if (name == NULL)
		return ;
	copy = ft_calloc(sizeof(char), ft_strlen(&data->str[i]) + 1);
	j = 0;
	while (data->str[i + j])
	{
		copy[j] = data->str[i + j];
		j++;
	}
	remove_escape_string(copy);
	new = ft_lstsearch(data->envp, name);
	free(name);
	if (new == NULL)
	{
		new = ft_lstnew(copy);
		ft_lstadd_back(&data->envp, new);
	}
	else
	{
		free(new->content);
		new->content = copy;
	}
}
