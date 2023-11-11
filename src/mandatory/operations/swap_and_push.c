/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:02:10 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 17:02:11 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_core.h"
#include "ft_printf.h"

void	sa(int *a, int size_a)
{
	s(a, size_a);
	ft_printf("sa\n");
}

void	sb(int *b, int size_b)
{
	s(b, size_b);
	ft_printf("sb\n");
}

void	ss(int *a, int *b, int size_a, int size_b)
{
	s(a, size_a);
	s(b, size_b);
	ft_printf("ss\n");
}

void	pa(int *a, int *size_a, int *b, int *size_b)
{
	p(b, size_b, a, size_a);
	ft_printf("pa\n");
}

void	pb(int *b, int *size_b, int *a, int *size_a)
{
	p(a, size_a, b, size_b);
	ft_printf("pb\n");
}
