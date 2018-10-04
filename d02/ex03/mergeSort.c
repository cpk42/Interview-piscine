/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:28:53 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/20 14:45:22 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	countPlayers(struct s_player **players)
{
	int i;

	i = 0;
	while (players[i])
		i++;
	return (i);
}

void	merge(struct s_player **players, int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	struct s_player *tmpright[2048];
	struct s_player *tmpleft[2048];

	for (i = 0; i < n1; i++)
		tmpleft[i] = players[left + i];
	for (j = 0; j < n2; j++)
		tmpright[j] = players[middle + 1 + j];
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if ((tmpleft[i])->score >= (tmpright[j])->score)
		{
			players[k] = tmpleft[i];
			i++;
		}
		else
		{
			players[k] = tmpright[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		players[k] = tmpleft[i];
		k++;
		i++;
	}
	while (j < n2)
	{
		players[k] = tmpright[j];
		k++;
		j++;
	}
}

void sort(struct s_player **players, int left, int right)
{
	if (left < right)
	{
		int middle = left+(right-left)/2;

		sort(players, left, middle);
		sort(players, middle+1, right);
		merge(players, left, middle, right);
	}
}

struct s_player **mergeSort(struct s_player **players)
{
	int n = countPlayers(players);

	sort(players, 0, n - 1);
	return (players);
}
