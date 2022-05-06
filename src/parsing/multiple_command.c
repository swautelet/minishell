/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:01:11 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/06 14:01:15 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_multiple_command(t_param *data, char **envp)
{
	char	**commands;
	int		i;
	char	*temp;

	temp = "";
	i = 0;
	while (i != -1)
	{
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n' || data->str[i] == '\r'
		|| data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		temp = find_next_element(data, i);
		i += ft_strlen(temp);
		if (temp == NULL)
			i = -1;
		free (temp);
	}
	commands = ft_split(data->str, ';');
	i = 0;
	if (commands)
	{
		while (commands[i] != NULL)
		{
			data->str = commands[i];
			just_parse_it(data, envp);
			i++;
		}
	}
	// printf("commands = %p\n", commands);
	free(commands);
}
