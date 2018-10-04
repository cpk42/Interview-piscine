/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearBits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:38:13 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/25 16:42:13 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int clearPlace(unsigned int parkingRow, int pos)
{
	parkingRow &= ~(1<<pos);
	return (parkingRow);
}

unsigned int clearBits(unsigned int parkingRow, int n)
{
	while (n-- >= 0)
		parkingRow = clearPlace(parkingRow, n);
	return (parkingRow);
}
