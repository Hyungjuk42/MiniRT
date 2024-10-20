/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 05:08:52 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/07/20 17:03:42 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char		*get_next_line(int fd);

typedef struct s_fdlist
{
	char			*str;
	int				fd;
	size_t			size;
	ssize_t			rd_size;
	struct s_fdlist	*next;
}	t_fdlist;

t_fdlist	*find_and_add(t_fdlist *head, int fd);
char		*find_nl_ret(t_fdlist *cur, char *buf);
long		ret_free(char *s, t_fdlist *cur, t_fdlist **head);
void		*ft_memset(void *b, int c, size_t len);
t_fdlist	*init_list(int fd, int flag);
char		*ft_strjoin2(t_fdlist **cur, char *buf);
size_t		ft_memchr2(const void *s, int c, size_t n);
char		*ft_strdup2(t_fdlist **cur, size_t nl_size);
void		*ft_memmove2(void *dst, const void *src, size_t len);

#endif