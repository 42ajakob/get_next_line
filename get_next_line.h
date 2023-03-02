/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:13:53 by ajakob            #+#    #+#             */
/*   Updated: 2023/01/30 20:24:26 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

char			*get_next_line(int fd);
void			*ft_calloc(size_t number, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
static size_t	ft_strnlen(const char *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t len);
char			*ft_strchr(const char *s, int c);

#endif