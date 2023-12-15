/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pile_of_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:34:04 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/15 01:45:20 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_a(t_pile **pile_b)
{
	int		pos_min;

	pos_min = find_min_pos(pile_b);
	if (pos_min < pile_len(pile_b) / 2)
	{
		while (pos_min != 0)
		{
			rotate_b(pile_b);
			pos_min--;
		}
	}
	else
	{
		while (pos_min != pile_len(pile_b))
		{
			rev_rotate_b(pile_b);
			pos_min++;
		}
	}
}

static int	find_pos(t_pile **pile_a, t_pile **pile_b, int top_b_pos, int pos)
{
	int		proxy;
	t_pile	*temp;

	temp = *pile_a;
	proxy = find_minimum(pile_a);
	pos = 0;
	if ((*pile_b)->nbr > find_maximum(pile_a))
		top_b_pos = find_max_pos(pile_a) + 1;
	if ((*pile_b)->nbr < find_minimum(pile_a))
		top_b_pos = find_min_pos(pile_b);
	else
	{
		while (temp)
		{
			if ((*pile_b)->nbr < temp->nbr && proxy < temp->nbr
				&& proxy < (*pile_b)->nbr)
			{
				top_b_pos = pos;
				proxy = temp->nbr;
			}
			pos++;
			temp = temp->next;
		}
	}
	return (top_b_pos);
}

void	pile_of_5(t_pile **pile_a, t_pile **pile_b)
{
	int		top_b_pos;
	int		len;
	int		pos;

	push_b(pile_a, pile_b);
	push_b(pile_a, pile_b);
	pile_of_3(pile_a);
	sort_a(pile_b);
	len = pile_len(pile_b);
	pos = 0;
	while (len != 0)
	{
		top_b_pos = find_pos(pile_a, pile_b, top_b_pos, pos);
		while (top_b_pos != 0)
		{
			rotate_a(pile_a);
			top_b_pos--;
		}
		push_a(pile_b, pile_a);
		len--;
	}
	sort_a(pile_a);
}
