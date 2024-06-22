/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 09:59:23 by kcisse            #+#    #+#             */
/*   Updated: 2024/06/22 17:30:12 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_next_line
{
	char				*content;
	struct s_next_line	*next;
}t_next_line;

// GET_NEXT_LINE FUNCTIONS
char	*get_next_line(int fd);
char	*fill_buffer(int fd, char *buffer);
char	*fill_line(char *buffer);
char	*fill_remain_char(char *buffer);
char	*handle_temp_var(char *remain_char, char *buffer);
// UTILS
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);
int		ft_strchr(const char *s, int c);
#endif
