/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:44:21 by kblanche          #+#    #+#             */
/*   Updated: 2026/11/20 19:43:42 by lcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cdl_lst.h"
#include <stddef.h>
#include <stdlib.h>

t_ilist	*ft_ilist_new(void)
{
	t_ilist	*ret;

	ret = malloc(sizeof(t_ilist));
	if (!ret)
		return (NULL);
	ret->val = 0;
	ret->radix_index = 0;
	ret->next = ret;
	ret->prev = ret;
	return (ret);
}

t_ilist	*ft_ilist_val_new(int val)
{
	t_ilist	*ret;

	ret = malloc(sizeof(t_ilist));
	if (!ret)
		return (NULL);
	ret->val = val;
	ret->radix_index = 0;
	ret->next = ret;
	ret->prev = ret;
	return (ret);
}
