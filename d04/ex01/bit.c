/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:49:03 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/24 19:40:23 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char *getAnd(char *a, char *b)
{
	char *res = malloc(5);
	int aNeg = a[0] == '~' ? 1 : 0;
	int bNeg = b[0] == '~' ? 1 : 0;
	int an = aNeg ? 1 : 0;
	int bn = bNeg ? 1 : 0;

	res[4] = 0;
	for (int i = 0; i < 4; i++)
	{
		if (aNeg)
			a[an] = a[an] == '1' ? '0' : '1';
		if (bNeg)
			b[bn] = b[bn] == '1' ? '0' : '1';
		res[i] = ((a[an] - '0') & (b[bn] - '0')) + 48;
		an++;
		bn++;
	}
	return (res);
}

char *getOr(char *a, char *b)
{
	char *res = malloc(5);
	int aNeg = a[0] == '~' ? 1 : 0;
	int bNeg = b[0] == '~' ? 1 : 0;
	int an = aNeg ? 1 : 0;
	int bn = bNeg ? 1 : 0;

	res[4] = 0;
	for (int i = 0; i < 4; i++)
	{
		if (aNeg)
			a[an] = a[an] == '1' ? '0' : '1';
		if (bNeg)
			b[bn] = b[bn] == '1' ? '0' : '1';
		res[i] = ((a[an] - '0') | (b[bn] - '0')) + 48;
		an++;
		bn++;
	}
	return (res);
}

int toInt(char *bits)
{
	int ret = 0;
	int factor = 8;

	for (int i = 0; i < 4; i++)
	{
		ret += ((bits[i] - '0') * factor);
		factor /= 2;
	}
	return (ret);
}
