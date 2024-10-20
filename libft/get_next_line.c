/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:51:50 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/08/22 01:23:54 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_fdlist	*head;
	t_fdlist		*cur;
	char			*buf;
	char			*ret;

	if (fd < 0)
		return (0);
	if (!head)
	{
		head = init_list(-1, 0);
		if (!head)
			return (0);
	}
	cur = find_and_add(head, fd);
	if (!cur)
		return ((char *)ret_free(0, 0, &head));
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return ((char *)ret_free(0, cur, &head));
	ret = find_nl_ret(cur, buf);
	if (!ret)
		ret_free(buf, cur, &head);
	else
		ret_free(buf, 0, 0);
	return (ret);
}

char	*find_nl_ret(t_fdlist *cur, char *buf)
{
	size_t	nl_size;

	nl_size = ft_memchr2(cur->str, '\n', cur->size);
	while (nl_size == 0)
	{
		cur->rd_size = read(cur->fd, buf, BUFFER_SIZE);
		if (cur->rd_size == -1)
			return (0);
		else if (cur->rd_size == 0)
			return ((char *)(ft_strdup2(&cur, nl_size)));
		cur->str = ft_strjoin2(&cur, buf);
		if (!cur->str)
			return (0);
		nl_size = ft_memchr2(cur->str, '\n', cur->size);
	}
	return ((char *)(ft_strdup2(&cur, nl_size)));
}

t_fdlist	*find_and_add(t_fdlist *head, int fd)
{
	t_fdlist	*ret;
	t_fdlist	*cur;

	while (head)
	{
		if (head->fd == fd)
			return (head);
		cur = head;
		head = head->next;
	}
	ret = init_list(fd, 1);
	if (!ret)
		return (0);
	cur->next = ret;
	return (ret);
}

long	ret_free(char *s, t_fdlist *cur, t_fdlist **head)
{
	t_fdlist	*this;

	if (s)
		free(s);
	s = NULL;
	if (head)
	{
		if (cur)
		{
			this = *head;
			while (this->next != cur)
				this = this->next;
			this->next = cur->next;
			if (cur->str)
				free(cur->str);
			free(cur);
		}
		if ((*head)->next == 0)
		{
			free(*head);
			*head = 0;
		}
	}
	return (0);
}

t_fdlist	*init_list(int fd, int flag)
{
	t_fdlist	*list;

	list = (t_fdlist *)malloc(sizeof(t_fdlist));
	if (!list)
		return (0);
	if (!flag)
		list->fd = -1;
	if (flag)
	{
		list->fd = fd;
		list->size = 0;
		list->rd_size = 0;
		list->str = 0;
	}
	list->next = 0;
	return (list);
}
