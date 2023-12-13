/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:21:14 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/13 13:26:50 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*get_last(t_pile **pile)
{
	t_pile	*temp;

	temp = *pile;
	if (!temp)
		return (NULL);
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

int	pile_len(t_pile **pile)
{
	t_pile	*temp;
	int		i;

	if (!pile)
		return (0);
	temp = *pile;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	print_pile(t_pile **pile)
{
	t_pile	*temp;

	if (!pile)
		return ;
	temp = *pile;
	while (temp)
	{
		printf("[%d]\n", temp->nbr);
		temp = temp->next;
	}
}
