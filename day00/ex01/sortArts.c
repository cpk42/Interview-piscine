/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:59:24 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/17 17:00:28 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h> //printf, scanf, ...
#include <string.h>

void	swap(struct s_art **arts, int i, int largest)
{
	struct s_art *tmp;

	tmp = arts[i];
	arts[i] = arts[largest];
	arts[largest] = tmp;
}

void	heapify(struct s_art **arts, int n, int i)
{
    int largest;
    int l;
    int r;
 
	largest = i;
	l = 2*i + 1;
	r = 2*i + 2;
    // If left child is larger than root
    if (l < n && strcmp((char *)(arts[l]->name), (char *)(arts[largest]->name)) > 0)
        largest = l;
    // If right child is larger than largest so far
    if (r < n && strcmp((char *)(arts[r]->name), (char *)(arts[largest]->name)) > 0)
        largest = r;
    // If largest is not root
    if (largest != i)
    {
        swap(arts, i, largest);
        // Recursively heapify the affected sub-tree
        heapify(arts, n, largest);
    }
}

void	heapSort(struct s_art **arts, int n)
{
	int i;

	i = n / 2 - 1;
    // Build heap (rearrange array)
    while (i >= 0)
        heapify(arts, n, i--);
	i = n - 1;
    // One by one extract an element from heap
    while (i >= 0)
    {
        swap(arts, 0, i);
        heapify(arts, i, 0);
		i--;
    }
}

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

void	sortArts(struct s_art **arts)
{
	int n;

	n = countElems(arts);
	heapSort(arts, n);
}
