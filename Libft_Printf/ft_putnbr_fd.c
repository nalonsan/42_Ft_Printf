/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:31:03 by marvin            #+#    #+#             */
/*   Updated: 2020/07/14 16:31:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void        ft_putstr_fd(char *str, int fd)
{
    int     i;

    i = 0;
    while(str[i] != '\0')
    {
        write(fd, &str[i], 1);
        i++;
    }
}

void        ft_putchar_fd(char n, int fd)
{
    write(fd, &n, 1);
}

void         ft_putnbr_fd(int n)
{
    int fd;

    fd = 1; 
    if(n == -2147483648)
    {
        ft_putstr_fd("-2147483648", fd);
    }
    else
    {
        if(n < 0)
        {
            write(fd, "-", 1);
            n = -n;
        }
        if(n / 10 > 0)
        {
            //write(1, "A", 1);
            ft_putnbr_fd(n / 10);
        }
        //write(1, "B", 1);
        ft_putchar_fd(n % 10 + '0', fd); //se suma el '0' ó +48 para convertirlo a char.
    }
}