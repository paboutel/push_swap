/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:00:23 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 17:00:25 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algo.h"

static void	sort_2(int *a, int *size_a)
{
	sa(a, *size_a);
	return ;
}

static void	sort_3(int *a, t_list *list)
{
	if ((a[1] < a[2] && a[1] < a[0] && a[2] < a[0]) || (a[1] > a[0]
			&& a[1] < a[2]) || (a[1] > a[0] && a[1] > a[2] && a[2] < a[0]))
	{
		if (does_b_need_swap(list->a, list->b, list->size_a, list->size_b))
			ss(list->a, list->b, list->size_a, list->size_b);
		else
			sa(list->a, list->size_a);
	}
	if (a[1] < a[0] && a[1] < a[2] && a[2] > a[0])
	{
		if (does_b_need_swap(list->a, list->b, list->size_a, list->size_b))
			rr(list);
		else
			ra(list);
	}
	else if (a[1] > a[0] && a[1] > a[2] && a[2] > a[0])
	{
		if (does_b_need_swap(list->a, list->b, list->size_a, list->size_b))
			rrr(list);
		else
			rra(list);
	}
}

static void	insert_1(t_list *list)
{
	int	index;

	index = insert_index(list->a, list->size_a, list->b[0]);
	if (index > (list->size_a - 1) / 2)
		while (list->size_a - index++)
			ra(list);
	else
		while (index--)
			rra(list);
	pa(list->a, &list->size_a, list->b, &list->size_b);
}

static void	insert_2(t_list *list)
{
	if (list->b[1] < list->a[list->size_a - 1])
		pa(list->a, &list->size_a, list->b, &list->size_b);
	if (list->b[0] < list->a[list->size_a - 1])
	{
		if (list->size_b == 2)
			sb(list->b, list->size_b);
		pa(list->a, &list->size_a, list->b, &list->size_b);
	}
	if (list->size_b == 2 && list->b[0] > list->b[1])
		sb(list->b, list->size_b);
	while (list->size_b)
	{
		if (list->b[list->size_b - 1] > list->a[0])
			pa(list->a, &list->size_a, list->b, &list->size_b);
		else
			rra(list);
	}
}

void	sort_small(t_list *list)
{
	if (list->size_a == 2)
		return (sort_2(list->a, &list->size_a));
	while (list->size_a != 3)
		pb(list->b, &list->size_b, list->a, &list->size_a);
	sort_3(list->a, list);
	if (list->size_b == 1)
		insert_1(list);
	else if (list->size_b == 2)
		insert_2(list);
	if (find_min(list->a, list->size_a) < ((list->size_a - 1) / 2))
		while (!is_array_sorted(list->a, list->size_a))
			rra(list);
	else
		while (!is_array_sorted(list->a, list->size_a))
			ra(list);
}
