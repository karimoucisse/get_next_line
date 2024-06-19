/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:12:36 by kcisse            #+#    #+#             */
/*   Updated: 2024/06/19 17:20:42 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fill_lst(t_next_line **lst, char *buffer)
{
	t_next_line	*new_lst;
	t_next_line	*p;

	p = *lst;
	if (!lst)
		return (0);
	new_lst = ft_lstnew(buffer);
	if (!new_lst)
		return (0);
	if (!*lst)
		*lst = new_lst;
	else
	{
		while (p->next)
				p = p->next;
		p->next = new_lst;
	}
	return (1);
}

char	*fill_buffer(int fd)
{
	char	*buffer;
	int		byte_read;

	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read < 0)
	{
		free(buffer);
		return (0);
	}
	buffer[byte_read] = '\0';
	return (buffer);
}

int	handle_new_line(t_next_line *lst, char **remain_chars, char *buffer)
{
	char	*str_cpy;
	int		i;

	i = ft_strchr(buffer, '\n');
	str_cpy = malloc(sizeof(char *) * i);
	ft_strlcpy(str_cpy, buffer, i + 1);
	*remain_chars = ft_strdup(&(buffer[i]));
	if (!remain_chars)
		return (0);
	return (fill_lst(&lst, str_cpy));
}

char	*fill_str_line(t_next_line *lst)
{
	char	*str;
	int		i;
	int		len;
	t_next_line *new_lst;

	new_lst = lst;
	len = 0;
	while (new_lst)
	{
		len += ft_strlen(new_lst->content);
		new_lst = new_lst->next;
	}
	if (len == 0)
		return (0);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	new_lst = lst;
	while (new_lst && new_lst->content)
	{
		i = 0;
		while (new_lst->content[i])
		{
			*str = new_lst->content[i];
			str++;
			i++;
		}
		new_lst = new_lst->next;
	}
	*str = '\0';
	return (str-len);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remain_chars;
	t_next_line	*lst;
	char	*str_line;
	if (fd <= 0)
		return (0);
	if (remain_chars)
		buffer = remain_chars;
	else
		buffer = fill_buffer(fd);
	if (!buffer)
		return (0);
	lst = ft_lstnew(buffer);
	if (!lst)
		return (0);
	while (buffer && !ft_strchr(buffer, '\n'))
	{
		buffer = fill_buffer(fd);
		if(buffer)
		{
			if (!ft_strchr(buffer, '\n') && !fill_lst(&lst, buffer))
				return (0);
		}
	}
	if(buffer && ft_strchr(buffer, '\n'))
		handle_new_line(lst, &remain_chars, buffer);
	str_line = (fill_str_line(lst));
	free(buffer);
	// ft_lstclear(&lst, free);
	return (str_line);
}

int main ()
{
	int fd = open("cyrano_nez.txt", O_RDONLY);
	// int fd2 = open("la_guerre_des_etoiles.txt", O_RDONLY);
	char *str = get_next_line(fd);
	// get_next_line(fd2);
	int i;
	i = 0;
	while(str)
	{
		i++;
		// printf("%s", str);
		str = get_next_line(fd);
	}
	// printf("\ntotal line = %d\n", i);
	close(fd);
}
