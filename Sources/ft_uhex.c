/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:10:23 by marvin            #+#    #+#             */
/*   Updated: 2020/07/14 18:10:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

/*void    ft_uhex(/*unsigned int uhex_res, t_point *struc, const char *format)
{
    unsigned int hex_resu;
    int hex_res;
    unsigned int hex_rest;
    unsigned char *s_hex;
    
    struc->res_uhex = va_arg(struc->args, int);
    hex_resu = struc->res_uhex;
    if(struc->res_uhex)
    {   
        s_hex = "0123456789abcdef";
        if(format[struc->i] == 'X')
            s_hex = "0123456789ABCDEF";
    }
    if(hex_resu >= 16)
    {
        hex_res = hex_resu % 16;
        ft_uhex(/*hex_resu / 16, struc, format); //recursión
        
        hex_resu = hex_resu / 16;
        struc->count += write(1, &s_hex[hex_res], 1);
    }
    if(struc->res_uhex < 16)
    {
        hex_rest = struc->res_uhex % 16;
        struc->count = write(1, &s_hex[hex_rest], 1);
    }
}*/

void    ft_uhex(unsigned int uhex_res, t_point *struc, const char *format)
{
    unsigned int hex_resu;
    int hex_res;
    unsigned int hex_rest;
    unsigned char *s_hex;
    
    hex_resu = uhex_res;
    if(uhex_res)
    {   
        s_hex = "0123456789abcdef";
        if(format[struc->i] == 'X')
            s_hex = "0123456789ABCDEF";
    }
    if(hex_resu >= 16)
    {
        hex_res = hex_resu % 16;
        ft_uhex(hex_resu / 16, struc, format); //recursión
        struc->count += write(1, &s_hex[hex_res], 1);
    }
    if(uhex_res < 16)
    {
        hex_rest = uhex_res % 16;
        struc->count = write(1, &s_hex[hex_rest], 1);
    }
}
