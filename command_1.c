/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:21:59 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/03 19:28:41 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	swap(t_pile pile)
{
	t_pile	temp;
	int		first;
	int		second;

	temp = pile;
	if (!pile)
		return (NULL);
	first = temp->nbr;
	temp = pop_one(temp);
	second = temp->nbr;
	temp = pop_one(temp);
	temp = push_pile(temp, first);
	temp = push_pile(temp, second);
	return (temp);
}

t_pile	push(t_pile from, t_pile to)
{
	t_pile	temp;
	int		first;

	if (!from)
		return (NULL);
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

	temp = pile;
	first = temp->nbr;
	temp = pop_one(temp);
	last = get_last(temp);
	last->next = new_elem(first);

	return (temp);
}

t_pile	rev_rotate(t_pile pile)
{

}
