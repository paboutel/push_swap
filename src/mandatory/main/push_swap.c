/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:01:30 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 17:01:32 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_error(t_list *list)
{
	if (list->a)
		free(list->a);
	if (list->b)
		free(list->b);
	if (list->all_chunk)
	{
		if (list->all_chunk[0])
			free(list->all_chunk[0]);
		if (list->all_chunk[1])
			free(list->all_chunk[1]);
		free(list->all_chunk);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static int	ft_parse_error(int ac, char **av)
{
	int	i;
	int	j;
	int	ptra;
	int	ptrb;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		if (ft_atoimod(av[i++], &ptra) == -1)
			return (-1);
		while (j < ac)
		{
			ft_atoimod(av[j++], &ptrb);
			if (ptra == ptrb)
				return (-1);
		}
	}
	return (0);
}

static void	build_array(int *array, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
		ft_atoimod(av[i], &array[ac - 1 - i]);
}

int	main(int ac, char **av)
{
	t_list	list;

	if (ac == 1)
		exit(EXIT_SUCCESS);
	list.a = NULL;
	list.b = NULL;
	list.all_chunk = NULL;
	list.a = (int *)malloc(sizeof(int) * (ac - 1));
	if (!list.a)
		ft_error(&list);
	build_array(list.a, ac, av);
	if (ft_parse_error(ac, av) == -1)
		ft_error(&list);
	if (!is_array_sorted(list.a, (ac - 1)))
		algo(&list, ac);
	free(list.a);
	exit(EXIT_SUCCESS);
}
