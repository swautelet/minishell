/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:57:57 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 17:04:46 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lst_replace_content(t_list *node, char *str)
{
	free(node->content);
	node->content = str;
}

void	ft_lst_addback_new(t_list *node, char *str)
{
	t_list	*new;

	new = ft_lstnew(str);
	ft_lstadd_back(&node, new);
}
