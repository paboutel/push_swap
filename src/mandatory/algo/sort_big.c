/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:59:57 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 17:00:00 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "algo.h"
#include <stdlib.h>

static void	put_chunks_a_b(t_list *list)
{
	int	n_r[2];
	int	chunk;

	chunk = 0;
	while (list->size_a)
	{
		n_r[0] = 0;
		n_r[1] = 0;
		while (n_r[0] < list->size_a && what_chunk(list->all_chunk,
				list->a[list->size_a - 1 - n_r[0]]) != chunk)
			n_r[0]++;
		while (n_r[1] < list->size_a && what_chunk(list->all_chunk,
				list->a[n_r[1]]) != chunk)
			n_r[1]++;
		if (n_r[0] == list->size_a && n_r[1] == list->size_a)
			chunk++;
		else if (n_r[0] <= n_r[1])
			while (n_r[0]--)
				ra(list);
		else
			while (n_r[1]-- + 1)
				rra(list);
		if (n_r[0] != list->size_a || n_r[1] != list->size_a)
			pb(list->b, &list->size_b, list->a, &list->size_a);
	}
}

static void	put_b_a(t_list *list)
{
	int	i;

	while (list->size_b)
	{
		i = find_max(list->b, list->size_b);
		if (i == list->size_b - 2)
			sb(list->b, list->size_b);
		else if (i >= list->size_b / 2)
			while (list->size_b - ++i)
				rb(list);
		else
			while (i-- + 1)
				rrb(list);
		pa(list->a, &list->size_a, list->b, &list->size_b);
	}
}

void	sort_big(t_list *list)
{
	int	i;

	i = 0;
	list->chunks = 11 - ((list->size_a <= 100) * 5);
	list->all_chunk = (int **)malloc(sizeof(int *) * 2);
	if (!list->all_chunk)
		ft_error(list);
	list->all_chunk[0] = create_all_chunk(list->a, list->size_all_chunk);
	list->all_chunk[1] = (int *)malloc(sizeof(int) * list->size_a);
	if (!list->all_chunk[0] || !list->all_chunk[1])
		ft_error(list);
	while (i < list->size_all_chunk)
	{
		list->all_chunk[1][i] = gen_chunk(list->all_chunk[0],
				list->size_all_chunk, list->all_chunk[0][i], list->chunks);
		if (list->all_chunk[1][i] == -1)
			ft_error(list);
		i++;
	}
	put_chunks_a_b(list);
	put_b_a(list);
	free(list->all_chunk[0]);
	free(list->all_chunk[1]);
	free(list->all_chunk);
}
