/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:13:08 by ajakob            #+#    #+#             */
/*   Updated: 2023/01/30 20:54:38 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_alloc(char *buffer, int end) // Somewhere here is the issue
{
	char		*line;
	char		*save;
	char		*n_p;
	static int	len;

	len += end;
	if (len > end)
	{
		save = ft_calloc(len - end, sizeof(char));
		ft_strlcpy(save, line, len - end);
		line = ft_calloc(len, sizeof(char));
		ft_strlcpy(line, save, len);
		ft_strlcat(line, buffer, len);
	}
	else
	{
		len += 1;
		line = ft_calloc(len, sizeof(char));
		ft_strlcpy(line, buffer, len);
	}
	if ((n_p = ft_strchr(buffer, '\n')) != buffer[end]) // Maybe buffer '\0' as well
	{
		ft_memcpy(buffer, n_p, end);
		len = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			end;


	if (buffer[0])
		line = line_alloc(buffer, end);
	end = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(buffer, '\n') && end == BUFFER_SIZE)
	{
		line = line_alloc(buffer, end);
		end = read(fd, buffer, BUFFER_SIZE);
	}
	if (ft_strchr(buffer, '\n') || end != BUFFER_SIZE)
	{
		line = line_alloc(buffer, end);
	}
	return (line);
}

// Case where allocation fails or input is wrong

int	main(void)
{
	int		fd;
	char	*result;

	fd = open("test.txt", O_RDONLY);
	result = get_next_line(fd);
	printf("%s", result);
	printf("\n");
	return (0);
}
