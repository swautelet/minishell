/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:15 by swautele          #+#    #+#             */
/*   Updated: 2022/05/18 13:56:20 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	where_am_i(t_param *data)
{
	char	*pos;

	pos = getenv("PWD");
	(void)data;
	write(1, pos, ft_strlen(pos));
	write(1, "\n", 1);
}
