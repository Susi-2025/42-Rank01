#include "get_next_line.h"
//#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>
#include <fcntl.h>  // for open()
#include <unistd.h> // for close()

void    ft_prints(char *s)
{
    int k = 0;
    while (s[k])
    {
        printf("%c", s[k]);
        k++;
    }
}

char    *get_next_line(int fd)
{
    static char *temp;
    char        *line;

    if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    temp = ft_readfile(fd, temp);
    if (!temp)
        return (NULL);
    line = ft_line(temp);
    temp = ft_remain(temp);
    return (line);
}

char    *ft_readfile(int fd, char *temp)
{
    char    *buffer;
    int     byte_read;

    if (!temp)
        temp = ft_calloc(1, 1);
    buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
    byte_read = 1;
    while (byte_read > 0)
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);
        if (byte_read == -1)
        {
            free (buffer);
            return (NULL);
        }
        buffer[byte_read] = 0;
        temp = ft_strjoin_free(temp, buffer);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free(buffer);
    ft_prints(temp);
    return (temp);
}

char    *ft_strjoin_free(char *temp, char *buffer)
{
    char    *out;

    out = ft_strjoin(temp, buffer);
    free(temp);
    return (out);
}

char    *ft_line(char *temp)
{
    char    *line;
    int     i;

    i = 0;
    if (!temp[i])
        return(NULL);
    while (temp[i] != '\n' && temp[i])
        i++;
    line = ft_calloc(i + 2, sizeof(char));
    i = 0;
    while (temp[i] != '\n' && temp[i])
    {
        line[i] = temp[i];
        i++;
    }
    if (temp[i] && temp[i] == '\n')
        line[i++] = '\n';
    return (line);
}

char    *ft_remain(char *temp)
{
    char    *out;
    int     i;
    int     j;

    i = 0;
    while (temp[i] != '\n' && temp[i])
        i++;
    if (!temp[i])
    {
        free(temp);
        return (NULL);
    }
    out = ft_calloc((ft_strlen(temp) - i + 1), sizeof(char));
    i++;
    j = 0;
    while (temp[i])
        out[j++] = temp[i++];
    free(temp);
    return (out);
}


int main (void)
{
    int fd = open("idea.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Failed to open file");
        return 1;
    }
    // printf("Value of fd is: %i \n", fd);
    char *out1 = get_next_line(fd);
    printf("Final output is: \n");
    ft_prints(out1);
    printf("\n");
    //for (int i = 1; i < 3; i++)
    // {
    //     char *out1 = get_next_line(fd);
    //     while (*out1 != '\0')
    //     {
    //         printf("%c", *out1);
    //         out1++;
    //     }
    //     printf("\n");
    // }
    close(fd);
    return (0);
}
