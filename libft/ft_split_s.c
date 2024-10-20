/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:30:50 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/11/30 10:28:55 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonwkan <yeonwkan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:13:59 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/03/21 16:47:47 by yeonwkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char const *set);
static int	word_len(char const *str, char const *set);
static int	num_set(char const *str, char const *set);
static int	free_arg(char **ret, int i);

char	**ft_split_s(char const *str, char const *set)
{
	char	**ret;
	int		word;
	int		word_leng;
	int		i;
	int		j;

	i = 0 - 1;
	word = word_count(str, set);
	ret = (char **)malloc(sizeof(char *) * (word + 1));
	if (ret == 0)
		return (0);
	ret[word] = 0;
	while (++i < word)
	{
		j = 0;
		str += num_set(str, set);
		word_leng = word_len(str, set);
		ret[i] = (char *)malloc(sizeof(char) * (word_leng + 1));
		if (ret[i] == 0)
			return ((char **)(long long)free_arg(ret, i));
		while (j < word_leng)
			ret[i][j++] = *str++;
		ret[i][j] = '\0';
	}
	return (ret);
}

static int	free_arg(char **ret, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	exit (1);
}

static int	num_set(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (ft_is_char_in_set(*str, set))
	{
		i++;
		str++;
	}
	return (i);
}

static int	word_len(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (ft_is_char_in_set(*str, set))
			return (i);
		else
			i++;
		str++;
	}
	return (i);
}

static int	word_count(char const *str, char const *set)
{
	int	ret;
	int	flag;

	ret = 0;
	flag = 1;
	while (*str)
	{
		if (ft_is_char_in_set(*str, set))
			flag = 1;
		else
		{
			if (flag == 1)
				ret++;
			flag = 0;
		}
		str++;
	}
	return (ret);
}
