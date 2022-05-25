/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:17:41 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/25 10:22:17 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_count(const char *str, const char c)
{
	size_t	l;

	l = 0;
	while (*str)
	{
		while (*str && *str == c)
		{
			str++;
		}
		if (*str != c && *str)
			l++;
		while (*str && *str != c)
		{
			str++;
		}
	}
	return (l);
}

void	minishell_free_and_exit(void)
{
	ft_lstclear(g_data, &free);
	perror("Not enough space to malloc can't keep going\n");
	exit(-1);
}
