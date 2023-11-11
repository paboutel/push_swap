/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:59:45 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 16:59:48 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algo.h"
#include <stdlib.h>

void	algo(t_list *list, int ac)
{
	list->size_a = ac - 1;
	list->size_b = 0;
	list->size_all_chunk = list->size_a;
	list->b = (int *)malloc(sizeof(int) * (ac - 1));
	if (!list->b)
		ft_error(list);
	if (list->size_a <= 5)
		sort_small(list);
	else
		sort_big(list);
	free(list->b);
}
