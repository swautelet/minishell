/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:42:12 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 19:02:30 by swautele         ###   ########.fr       */
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

static int	without_escape(t_param *data, int *i, int j, char *begin)
{
	while (data->str[*i + j] && is_whitespace(data->str[*i + j]) == FALSE)
	{
		j++;
		if ((data->str[*i + j] == "'"[0] || data->str[*i + j] == '"')
			&& *begin == 0)
		{
			j--;
			break ;
		}
	}
	return (j);
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
		j = with_escape(data, &i, j, &begin);
	else
		j = without_escape(data, &i, j, &begin);
	new = calloc(j + 2, sizeof(char));
	if (!new)
		return (NULL);
	k = -1;
	while (k++ < j && data->str[i + k] && new[k])
		new[k] = data->str[i + k];
	return (new);
}
