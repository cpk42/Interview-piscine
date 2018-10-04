/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:23:37 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/19 16:46:52 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	swap(struct s_player **players, int idx)
{
	int		tmpscore;
	char	*tmpname;

	tmpscore = players[idx]->score;
	tmpname = players[idx]->name;
	players[idx]->score = players[idx - 1]->score;
	players[idx]->name = players[idx - 1]->name;
	players[idx - 1]->score = tmpscore;
	players[idx - 1]->name = tmpname;
}

void	insertionSort(struct s_player **players)
{
	int i;

	i = 1;
	while (players[i])
	{
		if (i >= 1 && (players[i])->score > (players[i - 1])->score)
		{
			while (i >= 1 && (players[i])->score > (players[i - 1])->score)
				swap(players, i--);
			i = 0;
		}
		i++;
	}
}
