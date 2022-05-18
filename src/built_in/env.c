/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:07:23 by swautele          #+#    #+#             */
/*   Updated: 2022/05/18 15:10:23 by swautele         ###   ########.fr       */
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