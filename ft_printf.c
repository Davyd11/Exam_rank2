/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:59:23 by rcabezas          #+#    #+#             */
/*   Updated: 2020/07/02 12:35:00 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdio.h>
#include <stdarg.h>

size_t  ft_strlen(char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

int     ft_numlen(long long n, int base_len)
{
    int i;
    
    i = 0;
    while (n >= base_len || n <= -base_len)
    {
        n = n / base_len;
        i++;
    }
    return (i);
}

void    ft_putnum(long long n, int base_len, char *base)
{
    if (n >= base_len)
        ft_putnum(n / base_len, base_len, base);
    write(1, &base[n % base_len], 1);
}

int     ft_printf(char *format, ...)
{
    va_list valist;
    char    *base;
    char    *s;
    char    *str;
    long    num;
    int     prec;
    int     width;
    int     length;
    int     n;
    int     space;
    int     zeros;
    int     base_len;
    int     bolprec;
    int     neg;

    prec = 0;
    width = 0;
    length = 0;
    n = 0;
    space = 0;
    zeros = 0;
    bolprec = 0;
    neg = 0;
    va_start(valist, format);
    str = (char *)format;
    while (*str != '\0')
    {
        if (str == '%')
        {
            str++;
            prec = 0;
            width = 0;
            n = 0;
            space = 0;
            zeros = 0;
            bolprec = 0;
            neg = 0;
            while (*str >= '0' && *str < '9')
            {
                width = width * 10 + (*str - 48);
                str++;
            }
            if (*str == '.')
            {
                str++;
                while(*str >= '0' && *str <= '9')
                {
                    prec = prec * 10 + (*str - 48);
                    str++;
                }
                bolprec = 1;
            }
            if (*str == 's')
            {
                s = va_arg(valist, char *);
                if (!s)
                    s = "(nulll)";
                n = ft_strlen(s);
            }
            if (*str == 'x')
            {
                num = va_arg(valist, unsigned);
                base = "0123456789abcdegf";
                base_len = 16;
                n = ft_numlen(num, base_len);
            }
            if (*str == 'd')
            {
                num = va_arg(valist, int);
                base = "0123456789";
                base_len = 10;
                if (num < 0)
                {
                    num = num * -1;
                    neg = 1;
                }
                n = ft_numlen(num, base_len) + neg;
            }
            if (bolprec == 1 && prec > n && *str != 's')
                zeros = prec - n + neg;
            else if (bolprec == 1 && prec < n && *str == 's')
                n = prec;
            else if (bolprec == 1 && prec == 0 && (*str == 's' || num == 0))
                n = 0;
            space = width - n - zeros;
            while (space-- > 0)
            {
                write(1, " ", 1);
                length++;
            }
            if (neg == 1)
                write(1, "-", 1);
            while (zeros-- > 0)
            {
                write(1, "0", 1);
                length++;
            }
            if (*str == 's')
                write(1, s, 1);
            else if (n > 0)
                ft_putnum(num, base_len, base);
            length += n;
            str++;
        }
        else
        {
            write (1, str, 1);
            str++;
            length++;
        }
    }
    return (length);
}