/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 15:39:19 by swautele          #+#    #+#             */
/*   Updated: 2022/05/24 13:51:57 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalnum(char c)
{
	if (ft_isalpha (c) == 1 || ft_isdigit (c) == 1 || ft_isalpha (c) == 2)
		return (1);
	else
		return (0);
}
