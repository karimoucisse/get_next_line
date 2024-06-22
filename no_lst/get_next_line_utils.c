/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 09:59:10 by kcisse            #+#    #+#             */
/*   Updated: 2024/06/22 14:47:08 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	l;

	l = 0;
	while (str[l])
			l++;
	return (l);
}

int	ft_strchr(const char *s, int c)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(s);
	while (i <= l)
	{
		if ((char)s[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dup == NULL)
		return (0);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < (size -1))
	{
			dst[i] = src[i];
			i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*joined_str;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = malloc(sizeof(char) * ((s1_len + s2_len) + 1));
	if (!joined_str)
		return (0);
	while (i < s1_len)
	{
		((char *)joined_str)[i] = ((char *)s1)[i];
		i++;
	}
	ft_strlcpy(joined_str + s1_len, s2, s2_len + 1);
	return (joined_str);
}
