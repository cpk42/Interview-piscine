/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightMostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 16:44:42 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/25 17:10:59 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

int rightmostCar(unsigned int parkingRow)
{
	int factor = 0;
	int base = 1;

	while (factor ^ 32)
	{
		if ((unsigned int)(parkingRow >> factor) & (unsigned int)pow(base, factor))
			return (factor);
		factor = -(~factor);
	}
	return (-1);
}