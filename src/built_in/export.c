/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:13 by swautele          #+#    #+#             */
/*   Updated: 2022/05/19 14:32:22 by swautele         ###   ########.fr       */
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

// void	free_table(char **str)
// {
// 	int	i;

// 	i = -1;
// 	while (str[++i])
// 		free (str[i]);
// 	free (str);
// }

void	export_env(t_param *data)
{
	t_list	*new;
	char	*copy;
	int		i;
	int		j;

	i = 6;
	while (is_whitespace(data->str[i]) == TRUE)
		i++;
	copy = ft_calloc(sizeof(char), ft_strlen(&data->str[i]) + 1);
	j = 0;
	while (data->str[i + j])
	{
		copy[j] = data->str[i + j];
		j++;
	}
	new = ft_lstnew(copy);
	ft_lstadd_back(&data->envp, new);
}
