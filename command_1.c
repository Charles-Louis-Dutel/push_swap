/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:21:59 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/04 15:29:15 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	swap(t_pile pile)
{
	t_pile	temp;
	int		first;
	int		second;

	if (!pile)
		return (NULL);
	temp = pile;
	if (pile->next)
	{
		first = temp->nbr;
		temp = pop_one(temp);
		second = temp->nbr;
		temp = pop_one(temp);
		temp = push_pile(temp, first);
		temp = push_pile(temp, second);
	}
	return (temp);
}

t_pile	push(t_pile from, t_pile to)
{
	t_pile	temp;
	int		first;

	if (!from)
		return (to);
	temp = from;
	first = temp->nbr;
	to = push_pile(to, first);
	return (to);
}

t_pile	rotate(t_pile pile)
{
	t_pile	temp;
	t_pile	last;
	int		first;

	if (!pile)
		return (NULL);
	temp = pile;
	if (pile->next)
	{
		first = temp->nbr;
		temp = pop_one(temp);
		last = get_last(temp);
		last->next = new_elem(first);
	}
	return (temp);
}

t_pile	rev_rotate(t_pile pile)
{
	t_pile	temp;
	t_pile	last;
	t_pile	new;
	t_pile	head;

	if (pile && pile->next)
	{
		last = get_last(pile);
		new = push_pile(pile, last->nbr);
		temp = new;
		head = new;
		while (temp)
		{
			temp = temp->next;
			if (temp == last)
			{
				free(temp);
				new->next = NULL;
				break ;
			}
			new = new->next;
		}
		return (head);
	}
	return (pile);
}
