/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:52:41 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/13 14:33:01 by cdutel           ###   ########.fr       */
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
