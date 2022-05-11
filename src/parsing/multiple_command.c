/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:01:11 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/11 14:23:49 by simonwautel      ###   ########.fr       */
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
	while (data->str[i])
	{
		while (data->str[i] == ' ' || data->str[i] == '\f' || data->str[i] == '\n' || data->str[i] == '\r'
		|| data->str[i] == '\t' || data->str[i] == '\v')
			i++;
		temp = find_next_element(data, i);
		// printf("find_next_element found = %s\n", temp);
		i += ft_strlen(temp);
		// if (temp == NULL || temp[0] == '\0')
			// i = -1;
		free (temp);
	}
	data->str = insert_variable(data->str);
	// printf("data->str = %s\n", data->str);
	commands = split_with_escape(data->str, ';');
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
	// write_table(envp);
	// printf("commands = %p\n", commands);
	free(commands);
}
