/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:01:19 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 17:01:21 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char	const c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoimod(char const *s, int *ptr)
{
	long int	i;
	int			minus;

	i = 0;
	minus = 1;
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			minus -= 2;
		s++;
	}
	if (!*s)
		return (-1);
	while (*s && *s >= '0' && *s <= '9' && i <= 2147483647)
		i = i * 10 + (long int)*s++ - 48;
	while (*s)
		if (*s && !ft_isspace(*s++))
			return (-1);
	if ((i > 2147483647 && !minus) || (-i < -2147483648))
		return (-1);
	*ptr = (int)(i * minus);
	return (0);
}

int	find_min(int *array, int size_array)
{
	int	i;
	int	index_min;

	i = 0;
	index_min = 0;
	while (i < size_array)
	{
		if (array[i] < array[index_min])
			index_min = i;
		i++;
	}
	return (index_min);
}

int	find_max(int *array, int size_array)
{
	int	i;
	int	index_max;

	i = 0;
	index_max = 0;
	while (i < size_array)
	{
		if (array[i] > array[index_max])
			index_max = i;
		i++;
	}
	return (index_max);
}

int	is_array_sorted(int *array, int size_array)
{
	while (--size_array)
		if (array[size_array] > array[size_array - 1])
			return (0);
	return (1);
}
