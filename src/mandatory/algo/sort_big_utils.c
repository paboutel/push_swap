/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:00:10 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 17:00:13 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	sort_all_chunk(int *all_chunk, int size_all_chunk)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < size_all_chunk - 1)
	{
		if (all_chunk[i] > all_chunk[i + 1])
		{
			tmp = all_chunk[i];
			all_chunk[i] = all_chunk[i + 1];
			all_chunk[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

int	what_chunk(int **all_chunk, int number)
{
	int	i;

	i = 0;
	while (all_chunk[0][i] != number)
		i++;
	return (all_chunk[1][i]);
}

int	*create_all_chunk(int *a, int size_all_chunk)
{
	int	*all_chunk;
	int	i;

	all_chunk = (int *)malloc(sizeof(int) * size_all_chunk);
	if (!all_chunk)
		return ((int *) NULL);
	i = 0;
	while (i < size_all_chunk)
	{
		all_chunk[i] = a[i];
		i++;
	}
	sort_all_chunk(all_chunk, size_all_chunk);
	return (all_chunk);
}

static int	*calc_chunk(int chunks, int size_all_chunk)
{
	int	i;
	int	j;
	int	k;
	int	*l;

	i = 0;
	j = 0;
	k = 0;
	l = (int *)malloc(sizeof(int) * chunks);
	if (!l)
		return ((int *) NULL);
	while (i < chunks)
		l[i++] = 0;
	while (j < size_all_chunk)
	{
		j = 0;
		i = 0;
		while (i < chunks)
			j += l[i++];
		l[k]++;
		k++;
		if (k == chunks)
			k = 0;
	}
	return (l);
}

int	gen_chunk(int *all_chunk, int size_all_chunk, int number, int chunks)
{
	int	i;
	int	j;
	int	k;
	int	*l;

	i = 0;
	j = 0;
	k = 0;
	l = calc_chunk(chunks, size_all_chunk);
	if (!l)
		return (-1);
	while (i < size_all_chunk)
	{
		if (number == all_chunk[i])
			break ;
		i++;
		j++;
		if (j == l[k])
		{
			j = 0;
			k++;
		}
	}
	free(l);
	return (k);
}
