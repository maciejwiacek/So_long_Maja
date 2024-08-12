/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:32:30 by mbaj              #+#    #+#             */
/*   Updated: 2024/08/12 10:13:07 by mwiacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_map(int fd)
{
	char	*str;
	char	*line;
	char	*tmp;

	str = get_next_line(fd);
	if (!str)
	{
		perror("Map file is empty");
		return (NULL);
	}	
	line = get_next_line(fd);
	while (line)
	{
		tmp = str;
		str = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
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
	str = read_map(fd);
	map_str = ft_split (str, '\n');
	close(fd);
	free(str);
	return (map_str);
}
