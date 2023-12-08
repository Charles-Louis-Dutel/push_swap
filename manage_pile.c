/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:14:03 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/08 16:26:15 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_pile	*new_pile(void)
{
	return (NULL);
}

/*int	is_pile_empty(t_pile pile)
{
	if (pile == NULL)
		return (1);
	return (0);
}*/

void	push_pile(t_pile **pile, int nbr)
{
	t_pile	*elem;
	t_pile	*temp;

	elem = malloc(sizeof(struct pile_elem));
	if (!elem)
		return ;
	elem->nbr = nbr;
	elem->next = NULL;
	if (*pile)
	{
		temp = *pile;
		*pile = elem;
		(*pile)->next = temp;
	}
	else
		*pile = elem;
}

t_pile	*new_elem(int nbr)
{
	t_pile	*elem;

	elem = malloc(sizeof(struct pile_elem));
	if (!elem)
		return (NULL);
	elem->nbr = nbr;
	elem->next = NULL;
	return (elem);
}

void	clear_pile(t_pile **pile)
{
	t_pile	*temp;

	if (!pile)
		return ;
	while (*pile)
	{
		temp = (*pile)->next;
		free(*pile);
		*pile = temp;
	}
	*pile = NULL;
}

void	print_pile(t_pile **pile)
{
	t_pile	*temp;
	if (!pile)
		return ;
	temp = *pile;
	while (temp)
	{
		printf("[%d]\n", temp->nbr);
		temp = temp->next;
	}
}

void	pop_one(t_pile **pile)
{
	t_pile	*temp;

	if (!pile)
		return ;
	temp = (*pile)->next;
	free(*pile);
	*pile = temp;
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
