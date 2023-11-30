/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:34:53 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/30 15:59:58 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

t_pile	set_pile(int argc, char **argv)
{
	t_pile	temp;
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
			temp = clear_pile(temp);
			return (temp);
		}
		temp = push_pile(temp, nb);
		i--;
	}
	return (temp);
}

int	main(int argc, char **argv)
{
	t_pile	pile_a;

	if (argc > 1)
	{
		if (check_args(argc, argv) == 1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		//-Gérer les erreurs : paramètre qui ne sont pas de nombres,
		//si ils ne tiennent pas dans un int, si il y a des doublons : afficher "Error\n"
		pile_a = set_pile(argc, argv);
		if (!pile_a)
			return (1);
		print_pile(pile_a);
		pile_a = clear_pile(pile_a);
	}
	return (0);
}
