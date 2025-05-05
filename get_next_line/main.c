#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"
#include <stdio.h>
#include <fcntl.h>  // for open()
#include <unistd.h> // for close()

// char	*get_next_line(int fd)
// {
// 	char	buffer;
// 	char	*out;
//     char	*c;
// 	t_list	*new_node;
// 	t_list	*new_list;
	
// 	new_list = NULL;
	
// 	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
// 	{	
// 		//new_node = ft_read(buffer);
//         c = malloc(2);
// 		c[0] = buffer;
// 		c[1] = '\0';
// 		new_node = ft_lstnew(c);
// 		free(c);
//         printf("Value of new node is: %s \n", (char *)(new_node -> content));
//         ft_lstadd_back(&new_list, new_node);
// 	}
//     out = ft_assign(new_list);
//     ft_lstclear(&new_list);
//     // check new_list again
//     //  while (new_list != NULL)
//     // {
//     //     printf("Remain value of new_list: %s \n", (char *)(new_list->content));
//     //     new_list = new_list -> next;
//     // }
//     return (out);
// }

int main (void)
{
    int fd = open("libft.h", O_RDONLY);
    if (fd == -1)
    {
        perror("Failed to open file");
        return 1;
    }
    printf("Value of the output is: \n");
    for (int i = 1; i < 40; i++)
    {
        char *out1 = get_next_line(fd);
        while (*out1 != '\0')
        {
            printf("%c", *out1);
            out1++;
        }
        printf("\n");
    }
    close(fd);
    return (0);
}
// test ft_lstnew
// int main(void)
// {
//     char *s[] = {"a", "b", "c", "", "\0", "N", "-300"};
//     t_list  *lst = NULL;
//     for (int i = 0; i < 6; i++)
//     {
//         t_list *new_node = ft_lstnew(s[i]);
//         if (*(char *)(new_node -> content) == '\0')
//             printf("Content of new_node is empty \n");
//         else
//             printf ("Content of new_node: %s \n", new_node -> content);
//     // test ft_lstadd_back
//         ft_lstadd_back(&lst, new_node);
//     }
//     t_list  *current = lst;
//      while (current != NULL)
//     {
//         printf("Value inside the list: %s \n", (char *)(current->content));
//         current = current -> next;
//     }
//     // test ft_lstsize
//     int size = ft_lstsize(lst);
//     printf("Size of the list is: %d \n", size);
//     // test ft_lstlast
//     t_list  *last = ft_lstlast(lst);
//     printf("The content of the last position is: %s \n", (char *)(last -> content));
//     return (0);
// }