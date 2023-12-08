/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:21:59 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/08 16:34:28 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **pile)
{
	int		first;
	int		second;

	if (!pile)
		return ;
	if ((*pile)->next)
	{
		first = (*pile)->nbr;
		pop_one(pile);
		second = (*pile)->nbr;
		pop_one(pile);
		push_pile(pile, first);
		push_pile(pile, second);
	}
}

void	push(t_pile **from, t_pile **to)
{
	t_pile	*temp;
	int		first;

	if (!from)
		return ;
	temp = *from;
	first = temp->nbr;
	push_pile(to, first);
	pop_one(from);
}

void	rotate(t_pile **pile)
{
	t_pile	*last;
	int		first;

	if (!pile)
		return ;
	if ((*pile)->next)
	{
		first = (*pile)->nbr;
		pop_one(pile);
		last = get_last(pile);
		last->next = new_elem(first);
	}
}

void	rev_rotate(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*last;
	t_pile	*new;
	t_pile	*head;

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
