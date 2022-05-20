/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:42:12 by swautele          #+#    #+#             */
/*   Updated: 2022/05/20 15:08:48 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_next_escape(char *str)
{
	char	*temp;
	char	*temp1;
	char	*read;

	read = readline("> ");
	temp1 = ft_strjoin(str, "\n");
	temp = ft_strjoin(temp1, read);
	free(read);
	free(temp1);
	free(str);
	return (temp);
}

char	*find_next_element(t_param *data, int i)
{
	int		j;
	char	begin;
	char	*new;
	int		k;

	while (is_whitespace(data->str[i]) == TRUE)
		i++;
	if (!data->str[i])
		return (NULL);
	else if (data->str[i] == "'"[0] || data->str[i] == '"')
	{
		begin = data->str[i];
	}
	else
		begin = 0;
	j = 0;
	if (begin != 0)
	{
		while (data->str[i + j] && (data->str[i + j] != begin || j == 0))
		{
			j++;
			if (!data->str[i + j])
			{
				data->str = find_next_escape(data->str);
			}
			else if (data->str[i + j] == begin)
			{
				break ;
			}
		}
	}
	else
	{
		while (data->str[i + j] && is_whitespace(data->str[i + j]) == FALSE)
		{
			j++;
			if ((data->str[i + j] == "'"[0] || data->str[i + j] == '"')
					&& begin == 0)
			{
				j--;
				break ;
			}
		}
	}
	new = calloc(j + 1, sizeof(char));
	if (!new)
		return (NULL);
	k = -1;
	while (k++ < j)
		new[k] = data->str[i + k];
	return (new);
}
