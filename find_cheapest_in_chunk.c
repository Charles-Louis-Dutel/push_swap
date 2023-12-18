/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest_in_chunk.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:44:45 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/18 16:57:52 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calcul_move_a(t_pile **pile_a, int proxy_pos)
{
	int	n_move_a;

	if (proxy_pos < pile_len(pile_a))
		n_move_a = proxy_pos + 1;
	else
		n_move_a = pile_len(pile_a) - proxy_pos + 1;
	return (n_move_a);
}

static int	find_proxy_in_a(t_pile **pile_a, int nbr, int proxy_pos)
{
	t_pile	*temp;
	int		proxy;
	int		index;

	temp = *pile_a;
	if (nbr < find_minimum(pile_a))
		proxy_pos = find_min_pos(pile_a);
	else
	{
		index = 0;
		proxy = temp->nbr;
		while (temp)
		{
			if (nbr > temp->nbr && proxy < temp->nbr)
			{
				proxy = temp->nbr;
				proxy_pos = index;
			}
			index++;
			temp = temp->next;
		}
	}
	return (calcul_move_a(pile_a, proxy_pos));
}

static int	cal_n_move_chunk(t_pile **pile_a, t_pile **pile_b, int index)
{
	t_pile	*temp;
	int		n_move;
	int		proxy_pos;

	if (index < pile_len(pile_b) / 2)
		n_move = index + 1;
	else
		n_move = pile_len(pile_b) - index + 1;
	temp = *pile_b;
	while (index != 0)
	{
		temp = temp->next;
		index--;
	}
	proxy_pos = 0;
	n_move += find_proxy_in_a(pile_a, temp->nbr, proxy_pos);
	return (n_move);
}

int	find_cheapest_chunk(t_pile **pile_a, t_pile **pile_b)
{
	int		cheap_move;
	int		cheap_index;
	int		index;
	int		n_move;
	t_pile	*temp;

	temp = *pile_b;
	cheap_index = 0;
	cheap_move = 2147483647;
	index = 0;
	while (temp)
	{
		n_move = cal_n_move_chunk(pile_a, pile_b, index);
		if (n_move < cheap_move)
		{
			cheap_move = n_move;
			cheap_index = index;
		}
		index++;
		temp = temp->next;
	}
	return (cheap_index);
}
