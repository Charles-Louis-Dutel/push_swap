/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:21:59 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/19 12:57:23 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile **pile)
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
	ft_printf("sa\n");
}

void	push_a(t_pile **from, t_pile **to)
{
	t_pile	*temp;
	int		first;

	if (!from)
		return ;
	temp = *from;
	first = temp->nbr;
	push_pile(to, first);
	pop_one(from);
	ft_printf("pa\n");
}

void	rotate_a(t_pile **pile)
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
	ft_printf("ra\n");
}

void	rev_rotate_a(t_pile **pile)
{
	t_pile	*last;
	t_pile	*temp;
	int		last_num;

	last = get_last(pile);
	last_num = last->nbr;
	push_pile(pile, last_num);
	temp = *pile;
	while (temp->next != last)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	free(last);
	ft_printf("rra\n");
}
