/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:19:09 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/18 12:42:41 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_node *init_node(char data)
{
	struct s_node *ptr;

	ptr = (struct s_node *)malloc(sizeof(struct s_node));
	ptr->c = data;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

struct s_node *create_list()
{
	struct s_node	*head;
	struct s_node	*ptr;
	struct s_node	*last;
	char			*str;
	int				i;

	i = 1;
	str = CS;
	head = init_node(str[0]);
	ptr = head;
	while (str[i])
	{
		ptr->next = init_node(str[i]);
		last = ptr;
		ptr = ptr->next;
		ptr->prev = last;
		i++;
	}
	ptr->next = head;
	head->prev = ptr;
	return (head);
}

char	*precious(int *text, int size)
{
	struct s_node *head;
	char *ret;
	int i;

	i = 0;
	head = create_list();
	ret = (char *)malloc(sizeof(char) * size + 1);
	bzero(ret, size);
	while (i < size)
	{
		if (text[i] > 0)
		{
			while (text[i]-- > 0)
				head = head->next;
		}
		else
		{
			while (text[i]++ < 0)
				head = head->prev;
		}
		ret[i] = head->c;
		i++;
	}
	return (ret);
}
