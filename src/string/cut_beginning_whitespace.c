/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_beginning_whitespace.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:16:43 by swautele          #+#    #+#             */
/*   Updated: 2022/05/23 15:20:20 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cut_beginning_whitespace(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (is_whitespace(str[i]))
		i++;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
}
