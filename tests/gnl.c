/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:30:26 by davyd11           #+#    #+#             */
/*   Updated: 2020/07/16 22:25:11 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t	ft_strlen(const char *word)
{
	int x = 0;
	while (word[x])
		x++;
	return (x);
}

char *ft_strdup(char *s)
{
	int x;
	char *dest;
	char *temp;
	
	x = 0;
	if (!(temp = malloc(ft_strlen(s) + 1))) 
		return (0);
	while (s[x] != '\0')
	{
		temp[x] = s[x];
		x++;
	}
	temp[x] = '\0';
	dest = temp;
	free(temp);
	return (dest);
}

char *ft_strjoin (char *s, char *c)
{
	int x;
	char *dest;
	char *temp;
	
	x = 0;
	if (!(temp = malloc(ft_strlen(s) + 2))) 
		return (0);
	while (s[x] != '\0')
	{
		temp[x] = s[x];
		x++;
	}
	temp[x] = c[0];
	temp[x + 1] = '\0';
	dest = temp;
	free(temp);
	return (dest);
}

int get_next_line(char **line)
{
	char buf[1];
	int ret;
	
	if (!(line == '\0') || !(*line = ft_strdup("")))
		return (-1);
	while ((ret = read(0, buf,1)) > 0)
	{
		if (buf[0] == '\0' || buf[0] == '\n')
		{
			buf[0] = '\0';
			break;
		}
		*line = ft_strjoin(*line, buf);
	}
	buf[0] = '\0';
	return (ret);
}