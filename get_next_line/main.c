#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>  // for open()
#include <unistd.h> // for close()

int main (void)
{
    //int fd = open("./test_file/longline.txt", O_RDONLY);
    // int fd = open("./test_file/newline.txt", O_RDONLY);
    //int fd = open("./test_file/empty.txt", O_RDONLY);
    int fd = open("./test_file/shortline.txt", O_RDONLY);
    // printf("Value of fd is: %i \n", fd);
    printf("Value of fd is: %i \n",fd);
    printf("BUFFER_SIZE is: %d\n", BUFFER_SIZE);
    char *out = get_next_line(fd);
    printf("The 1st result is: %s\n", out);
    char *out1 = get_next_line(fd);
    printf("The 2nd result is: %s\n", out1);
    char *out2 = get_next_line(fd);
    printf("The 3rd result is: %s\n", out2);
    char *out3 = get_next_line(fd);
    printf("The 4th result is: %s\n", out3);
    char *out4 = get_next_line(fd);
    printf("The 5th result is: %s\n", out4);
    close(fd);
    return (0);
}