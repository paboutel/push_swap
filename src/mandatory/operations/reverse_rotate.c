/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:01:50 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 17:01:52 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_core.h"

#include "ft_printf.h"

void	rra(t_list *list)
{
	if (rev_r(list->a, list->size_a) == -1)
		ft_error(list);
	ft_printf("rra\n");
}

void	rrb(t_list *list)
{
	if (rev_r(list->b, list->size_b) == -1)
		ft_error(list);
	ft_printf("rrb\n");
}

void	rrr(t_list *list)
{
	if (rev_r(list->a, list->size_a) == -1)
		ft_error(list);
	if (rev_r(list->b, list->size_b) == -1)
		ft_error(list);
	ft_printf("rrr\n");
}
