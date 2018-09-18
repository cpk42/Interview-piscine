/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:44:26 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/17 20:50:26 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int		searchPrice(struct s_art **arts, char *name)
{
	while (*arts)
	{
		if (!strcmp((*arts)->name, name))
			return ((*arts)->price);
		arts++;
	}
	return (-1);
}
