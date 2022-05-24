/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:07:23 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 12:34:18 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_list *env)
{
	while (env->next)
	{
		printf("%s\n", env->content);
		env = env->next;
	}
	printf("%s\n", env->content);
}
