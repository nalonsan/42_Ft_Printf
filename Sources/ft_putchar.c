/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:29:44 by marvin            #+#    #+#             */
/*   Updated: 2020/08/02 19:29:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void    ft_putchar(t_point *struc)
{
    struc->result = va_arg(struc->args, char*);
    struc->count += write(1, &(struc->result), 1);
}