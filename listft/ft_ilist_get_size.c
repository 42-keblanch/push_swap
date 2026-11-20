/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilist_get_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:17:22 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/20 19:43:44 by lcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cdl_lst.h"

int	ft_ilist_get_size(t_ilist *self)
{
	int		ret;
	t_ilist	*temp;

	if (!self)
		return (0);
	ret = 1;
	temp = self;
	while (temp->next && temp->next != self)
	{
		++ret;
		temp = temp->next;
	}
	return (ret);
}
