/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:37:23 by rcabezas          #+#    #+#             */
/*   Updated: 2020/07/16 12:22:34 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t  ft_strlen(const char *s)
{
    size_t i = 0;
    
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strchr(const char *s, int c)
{
    unsigned int len;
    unsigned int i;
    
    i = 0;
    len = ft_strlen(s);
    while (*s != c && *s)
    {
        s++;
        i++;
    }
    if (len == i && *s != c)
        return (NULL);
    return ((char *)s);
}

int     main(int argc, char **argv)
{
    int used[255];
    int x;

    x = 0;
    if (argc == 3)
    {
        while (x < 255)
            used[x++] = 0;
        x = 0;
        while (argv[1][x])
        {
            if (!used[(unsigned char)argv[1][x]] && ft_strchr(argv[2], argv[1][x]))
            {
                used[(unsigned char)argv[1][x]] = 1;
                write(1, &argv[1][x], 1);
            }
            x++;
        }
        write(1, "\n", 1);
    }
    return (0);
}