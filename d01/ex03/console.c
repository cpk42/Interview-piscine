/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:00:43 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/18 16:03:15 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct s_stack *stackInit(void)
{
	struct s_stack *new;

	new = malloc(sizeof(struct s_stack));
	new->item = NULL;
	return (new);
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *ptr;

	if (stack->item)
	{
		ptr = malloc(sizeof(struct s_item));
		ptr->idx = idx;
		ptr->next = stack->item;
		stack->item = ptr;
	}
	else
	{
		ptr = malloc(sizeof(struct s_item));
		ptr->idx = idx;
		ptr->next = NULL;
		stack->item = ptr;
	}
}

int		pop(struct s_stack *stack)
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
		return (ret->idx);
	}
	return (0);
}

char	*console(void)
{
	struct s_stack	*stack;
	char			*message;
	char			*tmpmsg;
	size_t				bs;
	int					len;

	bs = 0;
	len = 0;
	stack = stackInit();
	message = (char *)malloc(sizeof(char) * 255);
	bzero(message, 255);
	while (printf("?: ") && getline(&tmpmsg, &bs, stdin))
	{
		if (!strcmp(tmpmsg, "SEND\n"))
		{
			break ;
		}
		else if (!strcmp(tmpmsg, "UNDO\n"))
		{
			len = pop(stack);
			bzero(message+len - 1, strlen(message+len) + 1);
			printf("%s\n", message);
		}
		else if (tmpmsg)
		{
			if ((strlen(message) + strlen(tmpmsg) + 1) < 255)
			{
				push(stack, strlen(message) + 1);
				if (message[0])
					strcat(message, " ");
				strcat(message, tmpmsg);
				message[strlen(message) - 1] = '\0';
			}
			if (stack->item)
				printf("%s \n", message);
		}
	}
	return (message);
}
