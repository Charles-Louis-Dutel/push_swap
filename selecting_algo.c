/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selecting_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:37:43 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/05 15:50:01 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_pile_sorted(t_pile **pile)
{
	t_pile	*temp;
	int		max;

	temp = *pile;
	max = temp->nbr;
	temp = temp->next;
	while (temp)
	{
		if (max > temp->nbr)
			return (1);
		max = temp->nbr;
		temp = temp->next;
	}
	return (0);
}

void	choose_algo(t_pile **pile_a, t_pile **pile_b)
{
	int	len;

	if (is_pile_sorted(pile_a) == 1)
	{
		len = pile_len(pile_a);
		if (len < 100)
			sort_pile(pile_a, pile_b);
		else
			sort_with_chunk(pile_a, pile_b);
	}
	else
		return ;
}
