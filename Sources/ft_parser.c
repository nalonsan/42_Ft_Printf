/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:40:54 by marvin            #+#    #+#             */
/*   Updated: 2020/07/14 12:40:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int     ft_parser_conversion(t_point *struc, const char *format)
{
    if(format[struc->i] == 's')
        ft_str(struc, format);
    else if(format[struc->i] == 'c')
        ft_putchar(struc);
    else if(format[struc->i] == 'd' || format[struc->i] == 'i') // int argument --> signed decimal notation
    {        
        struc->res_int = va_arg(struc->args, int);
        ft_putnbr_fd(struc->res_int);
    }
    else if(format[struc->i] == 'u') //unsigned int converted to unsigned decimal
    {
        struc->res_uint = va_arg(struc->args, unsigned int);
        ft_uint(struc->res_uint, struc);
    }
    else if(format[struc->i] == 'x' || format[struc->i] == 'X') //unsigned int converted to unsigned hexadecimal - lowercase
    {
        struc->res_uhex = va_arg(struc->args, int);
        ft_uhex(struc->res_uhex, struc, format);
    }
    else if(format[struc->i] == 'p') // el result es la dirección de mem de un puntero.
        ft_pointer(struc, format);
}

int     ft_parser_flags(t_point *struc, const char *format)
{
    //struc->count = write(1, "ok4flags", 9);
    struc->key_joker = 0;
    struc->key_zeroes = 0;
    struc->key_nbr = 0;
    struc->key_left_justify = 0;
    struc->key_precision = 0;
    while(format[struc->i] == '-' || format[struc->i] == '*' || 
        (format[struc->i] >= '0' && format[struc->i] <= '9') || 
        format[struc->i] == '.')
    {
        if(format[struc->i] == '*')
            struc->key_joker = 1;
            //ft_flag_joker_nbr(); //se coge valor de argumento extra¡!
        else if(format[struc->i] == '0')
            struc->key_zeroes = 1;
            //ft_flag_zeroes();
        else if(format[struc->i] >= '1' && format[struc->i] <= '9')
            struc->key_nbr = 1;
            //ft_flag_nbr();
        else if(format[struc->i] == '-')
            struc->key_left_justify = 1;
            //ft_flag_left_justify(); // siempre necesita un nbr ó *
        else if(format[struc->i] == '.')
            struc->key_precision = 1;
            //ft_flag_precision(); //siempre necesita un nbr delante ó * (nbr)
        struc->i++;
    }
}

int    ft_parser(t_point *struc, const char *format)
{   
    if(format[struc->i] == '%')
        /*struc->count += write(1, struc->result + struc->i - 1, 1); ALSO WORKS */
        struc->count += write(1, "%", 1);
    
    else if(format[struc->i] == '-' || format[struc->i] == '*' || 
            (format[struc->i] >= '0' && format[struc->i] <= '9') || 
            format[struc->i] == '.')
    {
        ft_parser_flags(struc, format);
    }
    else if(format[struc->i] == 's' || format[struc->i] == 'c' || 
            format[struc->i] == 'd' || format[struc->i] == 'i' || 
            format[struc->i] == 'u' || format[struc->i] == 'x' || 
            format[struc->i] == 'X' || format[struc->i] == 'p')
    {
        ft_parser_conversion(struc, format);
    }
  }