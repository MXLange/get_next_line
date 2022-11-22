/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msprenge <msprenge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:38:42 by msprenge          #+#    #+#             */
/*   Updated: 2022/11/22 14:08:04 by msprenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_count;
	size_t	s2_count;
	size_t	final_len;
	char	*final;

	final_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	final = malloc(sizeof(char) * (final_len));
	if (!final)
		return (NULL);
	s1_count = 0;
	s2_count = 0;
	while (s1[s1_count])
	{
		final[s1_count] = s1[s1_count];
		s1_count++;
	}
	while (s2[s2_count])
		final[s1_count++] = s2[s2_count++];
	final[s1_count] = '\0';
	return (final);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*final;
	size_t	total;
	size_t	i;

	total = size * nmemb;
	final = malloc(total);
	if (!final)
		return (NULL);
	i = 0;
	while (total > 0)
	{
		final[i] = 0;
		i++;
		total--;
	}
	return ((void *)final);
}
