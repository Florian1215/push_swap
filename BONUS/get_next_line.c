/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguirama <fguirama@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:34:00 by fguirama          #+#    #+#             */
/*   Updated: 2022/12/27 14:34:00 by fguirama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/push_swap.h"

static int	find_nl(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

static char	*str_join(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	res = malloc(sizeof(char) * (str_len(s1) + str_len(s2) + 1));
	if (!res)
	{
		if (s2)
			free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	if (s2)
	{
		j = 0;
		while (s2[j])
			res[i++] = s2[j++];
		free(s1);
	}
	return (res[i] = '\0', res);
}

static char	*get_line(char *line, char *static_str)
{
	char	*res;
	int		i;
	int		j;
	int		nl;

	nl = find_nl(line);
	if (nl == -1)
		return (*static_str = '\0', line);
	res = malloc(sizeof(char) * (nl + 1));
	if (!res)
		return (free(line), NULL);
	i = -1;
	while (++i < nl)
		res[i] = line[i];
	res[i++] = '\0';
	j = 0;
	while (line[i])
		static_str[j++] = line[i++];
	return (static_str[j] = '\0', free(line), res);
}

char	*get_next_line(int fd)
{
	static char	static_str[20];
	char		buff[21];
	char		*line;
	int			read_bytes;

	line = str_join(static_str, NULL);
	if (!line)
		return (NULL);
	read_bytes = 1;
	while (find_nl(line) == -1 && read_bytes)
	{
		read_bytes = read(fd, buff, 20);
		if ((*line == '\0' && !read_bytes) || read_bytes < 0)
			return (free(line), *static_str = '\0', NULL);
		buff[read_bytes] = '\0';
		line = str_join(line, buff);
		if (!line)
			return (free(line), NULL);
	}
	return (get_line(line, static_str));
}
