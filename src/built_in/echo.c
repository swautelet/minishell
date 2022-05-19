/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:10 by swautele          #+#    #+#             */
/*   Updated: 2022/05/19 16:32:49 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	write_echo(char *str)
{
	int 	i;
	char	flag;
	int		j;
	char 	*copy;

	i = 4;
	while(is_whitespace(str[i]) == TRUE)
			i++;
	flag = 0;
	j = 0;
	copy = ft_calloc(sizeof(char), ft_strlen(&str[i]));
	while (str[i])
	{
		if ((str[i] == '"' || str[i] == "'"[0]) && flag == 0)
		{
			flag = str[i];
			i++;
		}
		if ((str[i] == '"' || str[i] == "'"[0]) && flag != 0)
		{
			flag = 0;
			i++;
		}
		if (flag == 0 && is_whitespace(str[i]) == TRUE)
		{
			copy[j] = str[i];
			j++;
			i++;
			while (is_whitespace(str[i]) == TRUE)
				i++;
		}
		copy[j] = str[i];
		j++;
		i++;
	}
	printf("%s", copy);
	free(copy);
}
