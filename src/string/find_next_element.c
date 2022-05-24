/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:42:12 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 13:32:23 by simonwautel      ###   ########.fr       */
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

static void	without_escape(t_param *data, int *i, int *j, char *begin)
{
	while (data->str[*i + *j] && is_whitespace(data->str[*i + *j]) == FALSE)
	{
		*j++;
		if ((data->str[*i + *j] == "'"[0] || data->str[*i + *j] == '"')
			&& *begin == 0)
		{
			j--;
			break ;
		}
	}
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
		begin = data->str[i];
	else
		begin = 0;
	j = 0;
	if (begin != 0)
		with_escape(data, &i, &j, &begin);
	else
		without_escape(data, &i, &j, &begin);
	new = calloc(j + 1, sizeof(char));
	if (!new)
		return (NULL);
	k = -1;
	while (k++ < j)
		new[k] = data->str[i + k];
	return (new);
}
