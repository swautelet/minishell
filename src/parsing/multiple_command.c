/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:01:11 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/24 16:16:39 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_multiple_command(t_param *data)
{
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
	just_parse_it(data);
}
