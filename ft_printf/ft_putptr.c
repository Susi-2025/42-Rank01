/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:56:58 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/20 19:35:18 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putptr(unsigned long ptr, char *base, int i)
{
	int				res;

	res = 0;
	res += ft_putstr("0x");
	res += ft_putnbr_base(ptr, base, i);
	return (res);
}
