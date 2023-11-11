/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:58:53 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 16:58:55 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

void	sa(int *a, int size_a);
void	sb(int *b, int size_b);
void	ss(int *a, int *b, int size_a, int size_b);
void	pa(int *a, int *size_a, int *b, int *size_b);
void	pb(int *b, int *size_b, int *a, int *size_a);

void	ra(t_list *list);
void	rb(t_list *list);
void	rr(t_list *list);

void	rra(t_list *list);
void	rrb(t_list *list);
void	rrr(t_list *list);

#endif
