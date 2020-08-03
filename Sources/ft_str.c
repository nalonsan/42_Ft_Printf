/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:45:13 by marvin            #+#    #+#             */
/*   Updated: 2020/08/02 19:45:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void    ft_str_flags(t_point *struc, const char *format)
{
    if(struc->key_zeroes == 1 || struc->key_joker == 1 || 
    struc->key_left_justify == 1)
        struc->i++;
    if(struc->key_nbr == 1) //reserva n espacios e imprime pegado a la dcha
    {    
        //ft_flag_nbr();

    }
    if(struc->key_precision == 1) //'.'
    {
        //ft_flag_precision();
        while(struc->i++ >= '1' && struc->i++ <= '9')
        {
            struc->i++;
        }
    }

}

void    ft_str(t_point *struc, const char *format)
{
    int     z;
    
    struc->result = NULL;
    struc->result = va_arg(struc->args, char*);
    z = 0;
    ft_str_flags(struc, format);
    while(struc->result[z])
    {
        struc->count += write(1, &(struc->result[z]), 1);
        z++;
    }
}