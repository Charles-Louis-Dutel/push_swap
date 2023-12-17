/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:08:55 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/17 21:47:48 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calcul_move_b(t_pile **pile_b, int proxy_pos)
{
	int	n_move_b;

	if (proxy_pos < pile_len(pile_b))
		n_move_b = proxy_pos + 1;
	else
		n_move_b = pile_len(pile_b) - proxy_pos + 1;
	return (n_move_b);
}

static int	find_proxy_in_b(t_pile **pile_b, int nbr, int proxy_pos)
{
	t_pile	*temp;
	int		proxy;
	int		index;

	temp = *pile_b;
	if (nbr < find_minimum(pile_b))
		proxy_pos = find_min_pos(pile_b);
	else if (nbr > find_maximum(pile_b))
		proxy_pos = find_max_pos(pile_b) - 1;
	else
	{
		index = -1;
		proxy = temp->nbr;
		while (temp)
		{
			if (nbr < temp->nbr && proxy > temp->nbr)
			{
				proxy = temp->nbr;
				proxy_pos = index;
			}
			index++;
			temp = temp->next;
		}
	}
	return (calcul_move_b(pile_b, proxy_pos));
}

static int	calculate_n_move(t_pile **pile_a, t_pile **pile_b, int index)
{
	t_pile	*temp;
	int		n_move;
	int		proxy_pos;

	if (index < pile_len(pile_a) / 2)
		n_move = index + 1;
	else
		n_move = pile_len(pile_a) - index + 1;
	temp = *pile_a;
	while (index != 0)
	{
		temp = temp->next;
		index--;
	}
	proxy_pos = 0;
	n_move += find_proxy_in_b(pile_b, temp->nbr, proxy_pos);
	return (n_move);
}

int	find_3_max(t_pile **pile_a)
{
	t_pile	*temp;
	int		max;
	int		min;
	int		i;

	max = find_maximum(pile_a);
	i = 2;
	while (i > 0)
	{
		temp = *pile_a;
		min = find_minimum(pile_a);
		while (temp)
		{
			if (min < temp->nbr && temp->nbr < max)
				min = temp->nbr;
			temp = temp->next;
		}
		max = min;
		i--;
	}
	return (max);
}

int	find_cheapest(t_pile **pile_a, t_pile **pile_b)
{
	int		cheap_move;
	int		cheap_index;
	int		index;
	int		n_move;
	t_pile	*temp;

	temp = *pile_a;
	cheap_index = 0;
	cheap_move = 2147483647;
	index = 0;
	while (temp)
	{
		n_move = calculate_n_move(pile_a, pile_b, index);
		if (n_move < cheap_move && temp->nbr < find_3_max(pile_a))
		{
			cheap_move = n_move;
			cheap_index = index;
		}
		index++;
		temp = temp->next;
	}
	return (cheap_index);
}
