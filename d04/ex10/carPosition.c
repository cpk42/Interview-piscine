/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:25:58 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/25 16:29:11 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int carPosition(unsigned int parkingRow)
{
    unsigned int shift = 0;
    if ((((parkingRow>>1) | (parkingRow&1)) + ~0U) >> 31)
        return (-1);
    while (((((parkingRow >> shift) & 1>>1) | ((parkingRow >> shift) & 1&1)) + ~0U) >> 31)
        shift++;
    if (parkingRow >> (shift + 1))
        return (-1);
    return shift;
}
