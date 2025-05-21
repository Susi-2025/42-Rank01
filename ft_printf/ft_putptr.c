/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:56:58 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/21 16:46:44 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr(void *ptr, char *base, int i)
{
	int					res;
	unsigned long long	add;

	res = 0;
	add = (unsigned long long)ptr;
	res += ft_putstr("0x");
	res += ft_putnbr_base(add, base, i);
	return (res);
}
