/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:20:44 by daeidi-h          #+#    #+#             */
/*   Updated: 2021/10/03 13:08:23 by daeidi-h         ###   ########.fr       */
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

static void	free_ptr(char **str)
{
	free (*str);
	*str = NULL;
}

static char	*save_line(int r, char *last_line, char *currentline)
{
	char	*temp;

	if (r <= 0 && (!ft_strlen(last_line) || last_line == NULL))
	{
		return (NULL);
	}
	else if (!ft_strchr(last_line, '\n') && *last_line != '\0')
	{
		currentline = ft_strdup(last_line);
		free_ptr(&last_line);
	}
	else
	{
		currentline = ft_substr(last_line, 0, (ft_strchr(last_line, '\n') \
		+ 1 - last_line));
		temp = ft_substr(last_line, (ft_strchr(last_line, '\n') \
		+ 1 - last_line), ft_strlen(last_line));
		free_ptr(&last_line);
		last_line = ft_strdup(temp);
		free_ptr(&temp);
	}
	return (currentline);
}

static char	*load(char *last_line, char *buf, int fd, char *current_line)
{
	char	*temp;
	int		r;

	r = 1;
	while (!ft_strchr(last_line, '\n') \
	&& (r > 0))
	{	
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
		temp = last_line;
		last_line = ft_strjoin(temp, buf);
		free_ptr(&temp);
	}
	free_ptr(&buf);
	return (save_line(r, last_line, current_line));
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*last_line = NULL;
	char		*current_line;

	buf = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	printf("%p\n", &buf);
	printf("%p\n", &last_line);
	if (!buf)
		return (NULL);
	if (!last_line)
		last_line = ft_strdup("");
	printf("%p\n", last_line);
	if (read(fd, buf, 0) < 0)
	{
		free_ptr(&buf);
		return (NULL);
	}
	return (load(last_line, buf, fd, current_line));
}
