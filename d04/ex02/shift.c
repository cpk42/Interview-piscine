/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:53:27 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/25 17:16:45 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *rightShift(char *bin, int k)
{
	char *res = malloc(7);
	res[6] = 0;

	memset(res, '0', 6);
	for (int i = 0; i + k < 6; i++)
		res[i + k] = bin[i];
	for (int i = 0; k--; i++)
		res[i] = '1';
	return (res);
}

char *leftShift(char *bin, int k)
{
	char *res = malloc(7);
	res[6] = 0;

	memset(res, '0', 6);
	for (int i = 5; i - k >= 0; i--)
		res[i - k] = bin[i];
	for (int i = 5; k--; i--)
		res[i] = '0';
	return (res);
}

char *twoscomp(char *a)
{
	int c;

	c = 1;
	for (int i = 5; i >= 0; i--)
	{
		a[i] = (a[i] == '1') ? '0' : '1';
		if (a[i] - '0' + c == 1)
		{
			a[i] = '1';
			c = 0;
		}
		else if (a[i] - '0' + c == 2)
		{
			a[i] = '0';
			c = 1;
		}
	}
	return (a);
}

int toInt(char *bits)
{
	int ret;
	int sign;
	char *tmp;

	ret = 0;
	sign = 1;
	tmp = strdup(bits);
	if (*tmp == '1')
	{
		sign = -1;
		tmp = twoscomp(tmp);
	}
	while (*tmp)
	{
		ret = ret * 2 + *tmp - '0';
		tmp += 1;
	}
	return (ret * sign);
}
