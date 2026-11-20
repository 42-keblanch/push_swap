/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilist_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:43:46 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/20 19:43:38 by lcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cdl_lst.h"

void	ft_ilist_rotate(t_ilist **self)
{
	if ((*self)->next)
		*self = (*self)->next;
}

void	ft_ilist_rrotate(t_ilist **self)
{
	if ((*self)->prev)
		*self = (*self)->prev;
}
