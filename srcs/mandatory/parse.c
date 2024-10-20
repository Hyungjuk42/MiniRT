/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjuk <hyungjuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:24:23 by hyungjuk          #+#    #+#             */
/*   Updated: 2023/12/19 17:25:12 by hyungjuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../libft/libft.h"
#include "../../includes/mandatory/miniRT.h"
#include "../../includes/mandatory/append_object.h"

void	open_rt_file(int ac, char **av, int *fd)
{
	char	*str;

	str = ft_reverse_str(av[1]);
	if (ac != 2 || ft_strncmp(str, "tr.", 3) != 0)
		handling_error(WRONG_ARG);
	*fd = open(av[1], O_RDONLY, 0644);
	if (*fd < 0)
		handling_error(OPEN_FILE);
	free(str);
}

t_vec	str_to_vec(char *str)
{
	int		len;
	char	**str_set;
	double	e[3];

	len = ft_count_char(str, ',');
	if (len != 2)
		handling_error(WRONG_ARG);
	str_set = ft_split(str, ',');
	len = 0;
	while (str_set[len])
		len ++;
	if (len != 3)
		handling_error(WRONG_FORM);
	e[0] = ft_strtod(str_set[0]);
	e[1] = ft_strtod(str_set[1]);
	e[2] = ft_strtod(str_set[2]);
	if (e[0] == NAN || e[1] == NAN || e[2] == NAN)
		handling_error(NOT_A_NUM);
	free_split(str_set);
	return (gen_vec(e[0], e[1], e[2]));
}

static void	judge_object(t_data *img, char **str_set)
{
	if (ft_strncmp(str_set[0], "A", 2) == 0)
		set_ambient_light(img, str_set, ft_strsetlen(str_set));
	else if (ft_strncmp(str_set[0], "C", 2) == 0)
		set_camera(img, str_set, ft_strsetlen(str_set));
	else if (ft_strncmp(str_set[0], "L", 2) == 0)
		set_light(img, str_set, ft_strsetlen(str_set));
	else if (ft_strncmp(str_set[0], "sp", 3) == 0)
		set_sphere(img, str_set, ft_strsetlen(str_set));
	else if (ft_strncmp(str_set[0], "pl", 3) == 0)
		set_plane(img, str_set, ft_strsetlen(str_set));
	else if (ft_strncmp(str_set[0], "cy", 3) == 0)
		set_cylinder(img, str_set, ft_strsetlen(str_set));
	else if (ft_strncmp(str_set[0], "#", 2) == 0)
		return ;
	else
		handling_error(WRONG_ARG);
}

void	parse_rt_file(t_data *img, int fd)
{
	int		chk_camera;
	char	*line;
	char	**str_set;

	chk_camera = 0;
	line = get_next_line(fd);
	while (line)
	{
		str_set = ft_split_s(line, " \n\t\r\v\f");
		if (*str_set != NULL)
		{
			if (ft_strncmp(str_set[0], "C", 2) == 0)
				chk_camera = 1;
			judge_object(img, str_set);
		}
		free_split(str_set);
		free(line);
		line = get_next_line(fd);
	}
	if (chk_camera == 0)
		handling_error(NO_CAMERA);
}
