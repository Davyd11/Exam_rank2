/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:09:08 by davyd11           #+#    #+#             */
/*   Updated: 2020/07/16 21:25:39 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t		ft_strlen(const char *word)
{
	size_t x = 0;
	
	while (word[x])
		x++;
	return (x);
}

char	*ft_strchr(const char *word, int c)
{
	unsigned int len;
	unsigned int b;

	len = ft_strlen(word);
	b = 0;

	while (*word != c && *word)
	{
		word++;
		b++;
	}
	if (len == b && *word != c)
		return (NULL);
	return ((char *) word);
}

int main (int argc, char **argv)
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
				write(1,&argv[1][x],1);
			}
			x++;
		}
		write(1,"\n",1);
	}
	return (0);
}