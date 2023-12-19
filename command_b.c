/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:25:08 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/19 12:56:10 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_pile **pile)
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
	ft_printf("sb\n");
}

void	push_b(t_pile **from, t_pile **to)
{
	t_pile	*temp;
	int		first;

	if (!from)
		return ;
	temp = *from;
	first = temp->nbr;
	push_pile(to, first);
	pop_one(from);
	ft_printf("pb\n");
}

void	rotate_b(t_pile **pile)
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
	ft_printf("rb\n");
}

void	rev_rotate_b(t_pile **pile)
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
	ft_printf("rrb\n");
}
