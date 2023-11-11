/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paboutel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:57:28 by paboutel          #+#    #+#             */
/*   Updated: 2021/10/18 16:57:31 by paboutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

unsigned int	ft_strlen(char *str);

int				ft_putchar(char c);
int				ft_putstr(char *str);

int				ft_putbase(long long int n, char *base);
int				ft_putbase_address(unsigned long int n, char *base);

int				ft_printf(const char *str, ...);

#endif
