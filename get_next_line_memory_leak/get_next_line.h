/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinguyen <vinguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:38:22 by vinguyen          #+#    #+#             */
/*   Updated: 2025/05/14 19:44:30 by vinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 80
# endif

int ft_strlen(char *s);
char    *ft_strdup(char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
char    *ft_readfile(int fd, char *temp);
char    *ft_line(char *temp);
char    *ft_next(char *temp);
void    *ft_calloc(size_t nmemb, size_t size);

#endif
