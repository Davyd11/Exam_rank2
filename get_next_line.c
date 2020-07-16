/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:35:40 by rcabezas          #+#    #+#             */
/*   Updated: 2020/07/16 11:03:26 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i;
    
    i = 0;
    while (s[i] != '\0')
        i++;
    return(i);
}

char *ft_strdup(char *s)
{
    int i;
    char *dest;
    char *tmp;

    i = 0;
    if (!(tmp = malloc(ft_strlen(s) + 1)))
        return (0);
    while (s[i] != '\0')
    {
        tmp[i] = s[i];
        i++;
    }
    tmp[i] = '\0';
    dest = tmp;
    free(tmp);
    return (dest);
}

char *ft_strjoin(char *s, char *c)
{
    int i;
    char *dest;
    char *tmp;

    i = 0;
    if (!(tmp = malloc(ft_strlen(s) + 2)))
        return (0);
    while (s[i] != '\0')
    {
        tmp[i] = s[i];
        i++;
    }
    tmp[i] = c[0];
    tmp[i + 1] = '\0';
    dest = tmp;
    free(tmp);
    return (dest);
}

int get_next_line(char **line)
{
    char buf[1];
    int ret;

    if (line == '\0' || !(*line = ft_strdup("")))
        return (-1);
    while ((ret = read(0, buf, 1)) > 0)
    {
        if (buf[0] == '\n' || buf[0] == '\0')
        {
            buf[0] = '\0';
            break ;
        }
        *line = ft_strjoin(*line, buf);
    }
    buf[0] = '\0';
    return (ret);
}