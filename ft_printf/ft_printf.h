/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:12:34 by alaassir          #+#    #+#             */
/*   Updated: 2024/02/05 04:05:11 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		ft_printf(const char *str, ...);
int		ft_putchar_prnt(char c);
int		ft_putnbr_base(long nbr, char *base);
int		ft_putstr_prnt(char *s);
size_t	ft_strlen_prnt(const char *str);
int		print_ptr(void *ptr);

#endif
