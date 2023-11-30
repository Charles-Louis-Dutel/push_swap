/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:56:59 by cdutel            #+#    #+#             */
/*   Updated: 2023/11/14 16:33:40 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	const char		*source;
	char			*destination;

	if (!dest && !src)
		return (NULL);
	source = (const char *)src;
	destination = (char *)dest;
	if (destination > source)
	{
		while (n > 0)
		{
			destination[n - 1] = source[n - 1];
			n--;
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			destination[i] = source[i];
	}
	return (dest);
}
/*
int	main(void)
{
	int i;
	//char originale[] = "bonjour";
	int data[] = { 20, 30, 40, 50, 60, 70, 80, 90, 100, 0 };

	for(i=0; i<10; i++)
		printf("%d ", data[i]);
	printf("\n");

	void *source = (void *) data;
	void *destination = (void *) (data+1);
	unsigned long size = sizeof(int *) * 10;
	//memmove (destination, source, size);
	ft_memmove (destination, source, size);

	for(i=0; i<10; i++)
		printf("%d ", data[i]);
	printf("\n");

	data[0] = 10;
	for(i=0; i<10; i++)
		printf("%d ", data[i]);
	printf("\n");

	return(0);
}*/
