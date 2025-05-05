/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:38:36 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/05 15:45:27 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;
	char	*new_content;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_content = (char *)malloc(2 * sizeof(char));
	if (!new_content)
	{
		free(new_node);
		return (NULL);
	}
	new_content [0] = *((char *)content);
	new_content [1] = '\0';
	new_node -> content = new_content;
	new_node -> next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next != NULL)
		temp = temp->next;
	temp -> next = new;
	return ;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst-> next;
		i++;
	}
	return (i);
}

char	*ft_assign(t_list *new_list)
{
	unsigned int	size_list;
	unsigned int	i;
	char			*out;
	t_list			*head;

	i = 0;
	size_list = (unsigned int)(ft_lstsize(new_list));
	out = (char *)malloc((size_list + 1) * sizeof(char));
	if (!out)
		return (NULL);
	head = new_list;
	while (head != NULL)
	{
		out[i] = ((char *)(head -> content))[0];
		i++;
		head = head -> next;
	}
	out[i] = '\0';
	return (out);
}

void	ft_lstclear(t_list **new_list)
{
	t_list	*temp;

	while (*new_list != NULL)
	{
		temp = (*new_list)->next;
		free((*new_list)-> content);
		free(*new_list);
		*new_list = temp;
	}
}
