/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:59:12 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 16:59:14 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_list	t_list;

struct	s_list
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	chunks;
	int	**all_chunk;
	int	size_all_chunk;
};

void	ft_error(t_list *list);
void	algo(t_list *list, int ac);

int		ft_atoimod(char const *s, int *ptr);
int		find_min(int *array, int size_array);
int		find_max(int *array, int size_array);
int		is_array_sorted(int *array, int ac);

#endif
