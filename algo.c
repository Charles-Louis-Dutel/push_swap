/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:24:37 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/16 16:48:07 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index_b(t_pile **pile_b, int n_to_push)
{
	t_pile	*temp;
	int		proxy_pos;
	int		proxy;
	int		index;

	temp = *pile_b;
	if (n_to_push < find_minimum(pile_b))
		proxy_pos = find_min_pos(pile_b) + 1;
	else if (n_to_push > find_maximum(pile_b))
		proxy_pos = find_max_pos(pile_b);
	else
	{
		index = 0;
		proxy = find_maximum(pile_b);
		while (temp)
		{
			if (n_to_push < temp->nbr && proxy >= temp->nbr)
			{
				proxy = temp->nbr;
				proxy_pos = index + 1;
			}
			index++;
			temp = temp->next;
		}
	}
	return (proxy_pos);
}

void	sort_and_push(t_pile **pile_a, t_pile **pile_b, int cheap_index)
{
	t_pile	*temp;
	int		n_to_push;
	int		move_a;
	int		move_b;

	temp = *pile_a;
	move_a = cheap_index;
	while(cheap_index != 0)
	{
		temp = temp->next;
		cheap_index--;
	}
	n_to_push = temp->nbr;
	move_b = find_index_b(pile_b, n_to_push);
		//printf("*%d*\n", move_b);
	sort_help_a(pile_a, move_a);
		//print_pile(pile_a);
		//printf("\n");
	sort_help_b(pile_b, move_b);
		//print_pile(pile_b);
		//printf("\n");
	push_b(pile_a, pile_b);
}

static void	sort_b(t_pile **pile_b)
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
	int	cheap_index;
	//int	cheap_num;

	push_b(pile_a, pile_b);
	push_b(pile_a, pile_b);
		// printf("pile_a\n");
		// print_pile(pile_a);
		// printf("\n");
		// printf("pile_b\n");
		// print_pile(pile_b);
		// printf("\n");
	len = pile_len(pile_a);
	while (len)
	{
		cheap_index = find_cheapest(pile_a, pile_b);
		sort_and_push(pile_a, pile_b, cheap_index);
			// print_pile(pile_a);
			// printf("\n");
			// print_pile(pile_b);
			// printf("\n");
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
