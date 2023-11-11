/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:02:00 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 17:02:03 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_core.h"
#include "ft_printf.h"

void	ra(t_list *list)
{
	if (r(list->a, list->size_a) == -1)
		ft_error(list);
	ft_printf("ra\n");
}

void	rb(t_list *list)
{
	if (r(list->b, list->size_b) == -1)
		ft_error(list);
	ft_printf("rb\n");
}

void	rr(t_list *list)
{
	if (r(list->a, list->size_a) == -1)
		ft_error(list);
	if (r(list->b, list->size_b) == -1)
		ft_error(list);
	ft_printf("rr\n");
}
