/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:01:41 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 17:01:43 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	s(int *array, int size_array)
{
	int	tmp;

	if (size_array < 2)
		return ;
	tmp = array[size_array - 1];
	array[size_array - 1] = array[size_array - 2];
	array[size_array - 2] = tmp;
}

void	p(int *array1, int *size_array1, int *array2, int *size_array2)
{
	array2[*size_array2] = array1[*size_array1 - 1];
	*size_array1 -= 1;
	*size_array2 += 1;
}

int	r(int *array, int size_array)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = (int *)malloc(sizeof(int) * size_array);
	if (!tmp)
		return (-1);
	while (i < size_array - 1)
	{
		tmp[i + 1] = array[i];
		i++;
	}
	tmp[0] = array[size_array - 1];
	i = 0;
	while (i < size_array)
	{
		array[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (0);
}

int	rev_r(int *array, int size_array)
{
	int	i;
	int	*tmp;

	i = size_array;
	tmp = (int *)malloc(sizeof(int) * size_array);
	if (!tmp)
		return (-1);
	while (--i)
		tmp[i - 1] = array[i];
	tmp[size_array - 1] = array[0];
	i = 0;
	while (i < size_array)
	{
		array[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (0);
}
