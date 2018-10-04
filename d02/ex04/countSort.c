/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:21:29 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/19 22:02:41 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void countSort(unsigned char *utensils, int n)
{
	int	count[16] = {0};
	unsigned char *copy;

	copy = (unsigned char *)malloc(sizeof(unsigned char) * n + 1);
	bzero(copy, n + 1);
	for (int i = 0; i < n; i++)
		count[utensils[i]] = count[utensils[i]] + 1;
	for (int i = 0; i < 16; i++)
		count[i + 1] = count[i] + count[i + 1];
	for (int i = 0; utensils[i]; i++)
		copy[count[utensils[i]] -= 1] = utensils[i];
	for (int i = 0; i < n; i++)
		utensils[i] = copy[i];
}
