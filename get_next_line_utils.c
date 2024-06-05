/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:01:21 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/06/05 15:30:18 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return (&s[i]);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return (&s[i]);
	}
	return (NULL);
}

char	*join(char *memory, char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i] != '\0')
	{
		memory[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		memory[i + j] = s2[j];
		j++;
	}
	memory[i + j] = '\0';
	return (memory);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*memory;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	memory = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!memory || !s2)
		return (NULL);
	memory = join(memory, s1, s2);
	free(s1);
	return (memory);
}
