/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:38:36 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/15 15:08:52 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;	

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == (char) c)
			return (p);
		p++;
	}
	if ((char) c == '\0')
		return (p);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	out = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!out || !s1 || !s2)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		out[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		out[i + j] = s2[j];
		j++;
	}
	out[i + j] = '\0';
	return (out);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*out;
	size_t	i;

	out = malloc(nmemb * size);
	if (!out)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		out[i] = '\0';
		i++;
	}
	return (out);
}
