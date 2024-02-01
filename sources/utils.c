/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:21:14 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/20 09:39:43 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*set_pile(int argc, char **argv)
{
	t_pile	*temp;
	int		i;
	long	nb;

	temp = new_pile();
	i = argc - 1;
	while (i > 0)
	{
		nb = ft_atoi_modif(argv[i]);
		if (nb == 11111111111)
		{
			write(2, "Error\n", 6);
			clear_pile(&temp);
			return (new_pile());
		}
		push_pile(&temp, nb);
		i--;
	}
	if (check_doublons(temp) == 1)
	{
		write(2, "Error\n", 6);
		clear_pile(&temp);
		return (new_pile());
	}
	return (temp);
}

t_pile	*set_pile_2(int argc, char **argv)
{
	t_pile	*temp;
	int		i;
	long	nb;

	temp = new_pile();
	i = argc - 1;
	while (i >= 0)
	{
		nb = ft_atoi_modif(argv[i]);
		if (nb == 11111111111)
		{
			write(2, "Error\n", 6);
			clear_pile(&temp);
			return (new_pile());
		}
		push_pile(&temp, nb);
		i--;
	}
	if (check_doublons(temp) == 1)
	{
		write(2, "Error\n", 6);
		clear_pile(&temp);
		return (new_pile());
	}
	return (temp);
}

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
		ft_printf("[%d]\n", temp->nbr);
		temp = temp->next;
	}
}
