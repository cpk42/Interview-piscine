/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 21:23:36 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/24 21:25:03 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	occupiedPlaces(unsigned int parkingRow)
{
	int	count = 0;

	while (parkingRow)
	{
		parkingRow = parkingRow & ~(-parkingRow);
		count = -(~count);
	}
	return (count);
}
