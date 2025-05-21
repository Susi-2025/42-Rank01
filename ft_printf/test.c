#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_putchar(int c);
int ft_putstr(char *str);
int	ft_putptr(void *ptr, char *base, int i);
int	ft_putnbr_base(long long number, char *base, int i);
int check_format(va_list args, const char *string, int i);
int check_string(va_list args, const char *string, int i);
char    *ft_strchr(const char *str, char c);

int ft_printf(const char *string, ...)
{
    va_list args;
    int     i;
    int     new_out;

    i = 0;
    va_start (args, string);
    while (string[i])
    {
        if (string[i] == '%' && ft_strchr("%", string[i + 1]))
            i++;
        else if (string[i] == '%' && !ft_strchr("cspdiuxX", string[i + 1]))
            return (-1);
        i++;
    } 

    i = 0;
    new_out = check_string(args, string, i);
    va_end (args);
    return (new_out);
}

char    *ft_strchr(const char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(str[i] == c)
            return ((char *)(&str[i]));
        i++;
    }   
    if (c == '\n')
        return ((char *)(&str[i]));
    return (NULL);
}

int check_string(va_list args, const char *string, int i)
{
    int new_out;
    int out;
    int res;

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

int check_format(va_list args, const char *string, int i)
{
    char    *hex;
    char    *hex_up;

    hex = "0123456789abcdef";
    hex_up = "0123456789ABCDEF";
    if (string[i] == 'c')
        return (ft_putchar((char)va_arg(args, int)));
    else if (string[i] == 's')
        return (ft_putstr((char *)va_arg(args, char *)));
    else if (string[i] == 'p')
        return (ft_putptr(va_arg(args, void *), hex, 16));
    else if (string[i] == 'd' || string[i] == 'i')
        return (ft_putnbr_base(va_arg(args, int), hex, 10));
    else if (string[i] == 'u')
        return (ft_putnbr_base(va_arg(args, unsigned int), hex, 10));
    else if (string[i] == 'x')
        return (ft_putnbr_base(va_arg(args, unsigned int), hex, 16));
    else if (string[i] == 'X')
        return (ft_putnbr_base(va_arg(args, unsigned int), hex_up, 16));
    else if (string[i] == '%')
        return (ft_putchar('%'));
    else
        return (-1);
}


int ft_putchar(int c)
{
    return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

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




int main(void)
{   
    char c = 'd';
    char d = '9';
    char *s = "Well Hell";
    int no1 = -432;
    int no2 = 5678;
//  // Test char- compare ok
    // ft_printf("My func: ABC %c DED %c \n", c, d);
    // printf("Std func: ABC %c DED %c \n", c, d);
    // printf("Compare value: %d %d \n", printf("%c \n", 'W'), ft_printf("%c \n", 'W'));
        // Synchronized test cases
    // ft_printf("ft_printf: %c \n", '0');
    // printf("Test 1 (ft_printf): \n");
    // ft_printf("%c \n", '0');
    // printf("Test 1 (printf)   : \n");
    // printf("%c \n", '0');
    // // Test str - compare ok
    // int str1 = ft_printf("%s \n", s);
    // int str2 = printf("%s \n", s);
    // printf("Compare my and std function: %i & %i \n", str1, str2);
    // // Edge case
    // int e1 = ft_printf("ABC %c DED %c  % \n", c, d);
    // int e2 = printf("ABC %c DED %c  % \n", c, d);
    // printf("Value of edge case: %i \n", e1);
    // printf("Value of edge case: %i \n", e2);
    //printf("% \n");
    // Test ptr
    // printf("Address of c: %p \n", &c);
    // ft_printf("My function: Address of c: %p \n", &c);
    // printf("Compare value: %d %d \n", printf("%p \n", &c), ft_printf("%p \n", &c));
    //printf("Compare value: %d \n", ft_printf("%p \n", &c));
    // // Test d
    // printf("Integer test of no1: %d \n", no1);
    // ft_printf("My func: Integer test of no1: %d \n", no1);
    // printf("Compare value: %d %d \n", printf("%d \n", no1), ft_printf("%d \n", no1));
    // printf("Integer test of no2: %d \n", no2);
    // ft_printf("My func: Integer test of no2: %d \n", no2);
    // // Test i
    // printf("Integer test of no1: %i \n", no1);
    // ft_printf("My func: Integer test of no1: %i \n", no1);
    // printf("Integer test of no2: %i \n", no2);
    // ft_printf("My func: Integer test of no2: %i \n", no2);
    // Test u
    // printf("Value of u: %u \n", 123);
    // ft_printf("Value of u: %u \n", 123);;
    // printf("Compare value: %d %d \n", printf("%u \n", 123), ft_printf("%u \n", 123));
    // Test x
    // printf("Compare value: %d %d \n", printf("%x \n", -123456789), ft_printf("%x \n", -123456789));
    // // Test X
    // printf("Compare value: %d %d \n", printf("%X \n", -123456789), ft_printf("%X \n", -123456789));
    // // Combine test
    // printf("Compare value: %d %d \n", printf("%X %s %% %c\n", -123456789, "bee make best", 'a'), \
    // ft_printf("%X %s %% %c\n", -123456789, "bee make best", 'a'));
    // //printf("Value of error: %d \n",ft_printf("%X %s %c %d %%%%%% \n", -123456789, "bee make best", 'a', 1));
    // printf("Compare value: %d %d \n", printf("%X %s %c %d %%%%%% \n", -123456789, "bee make best", 'a', 1), \
    // ft_printf("%X %s %c %d %%%%%% \n", -123456789, "bee make best", 'a', 1));
    // printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
    // ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
    // printf(" NULL %s NULL ", NULL);
    // ft_printf(" NULL %s NULL ", NULL);
    printf(" %p %p ", 0, 0);
    ft_printf(" %p %p ", 0, 0);


    return 0;
}