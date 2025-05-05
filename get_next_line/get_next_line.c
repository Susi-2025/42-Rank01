/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:22:38 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/05 15:59:42 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer;
	char	*out;
	char	*c;
	t_list	*new_node;
	t_list	*new_list;

	new_list = NULL;
	while (read(fd, &buffer, 1) > 0 && buffer != '\n')
	{	
		c = malloc(2);
		c[0] = buffer;
		c[1] = '\0';
		new_node = ft_lstnew(c);
		free(c);
		ft_lstadd_back(&new_list, new_node);
	}
	out = ft_assign(new_list);
	if (!out)
		return (NULL);
	ft_lstclear(&new_list);
	return (out);
}
