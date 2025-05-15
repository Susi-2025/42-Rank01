#include "get_next_line.h"
//#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>
#include <fcntl.h>  // for open()
#include <unistd.h> // for close()

char	*get_next_line(int fd)
{
	char			*line;
	static char		*temp;
    int i = 0;

    if (!temp)
    {
        temp = malloc(1);
        if (!temp)
            return (NULL);
    }
	temp = ft_readfile(fd, temp);
    if (!temp)
        return (NULL);
    printf("1. 1st Value of temp variable \n");
    while (temp[i])
    {
        printf("%c", temp[i]);
        i++;
    }
    printf("\n");
    line = ft_line(temp);
    int j = 0;
    printf("2. Printout Value of temp variable \n");
    while (line[j])
    {
        printf("%c", line[j]);
        j++;
    }
    printf("\n");
    temp = ft_next(temp);
    printf("3. Remain Value of temp variable \n");
    int k = 0;
    while (temp[k])
    {
        printf("%c", temp[k]);
        k++;
    }
    printf("\n");
	return (line);
}

char    *ft_readfile(int fd, char *temp)
{
    unsigned int    byte_read;
    char            *buffer;

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    byte_read = 1;
    while(byte_read > 0 && !ft_strchr(temp, '\n'))
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);
        if (byte_read == -1)
        {
            free (buffer);
            return (NULL);
        }
        buffer[byte_read] = '\0';
        temp = ft_strjoin(temp, buffer);
    }
    free(buffer);
    return (temp);
}

char    *ft_line(char *temp)
{
    int     i;
    int     j;
    char    *out;

    i = 0;
    if(!temp[i])
        return(NULL);
    while (temp[i] && temp[i] != '\n')
        i++;
    out = (char *)(malloc((i + 2) * sizeof(char)));
    if (!out)
        return (NULL);
    j = 0;
    while (j <= i)
    {
        out[j] = temp[j];
        j++;
    }
    out[j] = '\0';
    return (out);
}

char    *ft_next(char *temp)
{
    int     i;
    char    *out;
    int     j;

    i = 0;
    while(temp[i] && temp[i] != '\n')
        i++;
    if (!temp[i])
    {
        free(temp);
        return(NULL);
    }
    out = (char *)malloc((ft_strlen(temp) - i + 1) * sizeof(char));
    if (!out)
        return (NULL);
    i++;
    j = 0;
    while (temp[i])
        out[j++] = temp[i++];
    out[i] = '\0';
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
        while (*out1)
        {
            printf("%c", *out1);
            out1++;
        }
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
