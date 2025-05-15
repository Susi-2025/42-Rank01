#include "get_next_line.h"
//#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>
#include <fcntl.h>  // for open()
#include <unistd.h> // for close()

int main (void)
{
    int fd = open("./test_file/empty.txt", O_RDONLY);
    // printf("Value of fd is: %i \n", fd);
    printf("Value of fd is: %i \n",fd);
    // char *out = get_next_line(fd);
    // printf("The result is: %s", out);
    close(fd);
    return (0);
}