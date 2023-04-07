/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:08:02 by pramos-m          #+#    #+#             */
/*   Updated: 2022/10/17 18:23:31 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(char const *s, ...);
int		ft_print_char(char const c, int count);
int		ft_print_str(char const *str, int count);
int		ft_print_decimal(int n, int count);
int		ft_print_pointer(void *p, int count);
int		ft_print_unsigned(unsigned int n, int count);
int		ft_print_hexa_low(unsigned int hexa, int count);
int		ft_print_hexa_up(unsigned int hexa, int count);

#endif