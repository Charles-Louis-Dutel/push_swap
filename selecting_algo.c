/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selecting_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:37:43 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/12 21:48:42 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_algo(t_pile **pile_a, t_pile **pile_b)
{
	int	len;

	len = pile_len(pile_a);
	if (len <= 3)
		pile_of_3(pile_a);
	else
		sort_pile(pile_a, pile_b);
}
