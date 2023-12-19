/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rr_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:26:57 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/19 13:03:40 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_help(t_pile **pile)
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

void	rotate(t_pile **pile_a, t_pile **pile_b)
{
	rotate_help(pile_a);
	rotate_help(pile_b);
	ft_printf("rr\n");
}

static void	rev_rotate_help(t_pile **pile)
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
}

void	rev_rotate(t_pile **pile_a, t_pile **pile_b)
{
	rev_rotate_help(pile_a);
	rev_rotate_help(pile_b);
	ft_printf("rrr\n");
}
