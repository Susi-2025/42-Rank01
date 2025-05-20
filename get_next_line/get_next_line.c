/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:14:21 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/20 12:18:24 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_readfile(fd, temp);
	if (!temp)
		return (NULL);
	line = ft_line(temp);
	temp = ft_remain(temp);
	return (line);
}

char	*ft_readfile(int fd, char *temp)
{
	int		byte_read;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(temp, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	free(buffer);
	return (temp);
}

char	*ft_line(char *temp)
{
	char	*line;
	int		i;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_remain(char *temp)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	out = (char *)malloc((ft_strlen(temp) - i + 1) * sizeof(char));
	if (!out)
	{
		free(temp);
		return (NULL);
	}
	i++;
	j = 0;
	while (temp[i])
		out[j++] = temp[i++];
	out[j] = '\0';
	free(temp);
	return (out);
}
