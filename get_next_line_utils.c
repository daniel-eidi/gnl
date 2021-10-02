/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeidi-h <daeidi-h@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:35:10 by daeidi-h          #+#    #+#             */
/*   Updated: 2021/10/02 15:46:34 by daeidi-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (malloc(0));
	new = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
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

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{	
	size_t	i;
	size_t	j;
	size_t	len;
	char	*cat;
	char	*s;

	s = (char *)src;
	cat = (char *)dst;
	len = ft_strlen(s);
	i = 0;
	j = 0;
	if (n == 0)
		return (len);
	while (i < n && cat[i] != '\0')
		i++;
	while ((j + i) < (n - 1) && s[j] != '\0')
	{
		cat[i + j] = s[j];
		j++;
	}
	if (i < n)
		cat[i + j] = '\0';
	return (len + i);
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
