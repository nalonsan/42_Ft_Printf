/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 08:04:37 by nalonso-          #+#    #+#             */
/*   Updated: 2020/08/02 21:02:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// LIBRARIES
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
//# include "/LIbft_Printf/libft.h"

// STRUCTURES
typedef struct s_point
{
    va_list             args;
    char                *result;
    int                 count;
    int                 i;
    int                 key_joker;
    int                 key_zeroes;
    int                 key_nbr;
    int                 key_left_justify;
    int                 key_precision;
    int                 res_int;
    unsigned int        u_count;
    unsigned int        res_uint;
    unsigned int        res_uhex;
    unsigned long int   res_point;
}               t_point; //typedef_point

// PROTOTYPES
int     main();
int     ft_printf(const char *format, ...);
int     ft_parser(t_point *struc, const char *format);
void    ft_str(t_point *struc, const char *format);
void    ft_putchar(t_point *struc);
//int     ft_parser_conversion(t_point *struc, const char *format);
void    ft_putnbr_fd(int n);
void    ft_uint(unsigned int u_res, t_point *struc);
void    ft_uhex(unsigned int uhex_res, t_point *struc, const char *format);
void    *ft_pointer(/*unsigned long int res_point, */t_point *struc, const char *format);
//void    ft_uint_long(unsigned int u_res, t_point *struc);
//void    ft_uhex_long(unsigned long int uhex_res, t_point *struc, const char *format);
//void    ft_flag_left_justify()
//void    ft_flag_nbr()
//void    ft_flag_joker_nbr()
//void    ft_flag_precision()
//void    ft_flag_zeroes()

#endif
