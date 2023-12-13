/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:34:53 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/12 18:45:22 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

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

// static void	test(t_pile **pile_a, t_pile **pile_b)
// {
// 	swap_a(pile_a);

// 	push_b(pile_a, pile_b);
// 	push_b(pile_a, pile_b);
// 	push_b(pile_a, pile_b);

// 	swap_a(pile_a);

// 	push_a(pile_b, pile_a);
// 	push_a(pile_b, pile_a);
// 	push_a(pile_b, pile_a);
// }

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc > 1)
	{
		if (check_args(argc, argv) == 1)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		pile_a = new_pile();
		pile_a = set_pile(argc, argv);
		if (!pile_a)
			return (1);
		pile_b = new_pile();
		print_pile(&pile_a);
		//test(&pile_a, &pile_b);
		choose_algo(&pile_a, &pile_b);
		__builtin_printf("\n");
		print_pile(&pile_a);

		clear_pile(&pile_a);
		clear_pile(&pile_b);
	}
	return (0);
}
