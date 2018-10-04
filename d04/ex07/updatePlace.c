/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:31:19 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/24 20:04:38 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int clearPlace(unsigned int parkingRow, int pos)
{
	parkingRow &= ~(1<<pos);
	return (parkingRow);
}

int getPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow >> pos & 1 ? 1 : 0);
}

unsigned int setPlace(unsigned int parkingRow, int pos)
{
	parkingRow |= (1<<pos);
	return (parkingRow);
}

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	if (value)
		parkingRow = setPlace(parkingRow, pos);
	else
		parkingRow = clearPlace(parkingRow, pos);
	return (parkingRow);
}
