/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 15:16:41 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/24 19:11:01 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlist(t_list **head)
{
	t_list *node;

	node = *head;
	while (node->next)
	{
		ft_putnode(node);
		node = node->next;
	}
}
