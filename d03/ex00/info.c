/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 13:06:56 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/21 17:09:47 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct s_info initInfo()
{
	struct s_info info;

	info.min = 0;
	info.max = 0;
	info.elements = 0;
	info.height = 0;
	info.isBST = 0;
	info.isBalanced = 0;
	return (info);
}

int findMin(struct s_node* root) 
{ 
    if (root == NULL) 
		return 2147483647; 
    int res = root->value; 
    int lres = findMin(root->left); 
    int rres = findMin(root->right); 
    if (lres < res) 
		res = lres; 
    if (rres < res) 
		res = rres; 
    return res; 
} 

int findMax(struct s_node* root) 
{ 
    if (root == NULL) 
		return -2147483648; 
    int res = root->value; 
    int lres = findMax(root->left); 
    int rres = findMax(root->right); 
    if (lres > res) 
		res = lres; 
    if (rres > res) 
		res = rres; 
    return res; 
} 

int findCount(struct s_node *root)
{
    int c = 1;
    if (root == NULL)
        return 0;
    else
    {
        c += findCount(root->left);
        c += findCount(root->right);
        return c;
    }
}

int findDepth(struct s_node *root)
{
	if (root == NULL)
		return (0);
	else
	{
		int lDepth = findDepth(root->left);
		int rDepth = findDepth(root->right);
		return (lDepth > rDepth ? lDepth + 1 : rDepth + 1);
	}
}

int	isBalanced(struct s_node *root)
{
	if (root == NULL)
		return (1);
	else if (!root->left && !root->right)
		return (1);
	else
	{
		int lDepth = 0;
		int rDepth = 0;

		if (root->left)
			lDepth = findDepth(root->left);
		if (root->right)
			rDepth = findDepth(root->right);
		return ((lDepth - rDepth == 1) || (rDepth - lDepth == 1) || (rDepth == lDepth)  ? 1 : 0);
	}
}

int	isBST(struct s_node *root, int left, int right)
{
	if (root == NULL)
		return 1;
	else
	{
		if (root->value > right || root->value <= left)
			return (0);
		return (isBST(root->left, left, root->value) && isBST(root->right, root->value, right));
	}
}

struct s_info getInfo(struct s_node *root)
{
	struct s_info info;

	info = initInfo();
	info.min = findMin(root);
	info.max = findMax(root);
	info.elements = findCount(root);
	info.height = findDepth(root);
	info.isBalanced = isBalanced(root);
	info.isBST = isBST(root, -2147483648, 2147483647);
	return (info);
}
