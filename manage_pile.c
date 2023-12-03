/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:14:03 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/03 19:28:22 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_pile	new_pile(void)
{
	return (NULL);
}

int	is_pile_empty(t_pile pile)
{
	if (pile == NULL)
		return (1);
	return (0);
}

t_pile	push_pile(t_pile pile, int nbr)
{
	t_pile	elem;

	elem = malloc(sizeof(struct pile_elem));
	if (!elem)
		return (NULL);
	elem->nbr = nbr;
	elem->next = pile;
	return (elem);
}

t_pile	new_elem(int nbr)
{
	t_pile	elem;

	elem = malloc(sizeof(struct pile_elem));
	if (!elem)
		return (NULL);
	elem->nbr = nbr;
	elem->next = NULL;
	return (elem);
}

t_pile	clear_pile(t_pile pile)
{
	t_pile	temp;

	if (is_pile_empty(pile))
		return (new_pile());
	temp = pile->next;
	free(pile);
	return (clear_pile(temp));
}

void	print_pile(t_pile pile)
{
	if (is_pile_empty(pile))
		return ;
	while (!is_pile_empty(pile))
	{
		printf("[%d]\n", pile->nbr);
		pile = pile->next;
	}
}

t_pile	pop_one(t_pile pile)
{
	t_pile	temp;

	if (is_pile_empty(pile))
		return (new_pile());
	temp = pile->next;
	free(pile);
	return (temp);
}

/*
int main()
{
	t_pile	test;

	test = new_pile();
	if (is_pile_empty(test))
		printf("vide\n");

	test = push_pile(test, 25);
	test = push_pile(test, 58418);

	if (is_pile_empty(test))
		printf("vide\n");

	print_stack(test);

	test = clear_pile(test);
	if (is_pile_empty(test))
		printf("vide\n");

	return (0);
}*/
