/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:37:50 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/17 17:28:19 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>
int     ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*((unsigned char *)s1) - *((unsigned char *)s2));
}

int binarySearch(struct s_art **arts, int start, int len, char *name)
{
	int mid;

	while (start <= len)
	{
		mid = start + (len-start) / 2;
		printf("mid %d\n", mid);
		if (!ft_strcmp((arts[mid])->name, name))
			return ((arts[mid])->price);
		if (ft_strcmp((arts[mid])->name, name) < 0)
			start = mid + 1;
		else
			len = mid - 1;
	}
	return (-1);
}

int	searchPrice(struct s_art **arts, int n, char *name)
{
	printf("%s %d\n", (arts[82512])->name, n);
	return (binarySearch(arts, 0, n-1, name));
}
