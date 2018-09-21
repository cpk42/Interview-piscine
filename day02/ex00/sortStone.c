/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:44:18 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/19 16:20:38 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int		countStones(struct s_stone **stone)
{
	struct s_stone *tmp;
	int i = 0;

	tmp = *stone;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		*stoneToArray(struct s_stone **stone, int *result)
{
	struct s_stone *tmp;
	int i;

	i = 0;
	tmp = *stone;
	while (tmp)
	{
		result[i++] = tmp->size;
		tmp = tmp->next;
	}
	return (result);
}

void	flipStones(int *stones, int start, int end)
{
	int swap;
	int length;
	length = end - start;
	while (start <= end)
	{
		swap = stones[start];
		stones[start] = stones[end];
		stones[end] = swap;
		start++;
		end--;
	}
}

void	groupStones(int *stone, int length)
{
	int start = 0;
	int end = 0;
	int i = 0;

	while (i < length)
	{
		if (i + 1 < length && stone[i] > stone[i + 1])
		{
			start = i;
			end = i + 1;
			while (stone[start - 1] == stone[start] && start - 1 >= 0)
				start--;
			while (stone[end + 1] == stone[end] && end + 1 < length)
				end++;
			flipStones(stone, start, end);
			i = 0;
			}
		i++;
	}
}

void sortStones(struct s_stone **stone)
{
	struct s_stone *sorted;
	int	*result;
	int	length;

	sorted = *stone;
	length = countStones(stone);
	result = (int *)malloc(sizeof(int *) * length);
	result = stoneToArray(stone, result);
	groupStones(result, length);
	for (int i = 0; i < length && sorted; i++)
	{
		sorted->size = result[i];
		sorted = sorted->next;
	}
}
