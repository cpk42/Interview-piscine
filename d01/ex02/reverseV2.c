/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:28:45 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/18 14:14:04 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_stack *stackInit(void)
{
	struct s_stack *new;

	new = malloc(sizeof(struct s_stack));
	new->item = NULL;
	return (new);
}

void *pop(struct s_stack *stack)
{
	struct s_item *ptr;
	struct s_item *ret;

	if (stack->item)
	{
		ret = stack->item;
		ptr = ret;
		ptr = ptr->next;
		ret->next = NULL;
		stack->item = ptr;
		return ((void *)(ret));
	}
	return (NULL);
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *ptr;

	if (stack->item)
	{
		ptr = malloc(sizeof(struct s_item));
		ptr->word = word;
		ptr->next = stack->item;
		stack->item = ptr;
	}
	else
	{
		ptr = malloc(sizeof(struct s_item));
		ptr->word = word;
		ptr->next = NULL;
		stack->item = ptr;
	}
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack *stack;
	struct s_item *item;

	stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (stack->item)
	{
		if ((item = pop(stack)) && stack->item)
			printf("%s ", item->word);
		else
			printf("%s", item->word);
	}
}
