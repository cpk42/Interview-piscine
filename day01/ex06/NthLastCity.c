/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:48:37 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/19 21:02:00 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int len = 0;
char *ret = NULL;

void findCity(struct s_city *city, int n)
{
    if (!city)
        return ;
    NthLastCity(city->next, n);
    if (len++ == n)
        ret = city->name;
}

char *NthLastCity(struct s_city *city, int n)
{
    findCity(city, n);
    return (ret);
}

/*
char *NthLastCity(struct s_city *city, int n)
{
	struct s_city *x;

	x = city;
	while (n-- && city->next)
		city = city->next;
	while (city->next)
	{
		city = city->next;
		x = x->next;
	}
	return (x->name);
}
*/
