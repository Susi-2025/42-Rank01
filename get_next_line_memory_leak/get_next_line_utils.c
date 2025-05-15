/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:38:36 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/14 20:51:23 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

int	ft_strlen(char *s)
{
	int	i;
	
	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p != c)
	{
		if (*p == '\0')
			return (NULL);
		p++;
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	int		i;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	out = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		out[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		out[len_s1 + i] = s2[i];
	out[len_s1 + i] = '\0';
	return (out);
}
