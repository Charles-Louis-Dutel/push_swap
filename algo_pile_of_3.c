/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pile_of_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:51:58 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/12 21:16:58 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_pos(t_pile **pile)
{
	int		min_pos;
	int		pos;
	int		min;
	t_pile	*temp;

	temp = *pile;
	min = temp->nbr;
	min_pos = 0;
	temp = temp->next;
	pos = 1;
	while (temp)
	{
		if (min > temp->nbr)
		{
			min = temp->nbr;
			min_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	return (min_pos);
}

static int	find_max_pos(t_pile **pile)
{
	int		max_pos;
	int		pos;
	int		max;
	t_pile	*temp;

	temp = *pile;
	max = temp->nbr;
	max_pos = 0;
	temp = temp->next;
	pos = 1;
	while (temp)
	{
		if (max < temp->nbr)
		{
			max = temp->nbr;
			max_pos = pos;
		}
		pos++;
		temp = temp->next;
	}
	return (max_pos);
}

void	pile_of_3(t_pile **pile_a)
{
	int	min_pos;
	int	max_pos;

	min_pos = find_min_pos(pile_a);
	max_pos = find_max_pos(pile_a);
	if (pile_len(pile_a) < 3 && min_pos == 1)
		swap_a(pile_a);
	else if (pile_len(pile_a) == 3 && min_pos == 1 && max_pos == 2)
		swap_a(pile_a);
	else if (pile_len(pile_a) == 3 && min_pos == 1 && max_pos == 0)
		rotate_a(pile_a);
	else if (pile_len(pile_a) == 3 && min_pos == 2 && max_pos == 1)
		rev_rotate_a(pile_a);
	else if (pile_len(pile_a) == 3 && min_pos == 2 && max_pos == 0)
	{
		swap_a(pile_a);
		rev_rotate_a(pile_a);
	}
	else if (pile_len(pile_a) == 3 && min_pos == 0 && max_pos == 1)
	{
		swap_a(pile_a);
		rotate_a(pile_a);
	}
}

void	rev_pile_of_3(t_pile **pile_b)
{
	int	min_pos;
	int	max_pos;

	min_pos = find_min_pos(pile_b);
	max_pos = find_max_pos(pile_b);
	if (pile_len(pile_b) < 3 && min_pos == 0)
		swap_b(pile_b);
	else if (pile_len(pile_b) == 3 && min_pos == 1 && max_pos == 2)
		rev_rotate_b(pile_b);
	else if (pile_len(pile_b) == 3 && min_pos == 0 && max_pos == 1)
		rotate_b(pile_b);
	else if (pile_len(pile_b) == 3 && min_pos == 2 && max_pos == 1)
		swap_b(pile_b);
	else if (pile_len(pile_b) == 3 && min_pos == 0 && max_pos == 2)
	{
		swap_b(pile_b);
		rev_rotate_b(pile_b);
	}
	else if (pile_len(pile_b) == 3 && min_pos == 1 && max_pos == 0)
	{
		swap_b(pile_b);
		rotate_b(pile_b);
	}
}
