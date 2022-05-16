/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:42:12 by swautele          #+#    #+#             */
/*   Updated: 2022/05/16 16:39:10 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	find_closure(char *str, char begin, int i)
// {
// 	// int	i;

// 	// i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == begin)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

char	*find_next_escape(char *str)
{
	char	*temp;
	char	*temp1;
	char	*read;

	read = readline(">");
	temp1 = ft_strjoin(str, "\n");
	temp = ft_strjoin(temp1, read);
	free (read);
	free (temp1);
	free (str);
	return (temp);
}

// char	*find_next_escape(char begin, int i, char *str, char flag)
// {
// 	char	*add;
// 	char	*new;
// 	// int		start;

// 	// start = i;
// 	// printf("flag = %d\n", (int)flag);
// 	while (str[++i])
// 	{
// 		// if (str[i] == begin && flag == 0)
// 			// flag++;
// 		if (str[i] == begin && flag == 1)
// 		{
// 			flag--;
// 			break ;
// 		}
// 	}
// 	new = str;
// 	printf("flag = %d\n", (int)flag);
// 	if (flag == 1)
// 	{
// 		add = readline(">");
// 		new = ft_strjoin(str, add);
// 		printf("new = %s\n", new);
// 		// printf("str = %p add = %p\n", str, add);
// 		// free (str);
// 		free (add);
// 		printf("find closure = %d\n", find_closure(new, begin, i));
// 		if (find_closure(new, begin, i) == 1)
// 		{
// 			add = ft_strjoin(new, "\n");
// 			free (new);
// 			new = find_next_escape(begin, i, add, flag);
// 		}
// 		// while (find_closure(&new[i], begin))
// 		// {
// 		// 	add = readline("dquote>");
// 		// 	new = ft_strjoin(new, add);
// 		// 	free (str);
// 		// 	free (add);
// 		// }
// 	}
// 	return (new);
// }

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
	j = 1;
	if (begin != 0)
	{
		while (data->str[i + j] && data->str[i + j] != begin)
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
			if ((data->str[i + j] == "'"[0] || data->str[i + j] == '"') && begin == 0)
			{
				begin = data->str[i + j];
			}
			else if (data->str[i + j] == begin && begin != 0)
			{
				begin = 0;
			}
			else if (!data->str[i + j] && begin != 0)
			{
				data->str = find_next_escape(data->str);
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
