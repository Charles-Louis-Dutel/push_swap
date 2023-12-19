/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:34:53 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/19 14:34:50 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static t_pile	*set_pile(int argc, char **argv)
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

static void ft_le_xav(char **dest)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

static int	case_one_arg(const char *argv)
{
	char	**args;
	t_pile	*pile_a;
	t_pile	*pile_b;
	int		i;

	args = ft_split(argv, ' ');
	i = 0;
	while (args[i])
		i++;
	if (check_args(i, args) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	pile_a = new_pile();
	pile_a = set_pile(i, args);
	ft_le_xav(args);
	if (!pile_a)
		return (1);
	pile_b = new_pile();
	choose_algo(&pile_a, &pile_b);
	clear_pile(&pile_a);
	clear_pile(&pile_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc == 2)
		return (case_one_arg(argv[1]));
	else if (argc > 2)
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
		choose_algo(&pile_a, &pile_b);
		clear_pile(&pile_a);
		clear_pile(&pile_b);
	}
	return (0);
}
