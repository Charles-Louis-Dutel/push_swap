/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:52:41 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/15 00:27:31 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_pile **pile_b, int min)
{
	t_pile	*temp;
	int		pos;
	int		pos_inf;

	temp = *pile_b;
	pos = 0;
	pos_inf = 0;
	while (temp)
	{
		if (temp->nbr == min)
			pos_inf = pos + 1;
		pos++;
		temp = temp->next;
	}
	return (pos_inf);
}

int	find_position_2(t_pile **pile_b, int min, int nbr_a)
{
	t_pile	*temp;
	int		pos;
	int		pos_inf;

	temp = *pile_b;
	pos = 0;
	pos_inf = 0;
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
	return (pos_inf);
}

void	sort_help(t_pile **pile_b, int pos_inf)
{
	if (pos_inf < pile_len(pile_b) / 2)
	{
		while (pos_inf != 0)
		{
			rotate_b(pile_b);
			pos_inf--;
		}
	}
	else
	{
		while (pos_inf != pile_len(pile_b))
		{
			rev_rotate_b(pile_b);
			pos_inf++;
		}
	}
}

int	find_minimum(t_pile **pile)
{
	t_pile	*temp;
	int		min;

	temp = *pile;
	min = temp->nbr;
	while (temp)
	{
		if (min > temp->nbr)
			min = temp->nbr;
		temp = temp->next;
	}
	return (min);
}

int	find_maximum(t_pile **pile)
{
	t_pile	*temp;
	int		max;

	temp = *pile;
	max = temp->nbr;
	while (temp)
	{
		if (max < temp->nbr)
			max = temp->nbr;
		temp = temp->next;
	}
	return (max);
}
