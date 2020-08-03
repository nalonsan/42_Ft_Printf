/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 22:12:23 by marvin            #+#    #+#             */
/*   Updated: 2020/07/22 22:12:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void    ft_uhex_long(unsigned long int uhex_res, t_point *struc, const char *format)
{
    unsigned long int hex_resu;
    unsigned long int hex_res;
    unsigned long int hex_rest;
    unsigned char *s_hex;

    hex_resu = uhex_res;
    if(uhex_res)
        s_hex = "0123456789abcdef";
    if(hex_resu >= 16)
    {
        hex_res = hex_resu % 16;
        ft_uhex_long(hex_resu / 16, struc, format);
        struc->res_point += write(1, &s_hex[hex_res], 1);
    }
    if(uhex_res < 16)
    {
        hex_rest = uhex_res % 16;
        struc->res_point = write(1, &s_hex[hex_rest], 1);
    }
}

void    *ft_pointer(/*unsigned long int res_point, */t_point *struc, const char *format)
{
    unsigned long int       point_hexa_value;
    
    struc->res_point = va_arg(struc->args, unsigned long int);
    point_hexa_value = struc->res_point;
    struc->res_point = write(1, "0x", 2);
    ft_uhex_long(point_hexa_value, struc, format);
}