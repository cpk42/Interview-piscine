/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:59:24 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/18 21:26:50 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>

int		countElems(struct s_art **arts)
{
	int i;

	i = 0;
	while (*arts)
	{
		i++;
		arts++;
	}
	return (i);
}

void	swap(struct s_art **arts, int i, int largest)
{
	struct s_art *tmp;

	tmp = arts[i];
	arts[i] = arts[largest];
	arts[largest] = tmp;
}

int		partition(struct s_art **arts, int l, int h)
{
	struct s_art *pivot = arts[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++)
	{
		if (strcmp(pivot->name, arts[j]->name) > 0)
		{
			i++;
			swap(arts, i, j);
		}
	}
	swap(arts, i + 1, h);
	return (i + 1);
}

void	quickSort(struct s_art **arts, int l, int h)
{
	if (l < h)
	{
		int pi = partition(arts, l, h);
		quickSort(arts, l, pi - 1);
		quickSort(arts, pi + 1, h);
	}
}

void	sortArts(struct s_art **arts)
{
	int n;

	n = countElems(arts);
	quickSort(arts, 0, n-1);
}
