/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdl_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcohen <lcohen@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:24:56 by lcohen            #+#    #+#             */
/*   Updated: 2026/11/20 19:44:50 by lcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CDL_LST_H
# define FT_CDL_LST_H

typedef struct s_radix_elem
{
	int						val;
	unsigned int			radix_int;
}	t_radix_elem;

typedef struct s_cdl_lst
{
	void				*data;
	struct s_cdl_lst	*next;
	struct s_cdl_lst	*prev;
}	t_cdl_lst;

t_cdl_lst	*ft_cdl_lst_new(void);
t_cdl_lst	*ft_cdl_lst_val_new(int val);
void		ft_cdl_lst_delete(t_cdl_lst	**list_head);
int			ft_cdl_lst_get_size(t_cdl_lst *self);
t_cdl_lst	*ft_cdl_lst_pop(t_cdl_lst **self);
void		ft_cdl_lst_pop_push(t_cdl_lst **self, t_cdl_lst **other);
void		ft_cdl_lst_push_back(t_cdl_lst **self, t_cdl_lst *new_node);
void		ft_cdl_lst_push_back_val(t_cdl_lst **self, int val);
void		ft_cdl_lst_push_front(t_cdl_lst **self, t_cdl_lst *new_node);
void		ft_cdl_lst_push_front_val(t_cdl_lst **self, int val);
void		ft_cdl_lst_radix_index(t_cdl_lst *self);
void		ft_cdl_lst_rotate(t_cdl_lst **self);
void		ft_cdl_lst_rrotate(t_cdl_lst **self);
void		ft_cdl_lst_swap(t_cdl_lst *self);
void		ft_cdl_lst_display(t_cdl_lst *self);

#endif
