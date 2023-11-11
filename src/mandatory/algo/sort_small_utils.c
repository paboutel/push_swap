/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:00:49 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 17:00:53 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_index(int *a, int size_a, int to_insert)
{
	int	i;

	i = 0;
	if (to_insert < a[size_a - 1])
		return (size_a);
	while (to_insert < a[i])
		i++;
	return (i);
}

int	does_b_need_swap(int *a, int *b, int size_a, int size_b)
{
	return ((size_b == 2) && ((b[1] > a[find_min(a, size_a)] && b[0] > b[1])
			|| (b[1] < a[find_min(a, size_a)]
				&& b[0] < a[find_min(a, size_a)]
				&& b[0] > b[1]) || (b[1] > a[find_min(a, size_a)]
				&& b[0] < a[find_min(a, size_a)])));
}
