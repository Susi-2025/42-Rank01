/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:23:21 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/21 14:26:27 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putnbr_base(long long number, char *base, int i)
{
	int	res;

	res = 0;
	if (number < 0)
	{
		number = -number;
		res += ft_putchar('-');
	}
	if (number / i > 0)
		res += ft_putnbr_base(number / i, base, i);
	res += ft_putchar(base[number % i]);
	return (res);
}
