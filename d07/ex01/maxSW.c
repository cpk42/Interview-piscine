/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:38:13 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/27 19:18:00 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MIN -2147483648

struct s_deque *dequeInit(void)
{
    struct s_deque *ptr = (struct s_deque *)malloc(sizeof(struct s_deque));
    ptr->first = NULL;
    ptr->last = NULL;
    return (ptr);
}

void pushFront(struct s_deque *deque, int value)
{
    if (!deque->first)
    {
        struct s_dequeNode *ptr = (struct s_dequeNode *)malloc(sizeof(struct s_dequeNode));
        ptr->value = value;
        ptr->next = NULL;
        ptr->prev = NULL;
        deque->first = ptr;
        deque->last = ptr;
    }
    else
    {
        struct s_dequeNode *ptr = (struct s_dequeNode *)malloc(sizeof(struct s_dequeNode));
        ptr->value = value;
        ptr->next = deque->first;
        ptr->prev = NULL;
        deque->first->prev = ptr;
        deque->first = ptr;
    }
}

void pushBack(struct s_deque *deque, int value)
{
    if (!deque->last)
    {
        struct s_dequeNode *ptr = (struct s_dequeNode *)malloc(sizeof(struct s_dequeNode));
        ptr->value = value;
        ptr->next = NULL;
        ptr->prev = NULL;
        deque->first = ptr;
        deque->last = ptr;
    }
    else
    {
        struct s_dequeNode *ptr = (struct s_dequeNode *)malloc(sizeof(struct s_dequeNode));
        ptr->value = value;
        ptr->next = NULL;
        ptr->prev = deque->last;
        deque->last->next = ptr;
        deque->last = ptr;
    }
}

int popFront(struct s_deque *deque)
{
    if (deque->first)
    {
        struct s_dequeNode *ptr = deque->first;
        if (!deque->first->next)
        {
            deque->first = NULL;
            deque->last = NULL;
        }
        else
        {
            deque->first = deque->first->next;
        }
        return (ptr->value);
    }
    return (INT_MIN);
}

int popBack(struct s_deque *deque)
{
    if (deque->last)
    {
        struct s_dequeNode *ptr = deque->last;
        if (!deque->last->prev)
        {
            deque->first = NULL;
            deque->last = NULL;
        }
        else
        {
            deque->last = deque->last->prev;
        }
        return (ptr->value);
    }
    return (INT_MIN);
}

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	struct s_deque *q = dequeInit();
    struct s_max *ptr = (struct s_max *)malloc(sizeof(struct s_max));
    ptr->max = (int *)malloc(sizeof(int) * (n - k));
    ptr->length = n-k+1;

    int i;
    int index = 0;
    for (i = 0; i < k && i < n; ++i)
    {
        while (q->first != NULL && arr[i] >= arr[q->last->value])
            popBack(q);
        pushBack(q, i);
    }
    for (; i < n; ++i)
    {
        ptr->max[index++] = arr[q->first->value];
        while (q->first != NULL && q->first->value <= i - k)
            popFront(q);
        while ( q->first != NULL && arr[i] >= arr[q->last->value])
            popBack(q);
        pushBack(q, i); 
    } 
    ptr->max[index++] = arr[q->first->value];
    return (ptr);
}
