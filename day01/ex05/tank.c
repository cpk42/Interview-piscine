/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:45:03 by ckrommen          #+#    #+#             */
/*   Updated: 2018/09/19 20:31:39 by ckrommen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_tank *initTank(void)
{
	struct s_tank *tank;

	tank = malloc(sizeof(struct s_tank));
	tank->stacks = (struct s_stack **)malloc(sizeof(struct s_stack *) * 512);
	tank->n = 0;
	return (tank);
}

void	printStacks(struct s_tank *tank)
{
	int i = 0;

	while (i < tank->n)
	{
		if (i == 0)
			printf("%6s", "normal\n");
		else
			printf("%s%d\n", "nitro", i);

		printf("______\n");
		printf("|%4d|\n", ((tank->stacks))[i]->sum);
		printf("|    |\n\n");
		i++;
	}
}

void tankPush(struct s_tank *tank, int energy)
{
	struct s_stack *tmp;

	if (!tank->stacks[0])
	{
		tmp = malloc(sizeof(struct s_stack));
		tmp->sum = energy;
		tmp->elem = malloc(sizeof(struct s_elem));
		tmp->elem->energy = energy;
		tmp->elem->next = NULL;
		tank->stacks[0] = tmp;
		printf("push(%d): \n\n", energy);
		tank->n += 1;
		printStacks(tank);
	}
	else
	{
		struct s_elem *input;
		
		input = malloc(sizeof(struct s_elem));
		input->energy = energy;
		input->next = NULL;
		if ((tank->stacks[tank->n - 1])->sum + energy <= 1000)
		{
			(tank->stacks[tank->n - 1])->sum += energy;			
			input->next = (tank->stacks[tank->n - 1])->elem;
			(tank->stacks[tank->n - 1])->elem = input;
			printf("push(%d): \n\n", energy);
			printStacks(tank);
		}
		else
		{
			tank->n += 1;
			tmp = malloc(sizeof(struct s_stack));
			tmp->sum = energy;
			tmp->elem = malloc(sizeof(struct s_elem));
			tmp->elem->energy = energy;
			tmp->elem->next = NULL;
			tank->stacks[tank->n - 1] = tmp;
			printf("push(%d): \n\n", energy);
			printStacks(tank);
		}
	}
}

int tankPop(struct s_tank *tank)
{
	struct s_elem *tmp;

	if (tank->n > 0)
	{
		tmp = (tank->stacks[tank->n - 1])->elem;
		(tank->stacks[tank->n - 1])->elem = (tank->stacks[tank->n - 1])->elem->next;
		tmp->next = NULL;
		(tank->stacks[tank->n - 1])->sum -= tmp->energy;
		if ((tank->stacks[tank->n - 1])->sum == 0)
			tank->n -= 1;
		if (tank->n == 0)
			tank->stacks[0] = NULL;
		printf("pop(%d):\n\n", tmp->energy);
		printStacks(tank);
	}
	return (1);
}
