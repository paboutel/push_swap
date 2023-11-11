/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:58:39 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 16:58:42 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

void	sort_small(t_list *list);
void	sort_big(t_list *list);

int		insert_index(int *a, int size_a, int to_insert);
int		does_b_need_swap(int *a, int *b, int size_a, int size_b);

int		what_chunk(int **all_chunk, int number);
int		*create_all_chunk(int *a, int size_all_chunk);
int		gen_chunk(int *all_chunk, int size_all_chunk, int number, int chunks);

#endif
