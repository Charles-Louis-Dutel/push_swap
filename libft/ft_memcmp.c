/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:40:52 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/10 17:08:21 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char		*str1;
	unsigned const char		*str2;
	unsigned long			i;

	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char *c1 = "s-erre";
	char *c2 = "s-erre";
	int size = sizeof(char) * 150;

	//char s [] = {-128, 0, 127, 0};
	//char scpy [] = {-128, 0, 127, 0};
	//char s2[] = {0, 0, 127, 0};
	//char s3[] = {0, 0, 42, 0};
	//size_t size = sizeof( int ) * 4;
	__builtin_printf("%d\n", memcmp(c1, c2, size));
	__builtin_printf("%d\n", ft_memcmp(c1, c2, size));
	return(0);
}*/
