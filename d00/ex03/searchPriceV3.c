/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:54:09 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/17 22:42:19 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

//typedef unsigned long size_t;

size_t			hash(char *input)
{
	size_t	hash = 5381;
    int c;

    while ((c = *input++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return (hash);
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict *new;

	new = (struct s_dict *)malloc(sizeof(struct s_dict));
	new->capacity = capacity;
	new->items = (struct s_item **)malloc(sizeof(struct s_item *) * capacity);
	for (int i = 0; i < capacity; i++)
		(new->items)[i] = NULL;
	return (new);
}

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	size_t h;

	h = hash(key);
	if (!((dict->items)[h % dict->capacity]))
	{
		((dict->items)[h % dict->capacity]) = malloc(sizeof(struct s_item));
		((dict->items)[h % dict->capacity])->value = value;
		((dict->items)[h % dict->capacity])->key = key;
		((dict->items)[h % dict->capacity])->next = NULL;
	}
	else
	{
		struct s_item *new = (((dict->items)[h % dict->capacity]));
		while (new->next)
			new = new->next;
		new->next = malloc(sizeof(struct s_item));
		new->next->key = key;
		new->next->value = value;
		new->next->next = NULL;
	}
	return (1);
}

struct s_art	*dictSearch(struct s_dict *dict, char *key)
{
	struct s_item *tmp = ((dict->items)[hash(key) % dict->capacity]);
	while (tmp && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	return (tmp->value);
}

int				searchPrice(struct s_dict *dict, char *name)
{
	struct s_item *tmp = ((dict->items)[hash(name) % dict->capacity]);
	while (tmp && strcmp(tmp->key, name) != 0)
		tmp = tmp->next;
	return (tmp->value->price);
}
