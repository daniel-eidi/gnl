/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:35:10 by daeidi-h          #+#    #+#             */
/*   Updated: 2021/10/03 16:13:56 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	s2_len = 0;
	while (s2[s2_len])
		s2_len++;
	join = (char *) malloc(s1_len + s2_len + 1);
	if (!join)
		return (NULL);
	ft_strlcpy(join, (char *) s1, s1_len + 1);
	ft_strlcpy(join + s1_len, (char *) s2, s2_len + 1);
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, \
size_t len)
{
	char			*new;
	size_t			siz;
	char			*ori;

	if (!s)
		return (NULL);
	ori = (char *) s;
	siz = ft_strlen(s);
	if (len > siz)
		len = siz;
	if (start > siz)
		return (ft_strdup(""));
	new = (char *) malloc(len + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, ori + start, len + 1);
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{	
	size_t	i;
	size_t	len;
	char	*cp;
	char	*ori;

	ori = (char *)src;
	cp = (char *)dst;
	len = ft_strlen(ori);
	i = 0;
	if (n == 0)
		return (len);
	while ((i + 1) < n && ori[i] != '\0')
	{
		cp[i] = ori[i];
		i++;
	}
	cp[i] = '\0';
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;
	char	*ori;

	ori = (char *) s;
	len = ft_strlen(s);
	new = (char *) malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, ori, len + 1);
	return (new);
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
