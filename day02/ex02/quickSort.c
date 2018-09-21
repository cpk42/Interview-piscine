/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:26:05 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/19 18:09:40 by ckrommen         ###   ########.fr       */
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

void	swap(struct s_player **players, int wall, int i)
{
	int	tmpscore;
	char	*tmpname;

	tmpscore = players[wall]->score;
	tmpname = players[wall]->name;
	players[wall]->score = players[i]->score;
	players[wall]->name = players[i]->name;
	players[i]->score = tmpscore;
	players[i]->name = tmpname;
}

int	getWall(struct s_player **players, int low, int high)
{
	int pivot = (players[high])->score;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if ((players[j])->score >= pivot)
		{
			i++;
			swap(players, i, j);
		}
	}
	swap(players, i+1, high);
	return (i + 1);
}

void sort(struct s_player **players, int low, int high)
{
	if (low < high)
	{
		int part = getWall(players, low, high);
		
		sort(players, low, part-1);
		sort(players, part+1, high);
	}
}

void quickSort(struct s_player **players)
{
	sort(players, 0, countPlayers(players)-1);
}
