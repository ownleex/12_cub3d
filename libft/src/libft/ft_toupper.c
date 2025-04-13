/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:57:55 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/01/18 05:10:03 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
int	main(void)
{
	char lower[] = "abcdefghijklmnopqrstuvwxyz";
	char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i;

	i = 0;
	printf("Before ft_toupper: %s\n", lower);
	while (lower[i])
	{
		lower[i] = ft_toupper(lower[i]);
		i++;
	}
	printf("After ft_toupper: %s\n", lower);

	i = 0;
	printf("Before ft_toupper: %s\n", upper);
	while (upper[i])
	{
		upper[i] = ft_toupper(upper[i]);
		 i++;
	}
	printf("After ft_toupper: %s\n", upper);

	char symbols[] = "12345!@#$%";
	i = 0;
	printf("Before ft_toupper: %s\n", symbols);
	while (symbols[i])
	{
		symbols[i] = ft_toupper(symbols[i]);
		i++;
	}
	printf("After ft_toupper: %s\n", symbols);
	return 0;
}
*/
