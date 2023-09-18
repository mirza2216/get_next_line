/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirza <samirza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:16:57 by samirza           #+#    #+#             */
/*   Updated: 2023/09/18 14:36:49 by samirza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int i)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *str, char *buffer)
{
	char		*new;
	size_t		i;
	size_t		j;

	i = -1;
	j = 0;
	if (!str)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (0);
	new = malloc(sizeof(char) * (((ft_strlen(str) + ft_strlen(buffer)) + 1)));
	if (new == NULL)
		return (0);
	if (str)
		while (str[++i] != '\0')
			new[i] = str[i];
	while (buffer[j] != '\0')
		new[i++] = buffer[j++];
	new[ft_strlen(str) + ft_strlen(buffer)] = '\0';
	free (str);
	return (new);
}
