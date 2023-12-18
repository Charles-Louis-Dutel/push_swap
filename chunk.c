/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:30:24 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/18 17:44:26 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index_a(t_pile **pile_a, int n_to_push, int proxy_pos)
{
	t_pile	*temp;
	int		proxy;
	int		index;

	temp = *pile_a;
	if (n_to_push < find_minimum(pile_a))
		proxy_pos = find_min_pos(pile_a);
	else
	{
		index = 0;
		proxy = find_maximum(pile_a);
		while (temp)
		{
			if (n_to_push < temp->nbr && proxy > temp->nbr)
			{
				proxy = temp->nbr;
				proxy_pos = index;
			}
			index++;
			temp = temp->next;
		}
	}
	return (proxy_pos);
}

// static void	sort_help_chunk(t_pile **pile_a, t_pile **pile_b, int m_a, int m_b)
// {
// 	if (m_a < pile_len(pile_a) / 2 && m_b < pile_len(pile_b) / 2)
// 	{
// 		while (m_a > 0 && m_b > 0)
// 		{
// 			rotate(pile_a, pile_b);
// 			m_a--;
// 			m_b--;
// 		}
// 	}
// 	else if (m_a > pile_len(pile_a) / 2 && m_b > pile_len(pile_b) / 2)
// 	{
// 		while (m_a < pile_len(pile_a) && m_b < pile_len(pile_b))
// 		{
// 			rev_rotate(pile_a, pile_b);
// 			m_a++;
// 			m_b++;
// 		}
// 	}
// 	if (m_a > 0 && m_a <= pile_len(pile_a))
// 		sort_help_a(pile_a, m_a);
// 	if (m_b > 0 && m_b <= pile_len(pile_b))
// 		sort_help_b(pile_b, m_b);
// }

static void	sort_and_push_chunk(t_pile **pile_a, t_pile **pile_b, int cheap_index)
{
	t_pile	*temp;
	int		n_to_push;
	int		move_b;
	int		move_a;
	int		proxy_pos;

	temp = *pile_b;
	move_b = cheap_index;
	while (cheap_index != 0)
	{
		temp = temp->next;
		cheap_index--;
	}
	n_to_push = temp->nbr;
	proxy_pos = 0;
	move_a = find_index_a(pile_a, n_to_push, proxy_pos);
	sort_help(pile_a, pile_b, move_a, move_b);
	push_a(pile_b, pile_a);
}

static int	find_chunk_max(t_pile **pile_a, int chunk_size)
{
	t_pile	*temp;
	int		max;
	int		min;
	int		i;

	max = find_maximum(pile_a);
	i = pile_len(pile_a) - chunk_size;
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

void	sort_with_chunk(t_pile **pile_a, t_pile **pile_b)
{
	int	len;
	int	chunk_size;
	int	chunk_max;
	int	n;

	while (pile_len(pile_a) > 3)
	{
		chunk_size = pile_len(pile_a) / 4;
		chunk_max = find_chunk_max(pile_a, chunk_size);
		n = find_chunk_max(pile_a, chunk_size / 2);
		len = 0;
		while(len < chunk_size)
		{
			while ((*pile_a)->nbr > chunk_max)
				rotate_a(pile_a);
			push_b(pile_a, pile_b);
			if ((*pile_b)->nbr < n)
				rotate_b(pile_b);
			len++;
		}
	}
	pile_of_3(pile_a);
	while (pile_len(pile_b) > 0)
	{
		n = find_cheapest_chunk(pile_a, pile_b);
		sort_and_push_chunk(pile_a, pile_b, n);
	}
	sort_help_a(pile_a, find_min_pos(pile_a));
}
