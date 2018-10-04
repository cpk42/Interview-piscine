/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:46:41 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/18 12:56:46 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	printReverse(struct s_node *lst)
{
	if (lst == NULL)
		return ;
	printReverse(lst->next);
	if (!lst->next)
		printf("%s", lst->word);
	else
		printf(" %s", lst->word);
}
