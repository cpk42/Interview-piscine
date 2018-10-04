/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:02:54 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/24 13:26:58 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *getSum(char *a, char *b)
{
	char *res = malloc(7);
	int carry = 0;
	res[7] = 0;

	for (int i = 5; i >= 0; i--)
	{
		if (a[i] == '1')
			carry += 1;
		if (b[i] == '1')
			carry += 1;
		res[i] = (carry % 2) + '0';
		if (carry >= 2)
			carry = 1;
		else
			carry = 0;
	}
	return (res);
}

int toInt(char *bits)
{
	int ret = 0;
	int factor = 32;

	for (int i = 0; i < 6; i++)
	{
		ret += ((bits[i] - '0') * factor);
		factor /= 2;
	}
	return (ret);
}

