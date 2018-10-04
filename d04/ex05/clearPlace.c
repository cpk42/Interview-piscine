/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearPlace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:31:19 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/24 19:53:03 by ckrommen         ###   ########.fr       */
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
