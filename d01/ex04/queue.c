/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:11:55 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/18 15:41:09 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_queue *queueInit(void)
{
	struct s_queue *queue;

	queue = (struct s_queue *)malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *tmp;

	if (!queue->first)
	{
		tmp = malloc(sizeof(struct s_node));
		tmp->message = message;
		tmp->next = NULL;
		queue->first = tmp;
		queue->last = tmp;
	}
	else
	{
		tmp = malloc(sizeof(struct s_node));
		tmp->message = message;
		queue->last->next = tmp;
		queue->last = queue->last->next;
	}
}

char *dequeue(struct s_queue *queue)
{
	struct s_node *tmp;

	if (queue->first)
	{
		tmp = queue->first;
		if (!strcmp(queue->first->message, queue->last->message))
		{
			queue->last = NULL;
			queue->first = NULL;
			return (tmp->message);
		}
		else
		{
			queue->first = queue->first->next;
			tmp->next = NULL;
			return (tmp->message);
		}
	}
	else
		return (NULL);
}

char	*peek(struct s_queue *queue)
{
	if (queue->first)
		return (queue->first->message);
	return (NULL);
}

int		isEmpty(struct s_queue *queue)
{
	return ((!queue->first && !queue->last) ? 1 : 0);
}
