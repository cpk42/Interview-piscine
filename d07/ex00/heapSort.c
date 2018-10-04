/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:36:37 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/27 18:32:12 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_art	**swap(struct s_art **masterpiece, int a, int b)
{
	struct s_art *ptr;

	ptr = masterpiece[a];
	masterpiece[a] = masterpiece[b];
	masterpiece[b] = ptr;
	return (masterpiece);
}

void heapify(struct s_art **masterpiece, int n, int i) 
{ 
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && strcmp(masterpiece[l]->name, masterpiece[largest]->name) > 0) 
		largest = l; 
	if (r < n && strcmp(masterpiece[r]->name, masterpiece[largest]->name) > 0)
		largest = r; 
	if (largest != i) 
	{ 
		masterpiece = swap(masterpiece, i, largest); 
		heapify(masterpiece, n, largest); 
	}
}

void heapSort(struct s_art **masterpiece, int n)
{ 
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(masterpiece, n, i); 
	for (int i = n - 1; i >= 0; i--) 
	{ 
		swap(masterpiece, 0, i); 
		heapify(masterpiece, i, 0); 
	} 
} 
