/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:14:03 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/01 16:56:19 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*new_pile(void)
{
	return (NULL);
}

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

void	pop_one(t_pile **pile)
{
	t_pile	*temp;

	if (!pile)
		return ;
	temp = (*pile)->next;
	free(*pile);
	*pile = temp;
}
