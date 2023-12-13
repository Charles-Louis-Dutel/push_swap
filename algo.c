/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:24:37 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/13 12:29:05 by cdutel           ###   ########.fr       */
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
	{
		while (temp)
		{
			if (temp->nbr == min)
				pos_inf = pos + 1;
			pos++;
			temp = temp->next;
		}
	}
	else
	{
		while (temp)
		{
			if (temp->nbr < nbr_a && temp->nbr >= min)
			{
				min = temp->nbr;
				pos_inf = pos;
			}
			pos++;
			temp = temp->next;
		}
	}
	while (pos_inf != 0)
	{
		rotate_b(pile_b);
		pos_inf--;
	}
	push_b(pile_a, pile_b);
}


void	sort_b(t_pile **pile_b)
{
	t_pile	*temp;
	int		max;
	int		pos_max;
	int		pos;

	temp = *pile_b;
	max = temp->nbr;
	pos = 0;
	pos_max = 0;
	while (temp)
	{
		if (temp->nbr > max)
		{
			max = temp->nbr;
			pos_max = pos;
		}
		pos++;
		temp = temp->next;
	}
	while (pos_max != 0)
	{
		rotate_b(pile_b);
		pos_max--;
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
