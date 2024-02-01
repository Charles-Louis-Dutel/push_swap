/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:52:41 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/16 18:11:06 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_help(t_pile **pile_a, t_pile **pile_b, int m_a, int m_b)
{
	if (m_a < pile_len(pile_a) / 2 && m_b < pile_len(pile_b) / 2)
	{
		while (m_a > 0 && m_b > 0)
		{
			rotate(pile_a, pile_b);
			m_a--;
			m_b--;
		}
	}
	else if (m_a > pile_len(pile_a) / 2 && m_b > pile_len(pile_b) / 2)
	{
		while (m_a < pile_len(pile_a) && m_b < pile_len(pile_b))
		{
			rev_rotate(pile_a, pile_b);
			m_a++;
			m_b++;
		}
	}
	if (m_a > 0 && m_a <= pile_len(pile_a))
		sort_help_a(pile_a, m_a);
	if (m_b > 0 && m_b <= pile_len(pile_b))
		sort_help_b(pile_b, m_b);
}

void	sort_help_a(t_pile **pile_a, int pos_inf)
{
	if (pos_inf < pile_len(pile_a) / 2)
	{
		while (pos_inf != 0)
		{
			rotate_a(pile_a);
			pos_inf--;
		}
	}
	else
	{
		while (pos_inf != pile_len(pile_a))
		{
			rev_rotate_a(pile_a);
			pos_inf++;
		}
	}
}

void	sort_help_b(t_pile **pile_b, int pos_inf)
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
