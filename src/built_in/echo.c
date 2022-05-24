/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:10 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 16:52:50 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	echo_loop(int i, char *str, char *copy)
{
	char	flag;
	int		j;

	flag = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '"' || str[i] == "'"[0]) && flag == 0)
			flag = str[i];
		else if (flag == str[i] && flag != 0)
			flag = 0;
		else if (flag == 0 && is_whitespace(str[i]) == TRUE)
		{
			copy[j++] = str[i];
			while (is_whitespace(str[i + 1]) == TRUE)
				i++;
		}
		else
			copy[j++] = str[i];
		i++;
	}
}

void	write_echo(char *str)
{
	int		i;
	char	*copy;
	char	flag_n;

	printf("i received %s\n", str);
	flag_n = FALSE;
	i = 4;
	while (is_whitespace(str[i]) == TRUE)
		i++;
	if (str[i] == '-' && str[i + 1] == 'n')
	{
		i = i + 2;
		flag_n = TRUE;
	}
	copy = ft_calloc(sizeof(char), ft_strlen(&str[i]) + 1);
	echo_loop(i, str, copy);
	printf("%s", copy);
	free(copy);
	if (flag_n == FALSE)
		printf("\n");
}
