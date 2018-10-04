/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:11:09 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/20 22:17:00 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int getDescription(struct s_info *info)
{
	return( info->gender * pow(10,6)
			+ info->height * pow(10,5)
			+ info->hairColor * pow(10,4)
			+ info->eyeColor * pow(10,3)
			+ info->glasses * pow(10,2)
			+ info->tattoo * pow(10,1)
			+ info->piercing * pow(10,0));
}

int	getMax(struct s_criminal **criminals)
{
	int max = criminals[0]->description;
	for (int i = 0; criminals[i]; i++)
		if (criminals[i]->description > max)
			max = criminals[i]->description;
	return (max);
}

int	getSize(struct s_criminal **criminals)
{
	int i;
	for (i = 0; criminals[i]; i++)
		;
	return (i);
}

static void countSort(struct s_criminal **criminals, int exp, int len)
{
	struct s_criminal *output[len];
	int i, count[10] = {0};

	for (i = 0; i < len; i++)
	{
		int index = (criminals[i]->description/exp) % 10;
		count[index]++;
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = len - 1; i >= 0; i--)
	{
		int index = (criminals[i]->description/exp) % 10;
		output[count[index] - 1] = criminals[i];
		count[index]--;
	}
	for (i = 0; i < len; i++)
		criminals[i] = output[i];
}

void sortCriminals(struct s_criminal **criminals)
{
	int len = getSize(criminals);
	int max = getMax(criminals);
	for (int i = 1; max / i > 0; i*=10)
		countSort(criminals, i, len);
}

static int binarySearch(struct s_criminal **criminals, int low, int high, int val)
{
	int mid = (low + high) / 2;

	if (high < low)
		return -1;
	if (val == criminals[mid]->description)
		return mid;
	if (val > criminals[mid]->description)
		return binarySearch(criminals, (mid + 1), high, val);
	else
		return binarySearch(criminals, low, (mid -1), val);
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	struct s_criminal **potential;
	int i;
	int j;
	int desc = getDescription(info);
	int res = binarySearch(criminals, 0, getSize(criminals)-1, desc);

	for (i = res; criminals[i] && (criminals[i])->description == desc; i++)
		;
	while (res > 0 && (criminals[res])->description == desc)
		res--;
	potential = malloc(sizeof(struct s_criminal *) * (i - res));
	bzero(potential, (i - res));
	j = res + 1;
	for (int x = 0; j < i; j++, x++)
		potential[x] = criminals[j];
	return potential;
}
