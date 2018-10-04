/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howmanyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 21:31:00 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/18 21:54:08 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdio.h>

int q = 17;
int d = 256;

int howManyJesus(char *bible, char *jesus)
{
    int M = strlen(jesus);
    int N = strlen(bible);
	int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
	int count = 0;

    for (i = 0; i < M-1; i++)
        h = (h*d)%q;
    for (i = 0; i < M; i++)
    {
        p = (d*p + jesus[i])%q;
        t = (d*t + bible[i])%q;
    }
    for (i = 0; i <= N - M; i++)
    {
        if ( p == t )
        {
            for (j = 0; j < M; j++)
            {
                if (bible[i+j] != jesus[j])
                    break;
            }
            if (j == M)
                count++;
        }
        if ( i < N-M )
        {
            t = (d*(t - bible[i]*h) + bible[i+M])%q;
            if (t < 0)
				t = (t + q);
        }
    }
	return (count);
}
