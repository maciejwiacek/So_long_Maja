/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_without_newline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaj <mbaj@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:10:33 by mbaj              #+#    #+#             */
/*   Updated: 2024/07/30 21:14:53 by mbaj             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	len_without_newline(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n' || str[len] != '\0')
		len++;
	return (len);
}
