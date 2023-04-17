/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguezzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:06:54 by aguezzi           #+#    #+#             */
/*   Updated: 2022/11/27 17:57:33 by aguezzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == c % 256)
			break ;
		s++;
	}
	if (*s != 0)
		return ((char *)s);
	if (c % 256 == 0)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	str = malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*tab;
	char	*t;

	i = 0;
	if (size == 0)
		return (ft_strdup(""));
	if (size >= 9223372036854775807 || nmemb >= 9223372036854775807)
		return (NULL);
	tab = malloc(size * nmemb);
	if ((tab == NULL || size == 0 || nmemb == 0) && size * nmemb != 0)
		return (NULL);
	t = tab;
	while (i < size * nmemb)
	{
		t[i] = 0;
		i++;
	}
	return (tab);
}
