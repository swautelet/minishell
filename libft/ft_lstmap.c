/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:59:04 by swautele          #+#    #+#             */
/*   Updated: 2021/09/30 18:21:29 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	ft_lstcopy(t_list *lst, t_list *new, void *(*f)(void *))
{
	if (lst != NULL)
	{
		new->next = ft_lstnew(f(lst->content));
		ft_lstcopy(lst->next, new->next, f);
	}
	else
		new->next = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (!lst || !*f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	ft_lstcopy(lst->next, new, f);
	if (ft_lstsize(new) != ft_lstsize(lst))
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	return (new);
}
