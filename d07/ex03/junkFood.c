/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:28:43 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/28 14:44:31 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct s_node *getCurrent(struct s_graph *parisPlaces, char *youAreHere)
{
	for (int i = 0; parisPlaces->places[i]; i++)
	{
		if (!strcmp(youAreHere, parisPlaces->places[i]->name))
			return (parisPlaces->places[i]);
	}
	return (NULL);
}

int	distance = 1;
int	x = 0;

struct s_sellers *findSellers(struct s_node *current, struct s_sellers *ret)
{
	for (int i = 0; current->connectedPlaces[i]; i++)
	{
		if (current->connectedPlaces[i]->hasCerealBar && !current->connectedPlaces[i]->visited)
		{
			ret->distance = distance;
			ret->placeNames[x] = strdup(current->connectedPlaces[i]->name);
			x += 1;
			current->connectedPlaces[i]->visited = 1;
		}
	}
	if (!ret->placeNames[0])
	{
		distance += 1;
		x = 0;
		for (int j = 0; current->connectedPlaces[j]; j++)
			return findSellers(current->connectedPlaces[j], ret);
	}
	return (ret);
}

struct s_sellers *closestSellers(struct s_graph *parisPlaces, char *youAreHere)
{
	struct s_sellers	*ret;
	struct s_node		*current;
	ret = malloc(sizeof(struct s_sellers));
	ret->placeNames = malloc(sizeof(char *) * 2048);
	current = getCurrent(parisPlaces, youAreHere);
	ret = findSellers(current, ret);
	return (ret);
}

