/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:24:37 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/13 14:32:43 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	is_pile_b_sorted(t_pile **pile_b)
// {
// 	t_pile	*temp;
// 	int		max;
// 	int		len;

// 	temp = *pile_b;
// 	max = temp->nbr;
// 	temp = temp->next;
// 	while (temp->next)
// 	{
// 		if (max < temp->nbr)
// 			return (1);
// 		max = temp->nbr;
// 		temp = temp->next;
// 	}
// 	return (0);
// }

int	find_minimum(t_pile **pile_b)
{
	t_pile	*temp;
	int		min;

	temp = *pile_b;
	min = temp->nbr;
	while (temp)
	{
		if (min > temp->nbr)
			min = temp->nbr;
		temp = temp->next;
	}
	return (min);
}

void	sort_and_push(t_pile **pile_a, t_pile **pile_b, int nbr_a)
{
	t_pile	*temp;
	int		pos_inf;
	int		pos;
	int		min;

	pos_inf = 0;
	pos = 0;
	temp = *pile_b;
	min = find_minimum(pile_b);
	if (min > nbr_a)
		pos_inf = find_position(pile_b, min);
	else
		pos_inf = find_position_2(pile_b, min, nbr_a);
	sort_help(pile_b, pos_inf);
	push_b(pile_a, pile_b);
}

void	sort_b(t_pile **pile_b)
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
	int	nbr;

	push_b(pile_a, pile_b);
	len = pile_len(pile_a);
	while (len)
	{
		nbr = (*pile_a)->nbr;
		sort_and_push(pile_a, pile_b, nbr);
		if (len == 1)
		{
			sort_b(pile_b);
			break ;
		}
		len--;
	}
	while (pile_len(pile_b) != 0)
	{
		push_a(pile_b, pile_a);
	}
}
