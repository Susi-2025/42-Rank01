/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:22:38 by vinguyen          #+#    #+#             */
/*   Updated: 2025/04/30 15:39:50 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*get_next_line(int fd)
{
	char			*buffer;
	char			*out;
	unsigned int	count; //count the number of bytes of 01 lines for assign the memory
	
	while (*buffer != '\n')
	{	
		read(fd, buffer, 1);
		count++;
	}
	out = (char *)malloc (count + 1);


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
	// or open the files again
	// 2. use struct to store the value of character and move the struct
	//		every read -> store in the temp node -> add temp node at the last position of the temp list
	//		count the size of the list to know the calculate the size of string output.
	//		read out the value from list to the string.
	// the link list usually assigned the memory randomly -> need to free the memory carefully to prevent memory leaks
}
