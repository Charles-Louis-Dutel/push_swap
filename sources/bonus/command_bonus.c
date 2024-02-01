/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:14:02 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/01 16:55:51 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_bonus(t_pile **pile)
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

void	push_bonus(t_pile **from, t_pile **to)
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

void	rotate_bonus(t_pile **pile)
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

void	rev_rotate_bonus(t_pile **pile)
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

void	rotate_all(t_pile **pile_a, t_pile **pile_b, const char *ins)
{
	if (ft_strncmp(ins, "rr\n", 4) == 0)
	{
		rotate_bonus(pile_a);
		rotate_bonus(pile_b);
	}
	else if (ft_strncmp(ins, "rrr\n", 5) == 0)
	{
		rev_rotate_bonus(pile_a);
		rev_rotate_bonus(pile_b);
	}
}
