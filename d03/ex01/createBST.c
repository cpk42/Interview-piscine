/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 17:24:12 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/21 22:08:58 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

struct s_node *initNode(int val)
{
	struct s_node *node;

	node = malloc(sizeof(struct s_node));
	node->left = NULL;
	node->right = NULL;
	node->value = val;
	return (node);
}

struct s_node *findMid(int *arr, int start, int len)
{
	struct s_node *root;
	int mid;

	root = NULL;
	if (start <= len)
	{
		mid = (start + len) / 2;
		root = initNode(arr[mid]);
		root->left = findMid(arr, start, mid - 1);
		root->right = findMid(arr, mid + 1, len);
	}
	return (root);
	
}

struct s_node *createBST(int *arr, int n)
{
	return (findMid(arr, 0, n - 1));
}
