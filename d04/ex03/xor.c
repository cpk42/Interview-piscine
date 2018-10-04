/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:06:55 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/24 15:12:10 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *getXor(char *a, char *b)
{
	char *res = malloc(7);
	res[6] = 0;

	for (int i = 0; i < 6; i++)
		res[i] = ((a[i] - '0') ^ (b[i] - '0')) + 48;
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
