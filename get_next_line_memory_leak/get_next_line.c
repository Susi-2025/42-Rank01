/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:22:38 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/14 20:43:28 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	temp = ft_readfile(fd, temp);
	if (!temp)
		return (NULL);
	line = ft_line(temp);
	temp = ft_next(temp);
	return (line);
}

char	*ft_strjoin_free (char *temp, char *buffer)
{
	char	*out;

	out = ft_strjoin(temp, buffer);
	free(temp);
	return (out);
}

char	*ft_readfile(int fd, char *temp)
{
	int		byte_read;
	char	*buffer;
	
	if (!temp)
		temp = ft_calloc(1, 1);
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while(byte_read > 0 && !ft_strchr(temp, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free (buffer);
			free (temp);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		temp = ft_strjoin_free(temp, buffer);
		if (!temp)
			return (NULL);
	}
	free(buffer);
	return (temp);
}

char	*ft_line(char *temp)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	if(!temp[i])
		return(NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	out = ft_calloc(i + 2, sizeof(char));
	j = 0;
	while (temp[j] && temp[j] != '\n')
	{
		out[j] = temp[j];
		j++;
	}
	if (temp[j] && temp[j] == '\n')
		out[j++] = '\n';
	return (out);
}

char	*ft_next(char *temp)
{
	int		i;
	char	*out;
	int		j;

	i = 0;
	while(temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return(NULL);
	}
	out = (char *)malloc((ft_strlen(temp) - i + 1)* sizeof (char));
	if (!out)
		return (NULL);
	i++;
	j = 0;
	while (temp[i])
		out[j++] = temp[i++];
	out[i] = '\0';
	free(temp);
	return (out);
}
