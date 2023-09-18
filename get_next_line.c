/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirza <samirza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:14:52 by samirza           #+#    #+#             */
/*   Updated: 2023/09/18 16:07:00 by samirza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	new_str = malloc(sizeof(char) * i + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*get_morelines(char *str)
{
	int		i;
	int		j;
	char	*str_more;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	str_more = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!str_more)
		return (NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
	{
		str_more[j++] = str[i++];
	}
	str_more[j] = '\0';
	free (str);
	return (str_more);
}

char	*read_in_buffer(int fd, char *str)
{
	char	*buffer;
	int		byte_s;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	byte_s = 1;
	while (!ft_strchr(str, '\n') && byte_s != 0)
	{
		byte_s = read(fd, buffer, BUFFER_SIZE);
		if (byte_s == -1)
		{
			free (str);
			free (buffer);
			return (NULL);
		}
		buffer[byte_s] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT32_MAX)
		return (NULL);
	str = read_in_buffer(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = get_morelines(str);
	return (line);
}

int main ()
{
	int		fd;
	char	*line;
	int 	i = 1;

	fd = open("textfile.txt",O_RDONLY);
	while (i < 12)
	{
		line = get_next_line(fd);
		printf("line %d : %s\n", i, line);
		free (line);
		i++;
	}
	close(fd);
	return (0);
}