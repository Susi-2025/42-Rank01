/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:39:11 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/26 12:24:56 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putptr(void *ptr, char *base, int i);
int		ft_putnbr_base(long long number, char *base, int i);
int		ft_putnbr_base_unsigned(unsigned long long number, char *base, int i);
int		check_format(va_list args, const char *string, int i);
int		check_string(va_list args, const char *string, int i);
char	*ft_strchr(const char *str, char c);
int		ft_printf(const char *string, ...);

#endif
