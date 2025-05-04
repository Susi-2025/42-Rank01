/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:38:36 by vinguyen          #+#    #+#             */
/*   Updated: 2025/04/30 16:34:45 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while(lst && lst -> next != NULL)
		lst = lst -> next;
	return(lst);
}
//should we insert the node from the front of the list
//-> assign the value of the list to reverse string -> easier or not?
void	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	temp = ft_lstlast(*lst); // can it work?
	temp -> next = new;
	//new -> next = NULL;
	// how about NULL at the end of the list, do we need to free it?
	return;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if(!lst)
		return (0);
	while(lst)
	{
		lst = lst-> next;
		i++;
	}
	return (i);
}

void	ft_lstfree(t_list **lst)
{

}