/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:05:58 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/24 20:45:54 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int isFilled(unsigned int parkingRow)
{
    if((parkingRow & (-(~parkingRow))))
        return (0);
    if (parkingRow)
        return (1);
    else
        return (0);
}
