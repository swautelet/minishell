/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:01:11 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/19 13:26:54 by swautele         ###   ########.fr       */
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
		// printf("temp  = %s\n", temp);
		i += ft_strlen(temp);
		free (temp);
	}
	if (data->str && *data->str)
		add_history (data->str);
	data->str = insert_variable(data->str);
	// printf("data->str = %s\n", data->str);
	commands = split_with_escape(data->str, ';');
	i = 0;
	if (commands)
	{
		while (commands[i] != NULL)
		{
			data->str = commands[i];
			check_built_in(data);
			just_parse_it(data);
			i++;
		}
	}
	free(commands);
}
