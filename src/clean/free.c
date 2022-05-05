/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:08:45 by simonwautel       #+#    #+#             */
/*   Updated: 2022/05/05 13:11:05 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_table(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i] != NULL)
		{
			free(strs[i]);
			i++;
		}
		free (strs);
	}
}
