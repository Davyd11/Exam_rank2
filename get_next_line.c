/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:35:40 by rcabezas          #+#    #+#             */
/*   Updated: 2020/07/02 13:13:01 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t  ft_strlen(char *s)
{
    size_t  i;
    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strchr(char *str, int c)
{
    unsigned int    i;
    unsigned int    length;
    
    i = 0;
    if (!str)
        return (NULL);
    length = ft_strlen(str);
    while (*str != '\0' && *str != c)
    {
        str++;
        i++;
    }
    if (*str != c && i == length)
        return (NULL);
    return (str);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *dest;
    int     i;
    
    i = 0;
    if (!(dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
        return (NULL);
    while (*s1 != '\0')
        dest[i++] = *s1++;
    while (*s2 != '\0')
        dest[i++] = *s2++;
    dest[i] = '\0';
    return (dest);
}

char    *ft_strdup(char *str)
{
    int i;
    char *dest;
    i = 0;
    if (!(dest = malloc(ft_strlen(str) + 1)))
        return (NULL);
    while (str[i] != '\0')
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int     getcharpls(char **line, char **aux, int n)
{
    char *temp1;
    char *temp2;
    
    if (n < 0)
    {
        if (*aux != NULL)
        {
            free(*aux);
            *aux = NULL;
        }
        return (-1);
    }
    if (!n && !*aux)
    {
        *line = ft_strdup("");
        return (0);
    }
    if ((temp1 = ft_strchr(*aux, '\n')))
    {
        *temp1 = 0;
        *line = ft_strdup(*aux);
        temp2 = ft_strdup(++temp1);
        free(*aux);
        *aux = temp2;
    }
    else
    {
        *line = ft_strdup(*aux);
        free(*aux);
        *aux = NULL;
        return (0);
    }
    return (1);
}

int     get_next_line(char **line)
{
    static char     *aux;
    char            buffer[65];
    char            *temp;
    int             n;
    if (!line)
        return (-1);
    while (ft_strchr(aux, '\n') == NULL)
    {
        n = read(0, buffer, 64);
        if (n < 0)
            return (-1);
        if (n == 0)
            break ;
        buffer[n] = 0;
        if (!aux)
            aux = ft_strdup(buffer);
        else
        {
            temp = ft_strjoin(aux, buffer);
            free(aux);
            aux = temp;
        }
    }
    return (getcharpls(line, &aux, n));
}