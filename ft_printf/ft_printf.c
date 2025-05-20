/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:16:12 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/20 19:35:21 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		new_out;

	i = 0;
	va_start (args, string);
	while (string[i])
	{
		if (string[i] == '%' && !ft_strchr("cspdiuxX%", string[i + 1]))
			return (-1);
		i++;
	}
	i = 0;
	new_out = check_string(args, string, i);
	va_end (args);
	return (new_out);
}

char	*ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)(&str[i]));
		i++;
	}
	if (c == '\n')
		return ((char *)(&str[i]));
	return (NULL);
}

int	check_string(va_list args, const char *string, int i)
{
	int	new_out;
	int	out;
	int	res;

	out = 0;
	new_out = 0;
	while (string[i])
	{
		if (string[i] != '%')
			out += ft_putchar(string[i]);
		else
		{
			out += check_format(args, string, i + 1);
			i++;
		}
		if (new_out > out)
			return (-1);
		new_out = out;
		i++;
	}
	return (new_out);
}

int	check_format(va_list args, const char *string, int i)
{
	if (string[i] == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (string[i] == 's')
		return (ft_putstr((char *)va_arg(args, char *)));
	else if (string[i] == 'p')
		return (ft_putptr(va_arg(args, long int), "0123456789abcdef", 16));
	else if (string[i] == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
