/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:08:43 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/20 15:58:25 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	binarySearch(int *rocks, int len, int key)
{
	int left = 0;
	int right = len - 1;
	
	while (left <= right) 
	{
		int mid = left + ((right - left) / 2);
		if (rocks[mid] == key) 
			return (mid);
		if (rocks[left] <= rocks[mid]) 
		{
			if (rocks[left] <= key && key < rocks[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		else
		{
			if (rocks[mid] < key && key <= rocks[right])
				left = mid + 1;
			else 
				right = mid - 1;
		}
	}
	return (-1);
}

int	searchShifted(int *rocks, int length, int value)
{
	int ret;
	
	if (rocks[0] == value)
		return (0);
	ret = binarySearch(rocks, length - 1, value);
	while (rocks[ret - 1] == value && ret > 0)
		ret--;
	return (ret);
}
