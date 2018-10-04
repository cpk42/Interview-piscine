/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:30:45 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/25 16:32:01 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int    carPosition(unsigned int parkingRow)
{
    int    ret = -1;
    if (parkingRow && (((parkingRow & (parkingRow - 1)>>1) | (parkingRow & (parkingRow - 1)&1)) + ~0U) >> 31)
        ret = (int)log2(parkingRow);
    return (ret);
}


