/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:20:44 by daeidi-h          #+#    #+#             */
/*   Updated: 2021/09/28 18:05:17 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{	
	int				i;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)s + i);
		i++;
	}
	if (!chr && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			r;
	static char	*last_line;
	char		*temp;
	char		*currentline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	r = 1;
	if (!last_line)
		last_line = ft_strdup("");
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	while (!ft_strchr(last_line, '\n') \
	&& (r > 0))
	{	
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		temp = ft_strjoin(last_line, buf);
		free(last_line);
		last_line = NULL;
		last_line = ft_strdup(temp);
		free(temp);
		temp = NULL;
	}
	free(buf);
	buf = NULL;
	if (r == 0 && !ft_strlen(last_line))
		return (NULL);
	currentline = ft_substr(last_line, 0, (ft_strchr(last_line, '\n') \
	+ 1 - last_line));
	temp = ft_substr(last_line, (ft_strchr(last_line, '\n') \
	+ 1 - last_line), ft_strlen(last_line));
	free(last_line);
	last_line = NULL;
	last_line = ft_strdup(temp);
	free(temp);
	temp = NULL;
	return (currentline);
}
