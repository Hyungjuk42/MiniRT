/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:13:59 by yeonwkan          #+#    #+#             */
/*   Updated: 2023/11/30 14:50:38 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char c);
static int	word_len(char const *str, char c);
static int	num_set(char const *str, char c);
static int	free_arg(char **ret, int i);

char	**ft_split(char const *str, char c)
{
	char	**ret;
	int		word;
	int		word_leng;
	int		i;
	int		j;

	i = 0 - 1;
	word = word_count(str, c);
	ret = (char **)malloc(sizeof(char *) * (word + 1));
	if (ret == 0)
		return (0);
	ret[word] = 0;
	while (++i < word)
	{
		j = 0;
		str += num_set(str, c);
		word_leng = word_len(str, c);
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
	exit(1);
}

static int	num_set(char const *str, char c)
{
	int	i;

	i = 0;
	while (*str == c)
	{
		i++;
		str++;
	}
	return (i);
}

static int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		else
			i++;
		str++;
	}
	return (i);
}

static int	word_count(char const *str, char c)
{
	int	ret;
	int	flag;

	ret = 0;
	flag = 1;
	while (*str)
	{
		if (*str == c)
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
