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

void    ft_uint(unsigned int u_res, t_point *struc)
{
    unsigned int resu;
    int res;
    unsigned int rest;
    
    resu = u_res;
    if(resu >= 10)
    {
        res = resu % 10 + '0';
        ft_uint(resu / 10, struc); //recursión
        struc->count = write(1, &res, 1);
    }
    if(u_res < 10)
    {
        rest = u_res % 10 + '0';
        struc->count += write(1, &rest, 1);
    }
}
