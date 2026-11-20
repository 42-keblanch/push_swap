/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilist_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcohen <lcohen@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 19:28:17 by lcohen            #+#    #+#             */
/*   Updated: 2026/11/20 20:03:36 by lcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cdl_lst.h"

void	ft_ilist_swap(t_ilist *self)
{
	unsigned int	temp;

	if (self->next)
	{
		temp = self->next->val;
		self->next->val = self->val;
		self->val = temp;
		temp = self->next->radix_index;
		self->next->radix_index = self->radix_index;
		self->radix_index = temp;
	}
}
