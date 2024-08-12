/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:32:30 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/12 10:32:16 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char *strjoin_free(char *s1, char *s2)
{
	char *result;

	if (!s1)
	{
		result = ft_strdup(s2);
		free(s2);
		return (result);
	}
	if (!s2)
		return (s1);
	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

static char *create_str(int fd)
{
	char *line;
	char *str;

	line = get_next_line(fd);
	if (!line)
	{
		perror("Map file is empty!");
		exit(1);
	}
	str = NULL;
	str = ft_strdup("");
	while (line)
	{
		str = strjoin_free(str, line);
		line = get_next_line(fd);
	}
	free(line);
	return (str);
}
char	**parsing_map(char *map)
{
	int	fd;
	char	*str;
	char	**map_str;
	

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (NULL);
	}
	str = create_str(fd);
	map_str = ft_split(str, '\n');
	free(str);
	close(fd);
	return (map_str);
}
