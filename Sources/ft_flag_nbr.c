/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 21:02:56 by marvin            #+#    #+#             */
/*   Updated: 2020/07/28 21:02:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void    ft_flag_nbr()
{
    if(format[struc->i] == '0')
    {
            //width filled with zeroes --> ft_bzero();
    }
    struc->i++;
    while(format[struc->i] >= '0' && format[struc->i] <= '9')
    {
        struc->i++; 
        // que reserve el nº de espacios del valor
    }
}