/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:56:58 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/21 11:20:49 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
