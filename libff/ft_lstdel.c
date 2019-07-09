/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:53:41 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/21 20:01:13 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *jump;

	while (*alst)
	{
		jump = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = jump;
	}
}
