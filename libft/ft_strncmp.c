/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:20:58 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/10 18:01:17 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	long unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	if (n == 1)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main()
{
	__builtin_printf("%d\n", strncmp("", "", 1));
	__builtin_printf("%d\n", ft_strncmp("", "", 1));
	return 0;
}*/
