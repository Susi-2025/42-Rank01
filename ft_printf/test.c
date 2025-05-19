#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c);
int ft_putstr(char *str);
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
        if (string[i] == '%' && !ft_strchr("cspdiuxX%", string[i + 1]))
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
    if (string[i] == 'c')
        return (ft_putchar((char)va_arg(args, int)));
    else if (string[i] == 's')
        return (ft_putstr((char *)va_arg(args, char *)));
    else if (string[i] == '%')
        return (ft_putchar('%'));
    else
        return (-1);
}

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (ft_putchar(str[i]) == -1)
            return (-1);
        i++;
    }
    return (i);
}

#include <stdio.h>

int main(void)
{   
    char c = 'd';
    char d = '9';
    char *s = "Well Hell";
//  // Test char
    // ft_printf("My func: ABC %c DED %c \n", c, d);
    // printf("Std func: ABC %c DED %c \n", c, d);
        // Synchronized test cases
    ft_printf("ft_printf: %c \n", '0');
    printf("Test 1 (ft_printf): \n");
    ft_printf("%c \n", '0');
    printf("Test 1 (printf)   : \n");
    printf("%c \n", '0');

    printf("Test 2 (ft_printf): ");
    ft_printf("[ %c ]\n", '0');
    printf("Test 2 (printf)   : ");
    printf("[ %c ]\n\n", '0');

    printf("Test 3 (ft_printf): ");
    ft_printf("[ %c ]\n", '0' - 256);
    printf("Test 3 (printf)   : ");
    printf("[ %c ]\n\n", '0' - 256);

    printf("Test 4 (ft_printf): ");
    ft_printf("[ %c ]\n", '0' + 256);
    printf("Test 4 (printf)   : ");
    printf("[ %c ]\n\n", '0' + 256);

    printf("Test 5 (ft_printf): ");
    ft_printf("[ %c %c %c ]\n", '0', 0, '1');
    printf("Test 5 (printf)   : ");
    printf("[ %c %c %c ]\n\n", '0', 0, '1');

    printf("Test 6 (ft_printf): ");
    ft_printf("[ %c %c %c ]\n", ' ', ' ', ' ');
    printf("Test 6 (printf)   : ");
    printf("[ %c %c %c ]\n\n", ' ', ' ', ' ');

    printf("Test 7 (ft_printf): ");
    ft_printf("[ %c %c %c ]\n", '1', '2', '3');
    printf("Test 7 (printf)   : ");
    printf("[ %c %c %c ]\n\n", '1', '2', '3');

    printf("Test 8 (ft_printf): ");
    ft_printf("[ %c %c %c ]\n", '2', '1', 0);
    printf("Test 8 (printf)   : ");
    printf("[ %c %c %c ]\n\n", '2', '1', 0);

    printf("Test 9 (ft_printf): ");
    ft_printf("[ %c %c %c ]\n", 0, '1', '2');
    printf("Test 9 (printf)   : ");
    printf("[ %c %c %c ]\n\n", 0, '1', '2');
    // // Test str
    // int str1 = ft_printf("%s \n", s);
    // int str2 = printf("%s \n", s);
    // printf("Compare my and std function: %i & %i \n", str1, str2);
    // // Edge case
    // int e1 = ft_printf("ABC %c DED %c  % \n", c, d);
    // int e2 = printf("ABC %c DED %c  % \n", c, d);
    // printf("Value of edge case: %i \n", e1);
    // printf("Value of edge case: %i \n", e2);
    //printf("% \n");
    return 0;
}