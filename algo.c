/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:24:37 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/18 15:58:21 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_b(t_pile **pile_b, int n_to_push, int proxy_pos)
{
	t_pile	*temp;
	int		proxy;
	int		index;

	temp = *pile_b;
	if (n_to_push < find_minimum(pile_b))
		proxy_pos = find_min_pos(pile_b) + 1;
	else if (n_to_push > find_maximum(pile_b))
		proxy_pos = find_max_pos(pile_b);
	else
	{
		index = 0;
		proxy = find_maximum(pile_b);
		while (temp)
		{
			if (n_to_push < temp->nbr && proxy >= temp->nbr)
			{
				proxy = temp->nbr;
				proxy_pos = index + 1;
			}
			index++;
			temp = temp->next;
		}
	}
	return (proxy_pos);
}

static void	sort_and_push(t_pile **pile_a, t_pile **pile_b, int cheap_index)
{
	t_pile	*temp;
	int		n_to_push;
	int		move_a;
	int		move_b;
	int		proxy_pos;

	temp = *pile_a;
	move_a = cheap_index;
	while (cheap_index != 0)
	{
		temp = temp->next;
		cheap_index--;
	}
	n_to_push = temp->nbr;
	proxy_pos = 0;
	move_b = find_index_b(pile_b, n_to_push, proxy_pos);
	sort_help(pile_a, pile_b, move_a, move_b);
	push_b(pile_a, pile_b);
}

static void	sort_b(t_pile **pile_b)
{
	int		pos_max;

	pos_max = find_max_pos(pile_b);
	if (pos_max < pile_len(pile_b) / 2)
	{
		while (pos_max != 0)
		{
			rotate_b(pile_b);
			pos_max--;
		}
	}
	else
	{
		while (pos_max != pile_len(pile_b))
		{
			rev_rotate_b(pile_b);
			pos_max++;
		}
	}
}

void	sort_pile(t_pile **pile_a, t_pile **pile_b)
{
	int	len;
	int	cheap_index;

	len = 0;
	while (len < 2 && pile_len(pile_a) > 3)
	{
		while ((*pile_a)->nbr >= find_3_max(pile_a))
			rotate_a(pile_a);
		push_b(pile_a, pile_b);
		len++;
	}
	while (pile_len(pile_a) > 3)
	{
		cheap_index = find_cheapest(pile_a, pile_b);
		sort_and_push(pile_a, pile_b, cheap_index);
	}
	if (pile_len(pile_b) > 1)
		sort_b(pile_b);
	pile_of_3(pile_a);
	while (pile_len(pile_b) != 0)
	{
		push_a(pile_b, pile_a);
	}
}
