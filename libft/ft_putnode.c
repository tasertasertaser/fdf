/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschulle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:18:16 by cschulle          #+#    #+#             */
/*   Updated: 2018/12/24 14:27:36 by cschulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnode(t_list *node)
{
	ft_putstr(node->content);
	ft_putstr(" (");
	ft_putnbr(node->content_size);
	ft_putstr(")\n");
}
