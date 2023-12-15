/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selecting_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:37:43 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/14 23:30:00 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_pile_sorted(t_pile **pile)
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

// static int	how_many_missplaced(t_pile	**pile)
// {
// 	t_pile	*temp;
// 	int		missplaced;
// 	int		actuel;

// 	temp = *pile;
// 	actuel = temp->nbr;
// 	missplaced = 0;
// 	temp = temp->next;
// 	while (temp)
// 	{
// 		if (actuel > temp->nbr)
// 			missplaced++;
// 		actuel = temp->nbr;
// 		temp = temp->next;
// 	}
// 	return (missplaced);
// }

void	choose_algo(t_pile **pile_a, t_pile **pile_b)
{
	int	len;
	//int	missplaced;

	if (is_pile_sorted(pile_a) == 1)
	{
		//missplaced = how_many_missplaced(pile_a);
		//printf("%d\n", missplaced);
		len = pile_len(pile_a);
		if (len <= 3)
			pile_of_3(pile_a);
		else if (len <= 5)
			pile_of_5(pile_a, pile_b);
		else
			sort_pile(pile_a, pile_b);
	}
	else
		return ;
}
