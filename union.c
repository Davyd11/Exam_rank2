/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:52:26 by rcabezas          #+#    #+#             */
/*   Updated: 2020/07/02 10:58:57 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int used[255];
    int x;
    int y;

    if (argc == 3)
    {
        x = 0;
        while (x++ < 255)
            used[x] = 0;
        x = 1;
        while (x < 3)
        {
            y = 0;
            while (argv[x][y])
            {
                if (!used[((unsigned char)argv[x][y])])
                {
                    used[((unsigned char)argv[x][y])] = 1;
                    write(1, &argv[x][y], 1);
                }
                y++;
            }
            x++;
        }
        write(1, "\n", 1);
    }
}