/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 22:20:12 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/22 00:02:25 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_node *ret;
	struct s_node *tmp;
	int check = 0;

	tmp = NULL;
	if (!strcmp(root->name, firstSpecies) || !strcmp(root->name, secondSpecies))
		return (root);
	for (int i = 0; root->children[i]; i++)
	{
		ret = findParent(root->children[i], firstSpecies, secondSpecies);
		if (ret == NULL)
			continue ;
		else if (ret && ++check)
			tmp = ret;
		else
			break ;
	}
	if (check == 2)
		return (root);
	return (tmp);
}
