/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:00:10 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/23 19:01:12 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char	**str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char	*storage)
{
	char	*newlinecharlocation;
	char	*new_storage;
	int		length;

	newlinecharlocation = ft_strchr(storage, '\n');
	if (!newlinecharlocation)
	{
		return (ft_free(&storage));
	}
	else
		length = (newlinecharlocation - storage) + 1;
	if (!storage[length])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, length, ft_strlen(storage) - length);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*new_line(char	*storage)
{
	char	*newlinecharlocation;
	char	*line;
	int		length;

	newlinecharlocation = ft_strchr(storage, '\n');
	length = (newlinecharlocation - storage) + 1;
	line = ft_substr(storage, 0, length);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_to_buffer(int fd, char	*storage)
{
	int		numbytesread;
	char	*buffer;

	numbytesread = 1;
	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&storage));
	buffer[0] = '\0';
	while (numbytesread > 0 && !ft_strchr(buffer, '\n'))
	{
		numbytesread = read (fd, buffer, BUFFER_SIZE);
		if (numbytesread > 0)
		{
			buffer[numbytesread] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (numbytesread == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = {0};
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = read_to_buffer (fd, storage);
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
		return (ft_free(&storage));
	storage = clean_storage(storage);
	return (line);
}