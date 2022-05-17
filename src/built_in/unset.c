/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:18 by swautele          #+#    #+#             */
/*   Updated: 2022/05/17 17:38:04 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env(t_param *data)
{
	int		i;
	char	*name;

	i = 5;
	while (is_whitespace(data->str[i]) == TRUE)
		i++;
	name = find_next_name(data, i);
	i = 0;
	while (strncmp(data->envp[i], name, ft_strlen(name)))
		i++;
	data->envp[i][0] = '\0';
	free (name);
}
