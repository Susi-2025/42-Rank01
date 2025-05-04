/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:22:38 by vinguyen          #+#    #+#             */
/*   Updated: 2025/04/30 16:31:34 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "get_next_line_utils.c"

char	*get_next_line(int fd)
{
	char	buffer;
	char	*out;
	t_list	*new_node;
	t_list	*new_list;
	t_list	*head;
	unsigned int	size_lst;
	unsigned int	i;

	new_list = NULL;
	i = 0;
	// read out the file and write to the buffer
	// assign the value from buffer to new node
	// assign the value from new node to new list
	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
	{	
		//read(fd, buffer, 1);
		new_node = ft_lstnew(buffer);// wrong here
		ft_lstadd_back(&new_list,new_node);
		// should we need to clear new_node memory before new process?
	}
	
	// check the size of list and array the memory
	size_lst = (unsigned int) (ft_lstsize(new_list));
	out = (char *)malloc((size_lst + 1) * sizeof(char));
	if (!out)
		return (NULL);
	// move the content on the new_list to out
	head = new_list;
	while (i < size_lst)
	{
		out[i] = ((char *)(new_list -> content))[0];
		new_list = new_list -> next;
		i++;
	}
	out[i] = '\0';
	// clear the new_list memory:
	ft_lstfree(&head);
}

	//return value: 
	// the line include the terminate \n character
	// except the end of file is reached or the file does not end with a \n character
	//return NULL if nothing to read or error occurs
	//work as expected reading a file and reading the std input
	//allow function: read, malloc, free

	//read function:
	// sszie_t read(int fd, void buf[.count], size count);
	// there is no limit characters for 01 line in files. Lines is detected by '\n' character
	
	// Edge case: the character of 01 lines could be not printable. what should we do??

	// Idea:
	// 1. count the number of character of 01 lines to store. But it has the issues: read will move
	// file pointer forward, there is no way to back to start of file of again if don't use lseek
	// or open the files again -> no effect.
	// 2. use struct to store the value of character and move the struct
	//		every read -> store in the temp node -> add temp node at the last position of the temp list
	//		count the size of the list to calculate the size of string output.
	//		read out the value from list to the string.
	// the link list usually assigned the memory randomly -> need to free the memory carefully to prevent memory leaks

