/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 07:44:31 by nalonso-          #+#    #+#             */
/*   Updated: 2020/07/30 22:52:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/ft_printf.h"

int     ft_printf(const char *format, ...)
{
    t_point   struc;
    struc.i = 0;
    struc.count = 0;
    va_start(struc.args, format);
    while(format[struc.i] != '\0')
    {
      if(format[struc.i] == '%')
      {
        struc.i++;
        ft_parser(&struc, format);
        }
      else {
        struc.count = write(1, &format[struc.i], 1);
      }
      struc.i++;
    }
    va_end(struc.args);
    return(struc.count);
}
