/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:01:11 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/24 12:56:43 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_multiple_command(t_param *data)
{
	char	**commands;
	int		i;
	char	*temp;

	temp = "";
	i = 0;
	while (data->str[i])
	{
		while (is_whitespace(data->str[i]) == TRUE)
			i++;
		temp = find_next_element(data, i);
		i += ft_strlen(temp);
		free(temp);
	}
	if (data->str && *data->str)
		add_history(data->str);
	cut_beginning_whitespace(data->str);
	commands = split_with_escape(data->str, ';');
	i = 0;
	if (commands)
	{
		while (commands[i] != NULL)
		{
			data->str = commands[i];
			just_parse_it(data);
			i++;
		}
	}
	free(commands);
}
